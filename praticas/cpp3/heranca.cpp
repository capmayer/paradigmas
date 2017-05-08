#include <string>
#include <iostream>
#include <vector>
#include <iterator>

class Person {
private:
   std::string name;
public:
   Person() {
      std::cout << "Construtor default de Person" << std::endl;
      name = "Culano";
   }
   std::string getName() {
      return name;
   }
   void setName(std::string name) {
      this->name = name;
   }
};

class Student : public Person {
   std::string course;
public:
   Student() {
      std::cout << "Construtor default de Student" << std::endl;
      course = "CC";
   }
   bool testName() {
     if (getName()[0] == 'F')
        return true;
     else
        return false;
    }
};

class PhdStudent : public Student {
  int ano;
  public:
    PhdStudent() {
      std::cout << "Construtor default PhdStudent" << std::endl;
    }
    PhdStudent(int ano) {
      this->ano = ano;
      std::cout << "Construtor default PhdStudent " << ano;
      std::cout << std::endl;
    }
};

int main() {
   Person p;
   Student s;
   PhdStudent ps(15);

   std::vector<Person*> v;
   v.push_back(&ps);
   v.push_back(&p);
   v.push_back(&s);
   std::vector<Person*>::iterator it;
   for (it = v.begin(); it != v.end(); it++)
      std::cout<< (*it)->getName() << " ";
   std::cout << std::endl;
}
