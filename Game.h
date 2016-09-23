//
//  Game.hpp
//  TicTacToe
//
//  Created by Daniel Mora on 6/15/16.
//  Copyright © 2016 Daniel Mora. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Tic
{
private:
    
    string board[3][3];
    
public:
    
    Tic();
    void printBoard();
    bool player1Move(int position);
    bool player2Move(int position);
    void computerFirstMove();
    void computerContinue();
    bool player1Win();
    bool player2Win();
    bool computerWin();
    bool draw();
};

#endif /* Game_h */
