#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <ctime>

using namespace std;

class Biscoito {
  private:
    int size;
    int price;
  public:
    Biscoito(int size){
      this->size = size;
      if (size > 25){
        this->price = 6;
      } else if (size >= 9){
        this->price = 4;
      } else {
        this->price = 2;
      }
    }

    int getPrice() {
      return price;
    }

    int getSize(){
      return size;
    }
};

class Circular : public Biscoito {
  private:
    int r;
  public:
    Circular(int r) : Biscoito(3.14 * r * r){
      this->r = r;
    }

};

class Triangular : public Biscoito {
  private:
    int b;
    int h;
  public:
    Triangular(int b, int h) : Biscoito((b * h)/2){
      this->b = b;
      this->h = h;
    }

};

class Quadrangular : public Biscoito {
  private:
    int l;
    int b;
  public:
    Quadrangular(int b, int l) : Biscoito(b * l){
      this->b = b;
      this->l = l;
    }

};

void showBiscoitos(vector<Biscoito*>* bisc){
  std::sort(bisc->begin(), bisc->end(), [](Biscoito* b1, Biscoito* b2) -> bool{
    return b1->getSize() > b2->getSize();
   });
  cout << "Tamanho | Preço ";
  cout << endl;
  vector<Biscoito*>::iterator it;
  for (it = bisc->begin(); it != bisc->end(); it++){
    cout << (*it)->getSize() << " | " << (*it)->getPrice();
    cout << endl;
  }
}

void createBiscoitos(vector<Biscoito*>* bisc, int qb){
  for (int x=0; x < qb; x++){
    int type = rand() % 3; // define a random type
    int size1 = rand() % 7 + 1; // define a random size 1
    int size2 = rand() % 7 + 1; // define a random size 2
    if (type == 0) {
      Circular* c = new Circular(size1);
      bisc->push_back(c);
    }else if(type == 1){
      Triangular* t = new Triangular(size1, size2);
      bisc->push_back(t);
    }else if(type == 2){
      Quadrangular* q = new Quadrangular(size1, size2);
      bisc->push_back(q);
    }
  }
}

void showReward(vector<Biscoito*>* bisc){
  int p = 0, m = 0, g = 0, vp = 0, vm = 0, vg = 0;
  vector<Biscoito*>::iterator it;
  for (it = bisc->begin(); it != bisc->end(); it++){
    if ((*it)->getSize() > 25){
      g++;
      vg += (*it)->getPrice();
    }
    else if ((*it)->getSize() > 9){
      m++;
      vm += (*it)->getPrice();
    }
    else{
      p++;
      vp += (*it)->getPrice();
    }

  }
  cout << "Biscoitos pequenos: "<< p << " valor estimado: " << vp <<" \n";
  cout << "Biscoitos medios: "<< m << " valor estimado: " << vm <<" \n";
  cout << "Biscoitos grandes: "<< g << " valor estimado: " << vg <<" \n";
  cout << "Valor total estimado: "<< vp+vm+vg << " golpes "<< "\n";
  cout << endl;
}

int main(){
  int N;
  cout << "Numero de biscoitos: ";
  cin >> N;

  std::srand(std::time(0));

  vector<Biscoito*> biscoitos;

  createBiscoitos(&biscoitos, N);

  showBiscoitos(&biscoitos);

  showReward(&biscoitos);

  // random type and size
  // classification by size
  // show
  // show size and price by size
  // show total price

}
