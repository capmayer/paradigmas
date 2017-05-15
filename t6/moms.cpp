#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Biscoito {
  private:
    int size;
    int price;
  public:
    Biscoito(int size){
      this->size = size;
      if (size > 50){
        this->price = 10;
      } else if (size > 25){
        this->price = 5;
      } else {
        this->price = 2;
      }
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

int main(){
  // get the N
  // random type and size
  // classification by size
  // show
  // show size and price by size
  // show total price
  Circular* o = new Circular(5);
  cout<< o->getSize();
  cout << endl;
}
