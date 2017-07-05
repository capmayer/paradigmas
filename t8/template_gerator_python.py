import tkinter as tk
import tkinter.ttk as ttk

class Field(object):
    def __init__(self, idlabel, label):
        self.idlabel = idlabel
        self.label = label

class WebApplication(object):
    fiels = []
    def __init__(self, title=None, subtitle=None, fields=[]):
        self.title = title
        self.subtitle = subtitle
        self.fields = fields

    def add_field(self, field):
        self.fields.append(field)

    def del_field(self, field):
        self.fields.remove(field)


class Editor(tk.Frame):
    webApp = WebApplication()
    def __init__(self, master=None):
        super().__init__(master)
        master.geometry("400x600")
        self.pack()
        self.create_widgets()
        

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

    def add_field_cb(self):
        text = self.add_field_input.get()
        f = Field(text+"ID", text)
        self.webApp.add_field(f)
        self.fields_table.insert('','end', text=text)

    def del_field_cb(self):
        item = self.fields_table.focus()
        print(item)
        if item is not None:
            self.webApp.del_field(item)
            self.fields_table.delete(self.fields_table.focus())

    def gerate_template_cb(self):
        pass

    def load_cb(self):
        pass
    def save_cb(self):
        pass
        

root = tk.Tk()
main = Editor(master=root)
main.mainloop()
