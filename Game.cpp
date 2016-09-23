//
//  board.cpp
//  TicTacToe
//
//  Created by Daniel Mora on 6/15/16.
//  Copyright © 2016 Daniel Mora. All rights reserved.
//

#include "Game.h"

Tic::Tic() /*************************************** Constructor ***********************************************/
{
    board[0][0] = "1";
    board[0][1] = "2";
    board[0][2] = "3";
    board[1][0] = "4";
    board[1][1] = "5";
    board[1][2] = "6";
    board[2][0] = "7";
    board[2][1] = "8";
    board[2][2] = "9";
}

void Tic::printBoard() /********************************** Print board *******************************************/
{
    cout << " -------------" << endl;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " | " << board[i][j];
        }
        
        cout << " | " << endl;
        cout << " -------------" << endl;
    }
}

void Tic::computerFirstMove() /****************************** Computer first move *********************************/
{
    srand(time(0));
    
    int a = rand() % 3;
    int b = rand() % 3;
    bool flag = false;
    
    while (flag == false)
    {
        if (board[a][b] != "X" && board[a][b] != "O")
        {
            cout << "Computer chooses: " << board[a][b] << endl;
            
            board[a][b] = "O";
            
            flag = true;
        }
        
        a = rand() % 3;
        b = rand() % 3;
    }
}

bool Tic::player1Move(int position) /*********************** Player 1 *************************************/
{
    if (position == 1)
    {
        if (board[0][0] != "X" && board[0][0] != "O")
        {
            board[0][0] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 2)
    {
        if (board[0][1] != "X" && board[0][1] != "O")
        {
            board[0][1] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 3)
    {
        if (board[0][2] != "X" && board[0][2] != "O")
        {
            board[0][2] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 4)
    {
        if (board[1][0] != "X" && board[1][0] != "O")
        {
            board[1][0] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 5)
    {
        if (board[1][1] != "X" && board[1][1] != "O")
        {
            board[1][1] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 6)
    {
        if (board[1][2] != "X" && board[1][2] != "O")
        {
            board[1][2] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 7)
    {
        if (board[2][0] != "X" && board[2][0] != "O")
        {
            board[2][0] = "X";
            return true;
        }
        else
            return false;
    }
    else if (position == 8)
    {
        if (board[2][1] != "X" && board[2][1] != "O")
        {
            board[2][1] = "X";
            return true;
        }
        else 
            return false;
    }
    else if (position == 9)
    {
        if (board[2][2] != "X" && board[2][2] != "O")
        {
            board[2][2] = "X";
            return true;
        }
        else 
            return false;
    }
    else 
        return false;
}

bool Tic::player2Move(int position) /********************** Player 2 move *****************************/
{
    if (position == 1)
    {
        if (board[0][0] != "X" && board[0][0] != "O")
        {
            board[0][0] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 2)
    {
        if (board[0][1] != "X" && board[0][1] != "O")
        {
            board[0][1] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 3)
    {
        if (board[0][2] != "X" && board[0][2] != "O")
        {
            board[0][2] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 4)
    {
        if (board[1][0] != "X" && board[1][0] != "O")
        {
            board[1][0] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 5)
    {
        if (board[1][1] != "X" && board[1][1] != "O")
        {
            board[1][1] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 6)
    {
        if (board[1][2] != "X" && board[1][2] != "O")
        {
            board[1][2] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 7)
    {
        if (board[2][0] != "X" && board[2][0] != "O")
        {
            board[2][0] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 8)
    {
        if (board[2][1] != "X" && board[2][1] != "O")
        {
            board[2][1] = "O";
            return true;
        }
        else
            return false;
    }
    else if (position == 9)
    {
        if (board[2][2] != "X" && board[2][2] != "O")
        {
            board[2][2] = "O";
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void Tic::computerContinue() /***************************** Computer continues *******************************/
{
    if (board[0][0] == "X" && board[0][0] != "O") // Top row, defending
    {
        if (board[0][1] == "X" && board[0][1] != "O")
        {
            if (board[0][2] != "X" && board[0][2] != "O")
            {
                cout << "Computer chooses: " + board[0][2] << endl;
                board[0][2] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "X" && board[0][2] != "O")
    {
        if (board[0][1] == "X" && board[0][1] != "O")
        {
            if (board[0][0] != "X" && board[0][0] != "O")
            {
                cout << "Computer chooses: " + board[0][0] << endl;
                board[0][0] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "X" && board[0][0] != "O")
    {
        if (board[0][2] == "X" && board[0][2] != "O")
        {
            if (board[0][1] != "X" && board[0][1] != "O")
            {
                cout << "Computer chooses: " + board[0][1] << endl;
                board[0][1] = "O";
                return;
            }
        }
    }
    if (board[1][0] == "X" && board[1][0] != "O") // Middle row, defending
    {
        if (board[1][1] == "X" && board[1][0] != "O")
        {
            if (board[1][2] != "X" && board[1][2] != "O")
            {
                cout << "Computer chooses: " + board[1][2] << endl;
                board[1][2] = "O";
                return;
            }
        }
    }
    if (board[1][2] == "X" && board[1][2] != "O")
    {
        if (board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[1][0] != "X" && board[1][0] != "O")
            {
                cout << "Computer chooses: " + board[1][0] << endl;
                board[1][0] = "O";
                return;
            }
        }
    }
    if (board[1][0] == "X" && board[1][0] != "O")
    {
        if (board[1][2] == "X" && board[1][2] != "O")
        {
            if (board[1][1] != "X" && board[1][1] != "O")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][0] == "X" && board[2][0] != "O") //Bottom row, defending
    {
        if (board[2][1] == "X" && board[2][1] != "O")
        {
            if (board[2][2] != "X" && board[2][2] != "O")
            {
                cout << "Computer chooses: " + board[2][2] << endl;
                board[2][2] = "O";
                return;
            }
        }
    }
    if (board[2][2] == "X" && board[2][2] != "O")
    {
        if (board[2][1] == "X" && board[2][1] != "O")
        {
            if (board[2][0] != "X" && board[2][0] != "O")
            {
                cout << "Computer chooses: " + board[2][0] << endl;
                board[2][0] = "O";
                return;
            }
        }
    }
    if (board[2][0] == "X" && board[2][0] != "O")
    {
        if (board[2][2] == "X" && board[2][2] != "O")
        {
            if (board[2][1] != "X" && board[2][1] != "O")
            {
                cout << "Computer chooses: " + board[2][1] << endl;
                board[2][1] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "X" && board[0][0] != "O") //Left column
    {
        if (board[1][0] == "X" && board[1][0] != "O")
        {
            if (board[2][0] != "X" && board[2][0] != "O")
            {
                cout << "Computer chooses: " + board[2][0] << endl;
                board[2][0] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "X" && board[0][0] != "O")
    {
        if (board[2][0] == "X" && board[2][0] != "O")
        {
            if (board[1][0] != "X" && board[1][0] != "O")
            {
                cout << "Computer chooses: " + board[1][0] << endl;
                board[1][0] = "O";
                return;
            }
        }
    }
    if (board[1][0] == "X" && board[1][0] != "O")
    {
        if (board[2][0] == "X" && board[2][0] != "O")
        {
            if (board[0][0] != "X" && board[0][0] != "O")
            {
                cout << "Computer chooses: " + board[0][0] << endl;
                board[0][0] = "O";
                return;
            }
        }
    }
    if (board[0][1] == "X" && board[0][1] != "O") //Middle column
    {
        if (board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[2][1] != "X" && board[2][1] != "O")
            {
                cout << "Computer chooses: " + board[2][1] << endl;
                board[2][1] = "O";
                return;
            }
        }
    }
    if (board[2][1] == "X" && board[2][1] != "O")
    {
        if (board[0][1] == "X" && board[0][1] != "O")
        {
            if (board[1][1] != "X" && board[1][1] != "O")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][1] == "X" && board[2][1] != "O")
    {
        if (board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[0][1] != "X" && board[0][1] != "O")
            {
                cout << "Computer chooses: " + board[0][1] << endl;
                board[0][1] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "X" && board[0][2] != "O") //Right column
    {
        if (board[1][2] == "X" && board[1][2] != "O")
        {
            if (board[2][2] != "X" && board[2][2] != "O")
            {
                cout << "Computer chooses: " + board[2][2] << endl;
                board[2][2] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "X" && board[0][2] != "O")
    {
        if (board[2][2] == "X" && board[2][2] != "O")
        {
            if (board[1][2] != "X" && board[1][2] != "O")
            {
                cout << "Computer chooses: " + board[1][2] << endl;
                board[1][2] = "O";
                return;
            }
        }
    }
    if (board[2][2] == "X" && board[2][2] != "O")
    {
        if (board[1][2] == "X" && board[1][2] != "O")
        {
            if (board[0][2] != "X" && board[0][2] != "O")
            {
                cout << "Computer chooses: " + board[0][2] << endl;
                board[0][2] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "X" && board[0][0] != "O") //Down diagonal
    {
        if(board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[2][2] != "X" && board[2][2] != "O")
            {
                cout << "Computer chooses: " + board[2][2] << endl;
                board[2][2] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "X" && board[0][0] != "O")
    {
        if (board[2][2] == "X" && board[2][2] != "O")
        {
            if (board[1][1] != "X" && board[1][1] != "O")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][2] == "X" && board[2][2] != "O")
    {
        if (board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[0][0] != "X" && board[0][0] != "O")
            {
                cout << "Computer chooses: " + board[0][0] << endl;
                board[0][0] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "X" && board[0][2] != "O") //Up diagonal
    {
        if (board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[2][0] != "X" && board[2][0] != "O")
            {
                cout << "Computer chooses: " + board[2][0] << endl;
                board[2][0] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "X" && board[0][2] != "O")
    {
        if (board[2][0] == "X" && board[2][0] != "O")
        {
            if (board[1][1] != "X" && board[1][1] != "O")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][0] == "X" && board[2][0] != "O")
    {
        if (board[1][1] == "X" && board[1][1] != "O")
        {
            if (board[0][2] != "X" && board[0][2] != "O")
            {
                cout << "Computer chooses: " + board[0][2] << endl;
                board[0][2] = "O";
                return;
            }
        }
    }
    
    // Computer
    if (board[0][0] == "O" && board[0][0] != "X") // Top row
    {
        if (board[0][1] == "O" && board[0][1] != "X")
        {
            if (board[0][2] != "O" && board[0][2] != "X")
            {
                cout << "Computer chooses: " + board[0][2] << endl;
                board[0][2] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "O" && board[0][2] != "X")
    {
        if (board[0][1] == "O" && board[0][1] != "X")
        {
            if (board[0][0] != "O" && board[0][0] != "X")
            {
                cout << "Computer chooses: " + board[0][0] << endl;
                board[0][0] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "O" && board[0][0] != "X")
    {
        if (board[0][2] == "O" && board[0][2] != "X")
        {
            if (board[0][1] != "O" && board[0][1] != "X")
            {
                cout << "Computer chooses: " + board[0][1] << endl;
                board[0][1] = "O";
                return;
            }
        }
    }
    if (board[1][0] == "O" && board[1][0] != "X") // Middle row
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[1][2] != "O" && board[1][2] != "X")
            {
                cout << "Computer chooses: " + board[1][2] << endl;
                board[1][2] = "O";
                return;
            }
        }
    }
    if (board[1][2] == "O" && board[1][2] != "X")
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[1][0] != "O" && board[1][0] != "X")
            {
                cout << "Computer chooses: " + board[1][0] << endl;
                board[1][0] = "O";
                return;
            }
        }
    }
    if (board[1][0] == "O" && board[1][0] != "X")
    {
        if (board[1][2] == "O" && board[1][2] != "X")
        {
            if (board[1][1] != "O" && board[1][1] != "X")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][0] == "O" && board[2][0] != "X") //Bottom row
    {
        if (board[2][1] == "O" && board[2][1] != "X")
        {
            if (board[2][2] != "O" && board[2][2] != "X")
            {
                cout << "Computer chooses: " + board[2][2] << endl;
                board[2][2] = "O";
                return;
            }
        }
    }
    if (board[2][2] == "O" && board[2][2] != "X")
    {
        if (board[2][1] == "O" && board[2][1] != "X")
        {
            if (board[2][0] != "O" && board[2][0] != "X")
            {
                cout << "Computer chooses: " + board[2][0] << endl;
                board[2][0] = "O";
                return;
            }
        }
    }
    if (board[2][0] == "O" && board[2][0] != "X")
    {
        if (board[2][2] == "O" && board[2][2] != "X")
        {
            if (board[2][1] != "O" && board[2][1] != "X")
            {
                cout << "Computer chooses: " + board[2][1] << endl;
                board[2][1] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "O" && board[0][0] != "X") //Left column
    {
        if (board[1][0] == "O" && board[1][0] != "X")
        {
            if (board[2][0] != "O" && board[2][0] != "X")
            {
                cout << "Computer chooses: " + board[2][0] << endl;
                board[2][0] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "O" && board[0][0] != "X")
    {
        if (board[2][0] == "O" && board[2][0] != "X")
        {
            if (board[1][0] != "O" && board[1][0] != "X")
            {
                cout << "Computer chooses: " + board[1][0] << endl;
                board[1][0] = "O";
                return;
            }
        }
    }
    if (board[1][0] == "O" && board[1][0] != "X")
    {
        if (board[2][0] == "O" && board[2][0] != "X")
        {
            if (board[0][0] != "O" && board[0][0] != "X")
            {
                cout << "Computer chooses: " + board[0][0] << endl;
                board[0][0] = "O";
                return;
            }
        }
    }
    if (board[0][1] == "O" && board[0][1] != "X") //Middle column
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[2][1] != "O" && board[2][1] != "X")
            {
                cout << "Computer chooses: " + board[2][1] << endl;
                board[2][1] = "O";
                return;
            }
        }
    }
    if (board[2][1] == "O" && board[2][1] != "X")
    {
        if (board[0][1] == "O" && board[0][1] != "X")
        {
            if (board[1][1] != "O" && board[1][1] != "X")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][1] == "O" && board[2][1] != "X")
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[0][1] != "O" && board[0][1] != "X")
            {
                cout << "Computer chooses: " + board[0][1] << endl;
                board[0][1] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "O" && board[0][2] != "X") //Right column
    {
        if (board[1][2] == "O" && board[1][2] != "X")
        {
            if (board[2][2] != "O" && board[2][2] != "X")
            {
                cout << "Computer chooses: " + board[2][2] << endl;
                board[2][2] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "O" && board[0][2] != "X")
    {
        if (board[2][2] == "O" && board[2][2] != "X")
        {
            if (board[1][2] != "O" && board[1][2] != "X")
            {
                cout << "Computer chooses: " + board[1][2] << endl;
                board[1][2] = "O";
                return;
            }
        }
    }
    if (board[2][2] == "O" && board[2][2] != "X")
    {
        if (board[1][2] == "O" && board[1][2] != "X")
        {
            if (board[0][2] != "O" && board[0][2] != "X")
            {
                cout << "Computer chooses: " + board[0][2] << endl;
                board[0][2] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "O" && board[0][0] != "X") //Down diagonal 
    {
        if(board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[2][2] != "O" && board[2][2] != "X")
            {
                cout << "Computer chooses: " + board[2][2] << endl;
                board[2][2] = "O";
                return;
            }
        }
    }
    if (board[0][0] == "O" && board[0][0] != "X")
    {
        if (board[2][2] == "O" && board[2][2] != "X")
        {
            if (board[1][1] != "O" && board [1][1] != "X")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][2] == "O" && board[2][2] != "X")
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[0][0] != "O" && board[0][0] != "X")
            {
                cout << "Computer chooses: " + board[0][0] << endl;
                board[0][0] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "O" && board[0][2] != "X") //Up diagonal
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[2][0] != "O" && board[2][0] != "X")
            {
                cout << "Computer chooses: " + board[2][0] << endl;
                board[2][0] = "O";
                return;
            }
        }
    }
    if (board[0][2] == "O" && board[0][2] != "X")
    {
        if (board[2][0] == "O" && board[2][0] != "X")
        {
            if (board[1][1] != "O" && board[1][1] != "X")
            {
                cout << "Computer chooses: " + board[1][1] << endl;
                board[1][1] = "O";
                return;
            }
        }
    }
    if (board[2][0] == "O" && board[2][0] != "X")
    {
        if (board[1][1] == "O" && board[1][1] != "X")
        {
            if (board[0][2] != "O" && board[0][2] != "X")
            {
                cout << "Computer chooses: " + board[0][2] << endl;
                board[0][2] = "O";
                return;
            }
        }
    }
    else
        computerFirstMove();
}

bool Tic::draw() /************************* Draw ********************************/
{
    if (board[0][0] != "1" && board[0][1] != "2" && board[0][2] != "3" && board[1][0] != "4" && board[1][1] != "5" && board[1][2] != "6" && board[2][0] != "7" && board[2][1] != "8" && board[2][2] != "9")
    {
        cout << "Draw!" << endl;
        return true;
    }
    
    return false;
}

bool Tic::player1Win() /******************************** Player 1 win ***************************************/
{
    if (board[0][0] == "X") //left column
        if (board[1][0] == "X")
            if (board[2][0] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[0][1] == "X") //Middle column
        if (board[1][1] == "X")
            if (board[2][1] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[0][2] == "X") //Right column
        if (board[1][2] == "X")
            if (board[2][2] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[0][0] == "X") //Top row
        if (board[0][1] == "X")
            if (board[0][2] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[1][0] == "X") //Middle row
        if (board[1][1] == "X")
            if (board[1][2] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[2][0] == "X") //Bottom row
        if (board[2][1] == "X")
            if (board[2][2] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[0][0] == "X") //Down diagonal
        if (board[1][1] == "X")
            if (board[2][2] =="X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[2][0] == "X") //Up diagonal
        if (board[1][1] == "X")
            if (board[0][2] == "X")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
            
    
    return false;
}

bool Tic::player2Win() /****************************** Player 2 win ***************************************/
{
    if (board[0][0] == "O") //left column
        if (board[1][0] == "O")
            if (board[2][0] == "O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    if (board[0][1] == "O") //Middle column
        if (board[1][1] == "O")
            if (board[2][1] == "O")
            {
                cout << "Congrats player 1 you won!" << endl;
                return true;
            }
    if (board[0][2] == "O") //Right column
        if (board[1][2] == "O")
            if (board[2][2] == "O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    if (board[0][0] == "O") //Top row
        if (board[0][1] == "O")
            if (board[0][2] == "O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    if (board[1][0] == "O") //Middle row
        if (board[1][1] == "O")
            if (board[1][2] == "O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    if (board[2][0] == "O") //Bottom row
        if (board[2][1] == "O")
            if (board[2][2] == "O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    if (board[0][0] == "O") //Down diagonal
        if (board[1][1] == "O")
            if (board[2][2] =="O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    if (board[2][0] == "O") //Up diagonal
        if (board[1][1] == "O")
            if (board[0][2] == "O")
            {
                cout << "Congrats player 2 you won!" << endl;
                return true;
            }
    
    
    return false;
}

bool Tic::computerWin()
{
    if (board[0][0] == "O") //left column
        if (board[1][0] == "O")
            if (board[2][0] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[0][1] == "O") //Middle column
        if (board[1][1] == "O")
            if (board[2][1] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[0][2] == "O") //Right column
        if (board[1][2] == "O")
            if (board[2][2] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[0][0] == "O") //Top row
        if (board[0][1] == "O")
            if (board[0][2] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[1][0] == "O") //Middle row
        if (board[1][1] == "O")
            if (board[1][2] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[2][0] == "O") //Bottom row
        if (board[2][1] == "O")
            if (board[2][2] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[0][0] == "O") //Down diagonal
        if (board[1][1] == "O")
            if (board[2][2] =="O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    if (board[2][0] == "O") //Up diagonal
        if (board[1][1] == "O")
            if (board[0][2] == "O")
            {
                cout << "Computer wins!" << endl;
                return true;
            }
    
    
    return false;
}
