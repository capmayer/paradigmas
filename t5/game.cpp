#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Activity {
  string description;
  int score;
  public:
    Activity(string description, int score) {
      this->description = description;
      this->score = score;
    }

    int getScore() {
      return score;
    }

    string getDescription() {
      return description;
    }

    bool sameActivity(Activity& a) {
      return this->description == a.getDescription();
    }
};

class Player {
   string name;
   std::vector<Activity> acts;
public:
   Player(string name) {
      this->name = name;
   }
   string getName() {
      return name;
   }
   void addActivity(Activity act) {
      this->acts.push_back(act);
   }
   // operador '<' sobrecarregado (overload)
   // permite comparar Persons pela idade


};

bool isMember(string p, std::vector<Player> ps){
  bool isMember = false;
  vector<Player>::iterator it;
  for (it = ps.begin(); it != ps.end(); it++)
     if (it->getName() == p)
        isMember = true;
  return isMember;
}

int main() {
  std::vector<Player> players;

  ifstream data("scores.csv");

  string line;
  string cell[3];

  while (getline(data, line)) {
     stringstream linestream(line);
     getline(linestream, cell[0], ',');
     getline(linestream, cell[1], ',');
     getline(linestream, cell[2], ',');
     if (isMember(cell[0], players)) {
       cout<< "member";
    cout << endl;
     }
     else{
       cout<< "not member";
    cout << endl;
     }
  }

}
