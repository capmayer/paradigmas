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
   vector<Activity*> acts;
public:
   Player(string name) {
      this->name = name;
   }
   string getName() {
      return name;
   }
   vector<Activity*> getActs() {
     return acts;
   }
   void addActivity(Activity* act) {
      acts.push_back(act);
   }
   bool isActivityRegistered(string a) {
     vector<Activity*>::iterator it;
     for (it = acts.begin(); it != acts.end(); it++){
        if ((*it)->getDescription() == a)
           return true;
     }
     return false;
   }
   int getScore(){
     int score = 0;
     vector<Activity*>::iterator it;
     for (it = acts.begin(); it != acts.end(); it++){
        score += (*it)->getScore();
     }
     return score;
   }
};

// find if a player already in the list by name
Player* findPlayerInList(string p, std::vector<Player*>* ps){
  // try to find a player in players list and return it
  vector<Player*>::iterator it;
  for (it = ps->begin(); it != ps->end(); it++){
     if ((*it)->getName() == p)
        return *it;
  }
  return nullptr;
}

// load the csv
void loadCSV(std::vector<Player*>* players){
    ifstream data("scores.csv");

    string line;
    string cell[3];

    while (getline(data, line)) {
       stringstream linestream(line);
       getline(linestream, cell[0], ',');
       getline(linestream, cell[1], ',');
       getline(linestream, cell[2], ',');

       Player* p = findPlayerInList(cell[0], players);
       if (p != nullptr){
         if (!p->isActivityRegistered(cell[1])){
           Activity* na = new Activity (cell[1], std::stoi(cell[2]));
           p->addActivity(na);
         }
       }
       else{
          Player* np = new Player(cell[0]);
          Activity* na = new Activity(cell[1], stoi(cell[2]));
          np->addActivity(na);
          players->push_back(np);
       }
    }
}

void showScores(vector<Activity*>* acts){
  std::sort(acts->begin(), acts->end(), [](Activity* a1, Activity* a2) -> bool{
    return a1->getScore() > a2->getScore();
   });

   cout<< "| Activities by Score |";
   cout << endl;

  vector<Activity*>::iterator it;
  for (it = acts->begin(); it != acts->end(); it++){
    cout<< "| " << (*it)->getDescription() << " - " << (*it)->getScore() << " |";
    cout << endl;
  }
}

vector<Activity*> getAllActivities(std::vector<Player*>* players){
  vector<Activity*> activities;

  vector<Player*>::iterator it;
  for (it = players->begin(); it != players->end(); it++){
    vector<Activity*> acts = (*it)->getActs();

    vector<Activity*>::iterator it1;
    for (it1 = acts.begin(); it1 != acts.end(); it1++){
      activities.push_back(*it1);
    }
  }
  return activities;
}

void showScoresByAZ(std::vector<Player*>* ps){
  std::sort(ps->begin(), ps->end(), [](Player* p1, Player* p2) -> bool{
    return p1->getName() < p2->getName();
   });

   cout<< "| By A-Z |";
   cout << endl;

  vector<Player*>::iterator it;
  for (it = ps->begin(); it != ps->end(); it++){
    cout<< "| " << (*it)->getName() << " - " << (*it)->getScore() << " |";
    cout << endl;
  }
}

void showScoresByPts(std::vector<Player*>* ps){
  std::sort(ps->begin(), ps->end(), [](Player* p1, Player* p2) -> bool{
    return p1->getScore() < p2->getScore();
   });

   cout<< "| By Points |";
   cout << endl;

  vector<Player*>::iterator it;
  for (it = ps->begin(); it != ps->end(); it++){
    cout<< "| " << (*it)->getName() << " - " << (*it)->getScore() << " |";
    cout << endl;
  }
}

int main() {
  vector<Player*> players;

  loadCSV(&players);

  vector<Activity*> acts = getAllActivities(&players);

  showScores(&acts);

  showScoresByAZ(&players);

  showScoresByPts(&players);

}
