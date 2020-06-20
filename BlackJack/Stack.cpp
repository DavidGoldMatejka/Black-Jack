#include <iostream>
#include <vector>
#include <string>
#include "Stack.h"
#include "Card.h"
using namespace std;

Stack::Stack(std::vector<int> initialCards)
{
  for(int i = 0; i < initialCards.size(); i++)
  {
    Card newCard(initialCards[i]);
    cards.push_back(newCard);
  }
  
}


 void Stack::printMe()
 {
   for(auto i = cards.begin(); i != cards.end(); ++i)
    cout << *i << ", ";
  cout << endl;
  
 }

 int Stack::size()
 {
   return cards.size();
 }

 Card Stack::dealACard()
 {
   
   Card topCard = cards.front();
   cards.pop_front();
   return topCard;

 }

 void Stack::addACard(Card newCard)
 {
   cards.push_back(newCard);
 }

 int Stack::getPoints()
 {
   int total = 0;
    for(auto iter=cards.begin(); iter != cards.end(); ++iter) 
    {
           total = total + iter->value;
    }
    return total;

 }

 bool Stack::hasAnAce()
 {
   for(auto iter=cards.begin(); iter != cards.end(); ++iter) 
    {
           if(iter->name == "Ace")
            return true;
    }
    return false;
 }
