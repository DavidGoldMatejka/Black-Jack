#include<iostream>
#include "Card.h"
#include "Stack.h"
#include "BlackJack.h"
using namespace std;

  void BlackJack :: play() {
    std::cout << "Let's Play BlackJack!" << std::endl;

    bool gameOver = false; // Bust means >21
    this->printInstructions(); // print instructions
    this->printBoard(); // print the board

    while( !gameOver ) { // keep playing as long as the game is not won by either player
    
      gameOver = this->takePlayerTurn(); // current player takes a turn

     
      

      //this->printBoard(); // print the board if that was a good move

      
     
      gameOver = this->takeDealerTurn(); // AI takes a turn

      //if (gameOver)
       //break;

    } // end while: game over

    // note below that the winning player is who we want, not the current player
    if (winningPlayerId!= -1)
      std::cout << "Congratulations: " << playerNames[winningPlayerId] << " has won the game!" << std::endl;
    else 
      std::cout << "Looks like the game was a tie" << std::endl;

    std::cout << "Goodbye!" << std::endl;

  } // end play()


void BlackJack::printInstructions()
{
  cout << "\n Welcome to Black Jack! The goal is to get as close to 21 as possible, without going over. \n";
}

void BlackJack::printBoard()
{
  cout << "\n Dealer's hand: ";
  dealerHand.printMe();
  cout << "\n Player's hand: ";
  playerHand.printMe();
}

bool BlackJack::takePlayerTurn()
{
  
  bool stand = false;
  char turn;
  while(stand != true)
  {
    cout << "\n Player's turn: Hit(h) or Stand(s)? \n";
    cin >> turn;
    if(turn == 'h')
    {
      cout << "Player hit";
      playerHand.addACard(deck.dealACard());
      printBoard();
       if(getPlayerPoints() > 21)
       {
         cout << "\n Bust! \n";
         winningPlayerId = 1;
         return true;
       }
    }
    else if (turn == 's')
    {
      cout << "Player Stands";
      printBoard();
      return true;
    }
    else
    {
      cout << "\n Invalid input, try again! \n";
      return false;
    }
  }
   
  return false;
}

bool BlackJack::takeDealerTurn()
  {
  bool stand = false;
  cout << "\n Dealers turn... \n";
  while(stand != true)
  {
    if(getDealerPoints() <= getPlayerPoints())
      {
        cout << "Dealer hits";
        dealerHand.addACard(deck.dealACard());
        printBoard();
        if(getDealerPoints() > 21)
        {
          cout << "\n Bust! \n";
          winningPlayerId = 0;
          return true;
        }
      }
    else
    {
      cout << "Dealer Stands";
      printBoard();
      stand = true;
      break;
    }

    if(getPlayerPoints() > getDealerPoints())
  {
    winningPlayerId = 0;
    return true;
  }
  else if(getPlayerPoints() == getDealerPoints())
  {
    winningPlayerId = -1;
    return true;
  }
  winningPlayerId = 1;
  return true;

  }
  cout << "\n takeDealerTurn(): false";
  
  return false;
  
}

   int BlackJack::getPlayerPoints()
   {
     return playerHand.Stack::getPoints();
    
   }

   int BlackJack::getDealerPoints()
   {
     return dealerHand.Stack::getPoints();
   }

   int BlackJack::getWinningPlayerId()
   {
     return winningPlayerId;
   }

   

  BlackJack::BlackJack(vector<string> _playerNames, vector <int> _cardID)
  {
    
    playerNames.push_back(_playerNames[0]);
    playerNames.push_back(_playerNames[1]);
    Stack temp(_cardID);
    deck = temp;
    

   
  
  }
