#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include "dice.hpp"

using namespace std;

class Player
{
    //fname
    //lname
    //uname
    //score
    //high score 
};

class Coins
{
  // Gold, silver, bronze, 
  map<string,int> coins {{"gold", 0}, {"silver", 0}, {"bronze", 0}};

  Coins(int goldVal, int silverVal, int bronzeVal)
  {}

  Coins(float ratio)
  {
    //silver = ratio;
    //bronze = ratio / 100;
  }
};

template <typename T> // T is a variable name
class Tokens
{
  T total;
  public:

  Tokens()
  {
    total = 
  }
};

class Game 
{
  vector<Player> players;
  vector<int> scores;
  int turn;

};

class KuckleBones : public Game, Tokens<int>
{
  Dice dice;
};

int main() 
{
  Die die(20, time(0));
  Dice dice(10, 6, time(0));
  for (int i = 0; i < 1000; i++) 
  {
    dice.roll();
    cout << dice << endl;
  }
  return 0;
}