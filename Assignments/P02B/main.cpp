#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class Dice;

class Die {

  int sides;
  int seed;
  int lastRoll;

public:
  Die() {

    this->sides = 6;
    this->seed = time(0);
    srand(seed);
    lastRoll = 0;
  }
  Die(int sides, int seed) {
    this->sides = sides;
    this->seed = seed;

    srand(seed);
    lastRoll = 0;
  }

  int roll() {
    lastRoll = rand() % sides + 1;
    return lastRoll;
  }

  int getLastRoll() { return lastRoll; }
  friend Dice;
};

class Dice {
  int numOfDie;
  int sides;
  int seed;
  vector<Die> dice;

public:
  Dice() {
    this->numOfDie = 1;
    this->sides = 6;
    this->seed = time(0);
    dice.push_back(Die(sides, seed));
  }
  Dice(int num, int sides, int seed) {
    this->sides = sides;
    this->numOfDie = num;
    this->seed = seed;
    for (int i = 0; i < numOfDie; i++) {
      dice.push_back(Die(sides, seed));
    }
  }
  void roll() {
    for (int i = 0; i < dice.size(); i++) {
      dice[i].roll();
    }
  }
  friend ostream &operator<<(ostream &os, const Dice &d) {
    os << "[";
    for (int i = 0; i < d.numOfDie; i++) {
      os << "[" << d.dice[i].lastRoll << "]";
    }
    os << "]\n";
    return os;
  }
  int getNumDie() { return numOfDie; }
};

class Player
{
    //fname
    //lname
    //uname
    //score
    //high score 
};

int main() {
  Die die(20, time(0));
  Dice dice(10, 6, time(0));
  for (int i = 0; i < 1000;i++) {
    dice.roll();
    cout << dice << endl;
  }
  return 0;
}