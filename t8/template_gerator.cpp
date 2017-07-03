#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Table.H>

using namespace std;

class GenericField {
  private:
    string id;
    string label;
  public:
    GenericField(string id, string label) {
       this->id = id;
       this->label = label;
    };
    string getId(){
      return this->id;
    }
    void setLabel(string label){
      this->label = label;
    }
    string getLabel(){
      return this->label;
    }
};

class WebApplication {
  private:
    string title;  // >>>1<<<
    string subtitle; // >>>2<<<
     //>>>3<<<
    // >>>4<<< just text with the fields
    // >>>5<<< just the js table gerator
    // >>>6<<< the js for editing
    // >>>7<<< the js for create a new entry
  public:
    vector<GenericField*> fields;
    WebApplication (string title, string subtitle){
      this->title = title;
      this->subtitle = subtitle;
    };
    WebApplication (string title){
      this->title = title;
    };
    void setTitle(string title){
      this->title = title;
    }
    string getTitle(){
      return this->title;
    }
    void setSubTitle(string subtitle){
      this->subtitle = subtitle;
    }
    string getSubTitle(){
      return this->subtitle;
    }
    void setField(string labelName){
      GenericField* newField = new GenericField(labelName+"Id", labelName);
      fields.push_back(newField);
    }

};


void gerateTemplate(WebApplication* wa){
  string tableConfigJS;
  string tableJS;
  string editJS;
  string createJS;
  cout << "called";
}

class Editor {
  private:
      Fl_Window* window;
      Fl_Button* bt_gerateTemplate;
      Fl_Button* bt_saveTemplate;
      Fl_Button* bt_loadTemplate;
      Fl_Input* in_title;
      Fl_Input* in_subtitle;
      Fl_Input* in_file;
      Fl_Input* in_field;
      Fl_Button* bt_newField;
      Fl_Button* bt_delField;
      Fl_Table* tb_fields;

      WebApplication* wa;

      vector<string> html;

      static void gerateTemplate_cb(Fl_Widget* w, void* userdata)
      {
          Editor* edit = static_cast<Editor*>(userdata);
          edit->wa = new WebApplication(edit->in_title->value(), edit->in_subtitle->value());
          edit->wa->setField("nome");
          edit->wa->setField("idade");
          edit->gerateTemplate();
      }
      static void load_cb(Fl_Widget* w, void* userdata)
      {
          Editor* edit = static_cast<Editor*>(userdata);
          edit->loadCSV(edit, edit->in_file->value());
      }

      static void newField_cb(Fl_Widget* w, void* userdata)
      {
        Editor* edit = static_cast<Editor*>(userdata);
        //edit->tb_fields->add(new Fl_Input(1,1,50,50,edit->in_field->value()));
        //cout << "t";
      }

      static void delField_cb(Fl_Widget* w, void* userdata)
      {
        Editor* edit = static_cast<Editor*>(userdata);

      }


      // Load the data
      void loadCSV(Editor* edit, string file){
          ifstream loadingConfigs;

          loadingConfigs.open(file + ".csv");

          string line;

          string cells[2];

          if (loadingConfigs.is_open())
          {
            while (getline(loadingConfigs, line))
            {
              stringstream linestream(line);
              getline(linestream, cells[0], ':');
              getline(linestream, cells[1], ':');
              if(cells[0].compare("TITLE")){
                wa = new WebApplication(cells[1]);
                //edit->in_title->value(cells[1]);
              }
              if(cells[0].compare("SUBTITLE")){
                wa->setSubTitle(cells[1]);
                //edit->in_subtitle->value(cells[1]);
              }
            }
            loadingConfigs.close();
          }
      }

      // Save the data;
      void saveCSV(string file){
          ofstream savingConfigs;

          savingConfigs.open(file + ".csv", fstream::out);

          vector<string>::iterator it;
          if (savingConfigs.is_open())
          {
            savingConfigs << "TITLE : "<< wa->getTitle() << '\n';
            savingConfigs << "SUBTITLE : "<< wa->getSubTitle() << '\n';
            savingConfigs.close();
          }
      }

      void gerateField(GenericField* field, vector<string>* html){
         html->push_back("<div class='form-group'>");
         html->push_back("<label for='"+field->getId()+"' class='col-sm-2 control-label'>"+field->getLabel()+"</label>");
         html->push_back("<div class='col-sm-6'>");
         html->push_back("<input type='text' class='form-control validate[required]' id='"+field->getId()+"' placeholder='"+field->getLabel()+"'>");
         html->push_back("</div></div>");
      }

      void gerateTemplate(){
        ifstream baseTemplate;

        baseTemplate.open("base_template.html");

        cout << "abriu";

        string line;

        if (baseTemplate.is_open())
        {
          vector<GenericField*>::iterator it;
          while (getline(baseTemplate, line))
          {
            if(line.compare(">>>1<<<") == 0){
              html.push_back("<title>" + wa->getTitle() + "</title>");
            }else if (line.compare(">>>2<<<") == 0){
              html.push_back("<h1>" + wa->getSubTitle() + "</h1>");
            }else if (line.compare(">>>3<<<") == 0){
              for (it = wa->fields.begin(); it != wa->fields.end(); it++){
                  gerateField(*it, &html);
              }
            }else if (line.compare(">>>4<<<") == 0){
              string thisLine = "dataSet[seq]=[index, icons";
              for (it = wa->fields.begin(); it != wa->fields.end(); it++){
                  thisLine += ", object."+ (*it)->getId();
              }
              thisLine += "];";
              html.push_back(thisLine);
            }else if (line.compare(">>>5<<<") == 0){
              string thisLine = "oTable=$('#table').dataTable({'data': dataSet,'columns': [ { 'title': 'Seq', 'class': 'center' }, { 'title': '', 'class': 'center' }";
              for (it = wa->fields.begin(); it != wa->fields.end(); it++){
                  thisLine += ", {'title':'"+ (*it)->getLabel() + "'}";
              }
              thisLine += "]});";
              html.push_back(thisLine);
            }else if (line.compare(">>>6<<<") == 0){
              string thisLine = "$('#table tbody').on( 'click', '.glyphicon-edit', function () {$('#list').hide();var rows = $(this).parents('tr').children();$('#seq').text(rows[0].innerHTML);";
              int ind = 2;
              for (it = wa->fields.begin(); it != wa->fields.end(); it++){
                  thisLine += "$('#"+ (*it)->getId() + "').val(rows["+ to_string(ind) +"].innerHTML);";
                  ind++;
              }
              thisLine += "$('#formID').show();} );";
              html.push_back(thisLine);
            }else if (line.compare(">>>7<<<") == 0){
              string thisLine = "function save() {var seq=$('#seq').text(); if ( isNaN(seq) ) { seq=0; } var key=formId+'_'+seq; var object={";
              for (it = wa->fields.begin(); it != wa->fields.end(); it++){
                  thisLine += "'"+ (*it)->getId() + "' :$('#"+(*it)->getId()+"').val(),";
              }
              thisLine += "} \nlocalStorage.setItem(key, JSON.stringify(object));}";
              html.push_back(thisLine);
            }else{
              html.push_back(line);
            }
          }
        }
        baseTemplate.close();

        ofstream newTemplate;

        newTemplate.open("newTemplate.html", fstream::out);

        vector<string>::iterator it;
        if (newTemplate.is_open())
        {
          for (it = html.begin(); it != html.end(); it++)
              newTemplate << *it << '\n';

          newTemplate.close();
        }
      }

  public:
    Editor(){
        window = new Fl_Window(800,700);
        window->begin();

        bt_gerateTemplate = new Fl_Button(590,640,100,50, "Gerar");
        bt_saveTemplate = new Fl_Button(480,640,100,50, "Save");
        bt_loadTemplate = new Fl_Button(370,640,100,50, "Load");

        bt_newField = new Fl_Button(290,520,145,50, "Criar");
        bt_delField = new Fl_Button(445,520,145,50, "Deletar");

        in_file = new Fl_Input(110, 640, 250,50, "Arquivo: ");
        in_file->value("configs");

        in_title = new Fl_Input(290, 10, 300, 50, "Titlo da aplicação:");
        in_subtitle = new Fl_Input(290, 70, 300, 50, "Subtitlo da aplicação:");

        in_field = new Fl_Input(290, 460, 300 , 50, "Nome do campo:");

        tb_fields = new Fl_Table(290, 150, 300, 300, "Campos");
        //tb_fields->cols(2);

        window->end();

        bt_gerateTemplate->callback(gerateTemplate_cb, (void*)(this));
        bt_loadTemplate->callback(load_cb, (void*)(this));
        bt_newField->callback(newField_cb, (void*)(this));
        bt_delField->callback(delField_cb, (void*)(this));

    };
    void show(){
      window->show();
    }
};


int main(int argc, char **argv){
  Editor editor;


  editor.show();
  return Fl::run();
}
