#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


#include "Stack.h"
#include "Card.h"
#include "BlackJack.h"
#include "testMe.h"

int main() {
std::cout << "Entered main \n";
  //testMe();                                          // call the testMe() tests when ready (input will be redirected)
  srand(time(NULL));        
                          // set the random number seed based on current time  
  std::vector<int> cardIDs; 
                             // we'll fill this up with card ids zero to 51
  for(int i=0; i<52; i++)  cardIDs.push_back(i);       // here we are pushing integers which represent card IDS
  Stack temp(cardIDs);
  
  random_shuffle(cardIDs.begin(), cardIDs.end());      // user iterators to shuffle the vector of cardIDs
  std::cout << "About to initialize \n";
  BlackJack game({ "Player A", "Dealer" }, cardIDs);   // specify all 3 arguments; constructor should build full deck from provided ids
  std::cout << "\n main(): Game initialization succsesful";  
  game.play();                                         // play the game 
  return 0; 
}