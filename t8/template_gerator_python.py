import tkinter as tk
import tkinter.ttk as ttk
from tkinter.filedialog import askopenfilename
import json

class Field(object):
    def __init__(self, idlabel, label):
        self.idlabel = idlabel
        self.label = label

    def get_field_html(self):
        html = """<div class='form-group'>
                    <label for='{0}' class='col-sm-2 control-label'>{1}</label>
                    <div class="col-sm-6">
                        <input type="text" class="form-control validate[required]" id="{0}" placeholder="{1}">
                    </div>
                  </div>
               """.format(self.idlabel, self.label)
        return html

class WebApplication(object):
    fiels = []
    def __init__(self, title=None, subtitle=None, fields=[]):
        self.title = title
        self.subtitle = subtitle
        self.fields = fields

    def add_field(self, field):
        self.fields.append(field)

    def del_field(self, field):
        self.fields = [x for x in self.fields if x.idlabel != field]

    def get_title_html(self):
        return "<title>"+self.title+"</title>"
    
    def get_subtitle_html(self):
        return "<h1>"+self.subtitle+"</h1>"

class Editor(tk.Frame):
    filename = None
    webApp = WebApplication()
    def __init__(self, master=None):
        super().__init__(master)
        master.geometry("400x600")
        self.pack()
        self.create_widgets()
        self.load_base_template()
        

    def create_widgets(self):
        self.info_label = tk.Label(self, text="Automare gerate HTML template:")
        self.info_label.pack()
        self.title_label = tk.Label(self, text="Title: ")
        self.title_label.pack()
        self.title_input = tk.Entry(self)
        self.title_input.pack()
        self.subtitle_label = tk.Label(self, text="Subtitle: ")
        self.subtitle_label.pack()
        self.subtitle_input = tk.Entry(self)
        self.subtitle_input.pack()
        self.fields_table = ttk.Treeview(self)
        self.fields_table.heading("#0", text='Label Name', anchor='w')
        self.fields_table.column("#0", anchor="w")
        self.fields_table.pack()
        self.add_field_label = tk.Label(self, text = "Field name:")
        self.add_field_label.pack()
        self.add_field_input = tk.Entry(self)
        self.add_field_input.pack()
        self.add_field_button = tk.Button(self, text="Adicionar field", command=self.add_field_cb)
        self.add_field_button.pack()
        self.del_field_button = tk.Button(self, text="Remover field", command=self.del_field_cb)
        self.del_field_button.pack()
        self.gerate_template_button = tk.Button(self, text="Gera Template", command=self.gerate_template_cb)
        self.gerate_template_button.pack()
        self.load_button = tk.Button(self, text="Load configs", command=self.load_cb)
        self.load_button.pack()
        self.save_button = tk.Button(self, text="Save configs", command=self.save_cb)
        self.save_button.pack()


    def load_base_template(self):
        with open('base_template.html') as f:
            self.base_template = [l for l in iter(f.readline, '')]

    def add_text_clean(self, widget, text):
        widget.delete(0,'end')
        widget.insert(0, text)

    def add_field_base(self, text, textId):
        f = Field(textId, text)
        self.webApp.add_field(f)
        self.fields_table.insert('','end', iid=textId, text=text)
        
    #callback region
    def add_field_cb(self):
        text = self.add_field_input.get()
        if text is not '':
            self.add_field_base(text, text+"Id")
            self.add_field_input.delete(0, 'end')

    def del_field_cb(self):
        item = self.fields_table.focus()
        if item is not None:
            self.webApp.del_field(item)
            self.fields_table.delete(item)

    def gerate_template_cb(self):
        pass

    def load_cb(self):
        self.filename = askopenfilename()
        with open(self.filename) as f:
            data = json.load(f)
        self.add_text_clean(self.title_input, data['title'])
        self.add_text_clean(self.subtitle_input, data['subtitle'])
        [self.add_field_base(field['label'], field['id']) for field in data['fields']]
    
    def save_cb(self):
        self.filename = askopenfilename()
        data = {}
        data['title'] = self.title_input.get()
        data['subtitle'] = self.subtitle_input.get()
        data['fields'] = [{'label': f.label, 'id': f.idlabel} for f in self.webApp.fields]
        with open(self.filename, 'w') as f:
            json.dump(data, f)
            
        

root = tk.Tk()
main = Editor(master=root)
main.mainloop()
