//
//  main.cpp
//  TicTacToe
//
//  Created by Daniel Mora on 6/15/16.
//  Copyright © 2016 Daniel Mora. All rights reserved.
//

#include "Game.h"

int main()
{
    Tic game;
    bool p1win = false;
    bool p2win = false;
    bool draw = false;
    bool comwin = false;
    bool move = false;
    int option;
    int place;
    int num;
    int counter = 0;
    char start = 'z';
    
    cout << "=============== Welcome to TicTacToe ====================" << endl << endl;
    cout << "1: Player v. Computer." << endl;
    cout << "2: Player v. Player." << endl;
    cout << "3: Quit." << endl;
    cout << "Select an option: ";
    cin >> option;
    
    cout << endl;
    
    switch (option)
    {
        case 1:
            
            game.printBoard();
            
            cout << "\nDo you want to go first: ";
            cin >> start;
            
            if (start == 'Y' || start == 'y')
            {
                while (p1win == false && comwin == false && draw == false)
                {
                    cout << "Choose your position: ";
                    cin >> place;
                    
                    while (move == false)
                    {
                        move = game.player1Move(place);
                        
                        if (move == true)
                            break;
                        
                        cout << "Invalid option" << endl;
                        cout << "Choose your position: ";
                        cin >> place;
                    }
                    
                    game.printBoard();
                    
                    cout << endl;
                    
                    p1win = game.player1Win();
                    comwin = game.computerWin();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (comwin == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                    
                    if (counter == 1)
                    {
                        game.computerContinue();
                        game.printBoard();
                        
                        cout << endl;
                    }
                    if (counter == 0)
                    {
                        game.computerFirstMove();
                        game.printBoard();
                        
                        cout << endl;
                        
                        counter++;
                    }
                    
                    move = false;
                    place = 0;
                    
                    p1win = game.player1Win();
                    comwin = game.computerWin();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (comwin == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                }
            }
            else if (start == 'N' || start == 'n')
            {
                while (p1win == false && comwin == false && draw == false)
                {
                    if (counter == 1)
                    {
                        game.computerContinue();
                        game.printBoard();
                        
                        cout << endl;
                    }
                    if (counter == 0)
                    {
                        game.computerFirstMove();
                        game.printBoard();
                        
                        cout << endl;
                        
                        counter++;
                    }
                    
                    p1win = game.player1Win();
                    comwin = game.computerWin();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (comwin == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                    
                    cout << "Choose your position: ";
                    cin >> place;
                    
                    while (move == false)
                    {
                        move = game.player1Move(place);
                        
                        if (move == true)
                            break;
                        
                        cout << "Invalid option" << endl;
                        cout << "Choose your position: ";
                        cin >> place;
                    }
                    
                    move = false;
                    place = 0;
                    
                    game.printBoard();
                    
                    cout << endl;
                    
                    p1win = game.player1Win();
                    comwin = game.computerWin();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (comwin == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                }
            }
            else
            {
                cout << "Invalid option" << endl;
                exit(1);
            }
            
            break;
            
        case 2:
            
            srand(time(0));
            
            game.printBoard();
            
            cout << endl;
            
            num = rand() % 2;
            
            if (num == 0)
            {
                cout << "Player 1 goes first" << endl;
                
                while (p1win == false && p2win == false && draw == false)
                {
                    cout << "Choose your position player 1: ";
                    cin >> place;
                    
                    while (move == false)
                    {
                        move = game.player1Move(place);
                        
                        if (move == true)
                            break;
                        
                        cout << "Invalid option" << endl;
                        cout << "Choose your position player 1: ";
                        cin >> place;
                    }
                    
                    move = false;
                    place = 0;
                    
                    game.printBoard();
                    
                    cout << endl;
                    
                    p1win = game.player1Win();
                    p2win = game.player2Win();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (p2win == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                    
                    cout << "Choose your position player 2: ";
                    cin >> place;
                    
                    while (move == false)
                    {
                        move = game.player2Move(place);
                        
                        if (move == true)
                            break;
                        
                        cout << "Invalid option" << endl;
                        cout << "Choose your position player 2: ";
                        cin >> place;
                    }
                    
                    move = false;
                    place = 0;
                    
                    game.printBoard();
                    
                    cout << endl;
                    
                    p1win = game.player1Win();
                    p2win = game.player2Win();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (p2win == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                }
            }
            if (num == 1)
            {
                cout << "Player 2 goes first" << endl;
                
                while (p1win == false && p2win == false && draw == false)
                {
                    cout << "Choose your position player 2: ";
                    cin >> place;
                    
                    while (move == false)
                    {
                        move = game.player2Move(place);
                        
                        if (move == true)
                            break;
                        
                        cout << "Invalid option" << endl;
                        cout << "Choose your position player 2: ";
                        cin >> place;
                    }
                    
                    move = false;
                    place = 0;
                    
                    game.printBoard();
                    
                    cout << endl;
                    
                    p1win = game.player1Win();
                    p2win = game.player2Win();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (p2win == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                    
                    cout << "Choose your position player 1: ";
                    cin >> place;
                    
                    while (move == false)
                    {
                        move = game.player1Move(place);
                        
                        if (move == true)
                            break;
                        
                        cout << "Invalid option" << endl;
                        cout << "Choose your position player 1: ";
                        cin >> place;
                    }
                    
                    move = false;
                    place = 0;
                    
                    game.printBoard();
                    
                    cout << endl;
                    
                    p1win = game.player1Win();
                    p2win = game.player2Win();
                    draw = game.draw();
                    
                    if (p1win == true)
                        exit(0);
                    
                    if (p2win == true)
                        exit(0);
                    
                    if (draw == true)
                        exit(0);
                }
            }
            
            break;
        
        case 3:
            
            cout << "Shutting down" << endl;
            exit(0);
            
            break;
        default:
            
            cout << "Invalid option" << endl << endl;
            exit(1);
            break;
    }
    
    return 0;
}
