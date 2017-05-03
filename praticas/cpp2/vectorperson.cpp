#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Person {
   string name;
   int age;
public:
   Person(string name, int age) {
      this->name = name;
      this->age = age;
   }
   string getName() {
      return name;
   }
   int getAge() {
      return age;
   }
   // operador '<' sobrecarregado (overload)
   // permite comparar Persons pela idade


};

// comparador de Persons pelo nome
bool cmpPersonName(Person& p1, Person& p2) {
   return p1.getName() < p2.getName();
}

bool cmpPersonAge(Person& p1, Person& p2) {
   return p1.getAge() < p2.getAge();
}

bool cmpBoth(Person& p1, Person& p2) {
  return cmpPersonName(p1, p2) && cmpPersonAge(p1, p2);
}

int main() {

   ifstream data("data.csv");

   string line;
   string cell[2];
   vector<Person> v;

   while (getline(data, line)) {
      stringstream linestream(line);
      getline(linestream, cell[0], ',');
      getline(linestream, cell[1], ',');
      v.push_back(Person(cell[0], stoi(cell[1])));
   }

   vector<Person>::iterator it;
   for (it = v.begin(); it != v.end(); it++)
      cout<< it->getName() << " ";
   cout << endl;


   // ordena com operador '<' definido na classe (por idade)

   // método sort usa '<' como default para ordenar
   sort(v.begin(), v.end(), cmpPersonName);


   for (it = v.begin(); it != v.end(); it++)
      cout<< it->getAge() << " ";
   cout << endl;


   // ordena com funcao cmpPerson definida fora da classe
   sort(v.begin(), v.end(), cmpBoth);


   for (it = v.begin(); it != v.end(); it++)
      cout<< it->getName() << " - " << it->getAge() << " // ";
   cout << endl;
}
