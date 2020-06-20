#pragma once
#include <list>
#include "Card.h"
#include <vector>

class Stack {
  std::list<Card> cards;  // list container - no brackets avaialble!  []; so you must use iterators!
  
  public:             
    Stack(std::vector<int> initialCards = {}); // constructor: converts requested vector of card IDs into Card instances; defaults to empty stack
    void printMe (); // print out the stack from “top to bottom”
    int size (); // return int of how many cards in the stack
    Card dealACard();      // “deal” a card from the top: remove it and return a copy of it
    void addACard(Card newCard);  // add a new card to the top of a stack
    int getPoints();   // return an integer value that represents the sum of all card values in this stack
    bool hasAnAce(); // BONUS: return true if the stack currently contains any Ace card
};