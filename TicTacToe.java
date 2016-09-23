/*
 TicTacToe.java
 This program imitates a tictactoe game with the computer being a player as well
 Daniel Mora
 2/6/16 
 */

import java.util.Scanner;
import java.util.Random;

public class TicTacToe
{
	private static Scanner cin;
	private String game[][] = new String[3][3]; //Creates 2d array

	public static void main(String[] args)
	{
		cin = new Scanner(System.in);
		TicTacToe tic = new TicTacToe();
		
		char options;
		int spot;
		boolean flag = false;
		int counter = 0;
		boolean move = false;
		boolean draw = false;
		boolean cflag = false;
		
		System.out.println("===== Welcome to TicTacToe =====");
		tic.printBoard();
		System.out.print("Would you like to start?: ");
		options = cin.next().charAt(0);
		
		if (options == 'Y' || options == 'y') //User go first
		{
			while (flag == false && cflag == false)
			{
				System.out.print("Choose your position: ");
				spot = cin.nextInt();
				
				while (move == false)
				{
					move = tic.userMove(spot);
					
					if (move == true)
						break;
					
					System.out.print("Choose your position: ");
					spot = cin.nextInt();
				}
				
				tic.printBoard();
				flag = tic.userWins();
				cflag = tic.computerWins();
				draw = tic.Draw();
				
				if (flag == true)				
					System.exit(0);	
				
				if (draw == true)
					System.exit(0);
				
				if (cflag == true)
					System.exit(0);
				
				if (counter == 1)
				{
					tic.computerContinues();
					tic.printBoard();
				}
				if (counter == 0)
				{
					tic.computerFirstMove();
					tic.printBoard();
					counter++;
				}
				
				move = false;
				spot = 0;
				
				flag = tic.userWins();
				cflag = tic.computerWins();
				draw = tic.Draw();
				
				if (flag == true)				
					System.exit(0);	
				
				if (draw == true)
					System.exit(0);
				
				if (cflag == true)
					System.exit(0);
			}
		}
		else if (options == 'N' || options == 'n') //Computer first
		{
			while (flag == false && cflag == false)
			{
				if (counter == 1)
				{
					tic.computerFirstMove();
					tic.printBoard();
				}
				if (counter == 0)
				{
					tic.computerContinues();
					tic.printBoard();
					counter++;
				}
				
				flag = tic.userWins();
				cflag = tic.computerWins();
				draw = tic.Draw();
				
				if (flag == true)				
					System.exit(0);	
				
				if (draw == true)
					System.exit(0);
				
				if (cflag == true)
					System.exit(0);
				
				System.out.print("Choose your position: ");
				spot = cin.nextInt();
				
				while (move == false)
				{
					move = tic.userMove(spot);
					
					if (move == true)
						break;
					
					System.out.print("Choose your position: ");
					spot = cin.nextInt();
				}
				
				tic.printBoard();
				
				move = false;
				spot = 0;
				
				flag = tic.userWins();
				cflag = tic.computerWins();
				draw = tic.Draw();
				
				if (flag == true)				
					System.exit(0);	
				
				if (draw == true)
					System.exit(0);
				
				if (cflag == true)
					System.exit(0);
			}
		}
		else
		{
			System.out.println("Invalid input, try again");
			System.exit(1);
		}
	}
	
	public TicTacToe() // Sets up board
	{
		game[0][0] = "1";
		game[0][1] = "2";
		game[0][2] = "3";
		game[1][0] = "4";
		game[1][1] = "5";
		game[1][2] = "6";
		game[2][0] = "7";
		game[2][1] = "8";
		game[2][2] = "9";
	}
	public void printBoard()
	{
		System.out.println(" -------------");
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				System.out.print(" | " + game[i][j]);
			
			System.out.print(" |");
			System.out.println();
			System.out.println(" -------------");
		}		
	}
	public void computerFirstMove()
	{
		int x;
		int y;
		boolean flag = false;
		
		Random rn = new Random();
		x = rn.nextInt(2 - 0 + 1) + 0; //generates random numbers
		y = rn.nextInt(2 - 0 + 1) + 0;
		
		while (flag == false)
		{
			if (game[x][y] != "X" && game[x][y] != "O") //checks for open spot
			{
				System.out.println("Computer chooses: " + game[x][y]);
				game[x][y] = "O";
				flag = true;
			}
			
			x = rn.nextInt(2 - 0 + 1) + 0; //If spot not found generate new numbers
			y = rn.nextInt(2 - 0 + 1) + 0;
		}
	}
	public void computerContinues()
	{
		if (game[0][0] == "X" && game[0][0] != "O") // Top row, defending
		{
			if (game[0][1] == "X" && game[0][1] != "O")
			{
				if (game[0][2] != "X" && game[0][2] != "O")
				{
					System.out.println("Computer chooses: " + game[0][2]);
					game[0][2] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "X" && game[0][2] != "O")
		{
			if (game[0][1] == "X" && game[0][1] != "O")
			{
				if (game[0][0] != "X" && game[0][0] != "O")
				{
					System.out.println("Computer chooses: " + game[0][0]);
					game[0][0] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "X" && game[0][0] != "O")
		{
			if (game[0][2] == "X" && game[0][2] != "O")
			{
				if (game[0][1] != "X" && game[0][1] != "O")
				{
					System.out.println("Computer chooses: " + game[0][1]);
					game[0][1] = "O";
					return;
				}
			}
		}
		if (game[1][0] == "X" && game[1][0] != "O") // Middle row, defending
		{
			if (game[1][1] == "X" && game[1][0] != "O")
			{
				if (game[1][2] != "X" && game[1][2] != "O")
				{
					System.out.println("Computer chooses: " + game[1][2]);
					game[1][2] = "O";
					return;
				}
			}
		}
		if (game[1][2] == "X" && game[1][2] != "O")
		{
			if (game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[1][0] != "X" && game[1][0] != "O")
				{
					System.out.println("Computer chooses: " + game[1][0]);
					game[1][0] = "O";
					return;
				}
			}
		}
		if (game[1][0] == "X" && game[1][0] != "O")
		{
			if (game[1][2] == "X" && game[1][2] != "O")
			{
				if (game[1][1] != "X" && game[1][1] != "O")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][0] == "X" && game[2][0] != "O") //Bottom row, defending
		{
			if (game[2][1] == "X" && game[2][1] != "O")
			{
				if (game[2][2] != "X" && game[2][2] != "O")
				{
					System.out.println("Computer chooses: " + game[2][2]);
					game[2][2] = "O";
					return;
				}
			}
		}
		if (game[2][2] == "X" && game[2][2] != "O")
		{
			if (game[2][1] == "X" && game[2][1] != "O")
			{
				if (game[2][0] != "X" && game[2][0] != "O")
				{
					System.out.println("Computer chooses: " + game[2][0]);
					game[2][0] = "O";
					return;
				}
			}
		}
		if (game[2][0] == "X" && game[2][0] != "O")
		{
			if (game[2][2] == "X" && game[2][2] != "O")
			{
				if (game[2][1] != "X" && game[2][1] != "O")
				{
					System.out.println("Computer chooses: " + game[2][1]);
					game[2][1] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "X" && game[0][0] != "O") //Left column
		{
			if (game[1][0] == "X" && game[1][0] != "O")
			{
				if (game[2][0] != "X" && game[2][0] != "O")
				{
					System.out.println("Computer chooses: " + game[2][0]);
					game[2][0] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "X" && game[0][0] != "O")
		{
			if (game[2][0] == "X" && game[2][0] != "O")
			{
				if (game[1][0] != "X" && game[1][0] != "O")
				{
					System.out.println("Computer chooses: " + game[1][0]);
					game[1][0] = "O";
					return;
				}
			}
		}
		if (game[1][0] == "X" && game[1][0] != "O")
		{
			if (game[2][0] == "X" && game[2][0] != "O")
			{
				if (game[0][0] != "X" && game[0][0] != "O")
				{
					System.out.println("Computer chooses: " + game[0][0]);
					game[0][0] = "O";
					return;
				}
			}
		}
		if (game[0][1] == "X" && game[0][1] != "O") //Middle column
		{
			if (game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[2][1] != "X" && game[2][1] != "O")
				{
					System.out.println("Computer chooses: " + game[2][1]);
					game[2][1] = "O";
					return;
				}
			}
		}
		if (game[2][1] == "X" && game[2][1] != "O")
		{
			if (game[0][1] == "X" && game[0][1] != "O")
			{
				if (game[1][1] != "X" && game[1][1] != "O")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][1] == "X" && game[2][1] != "O")
		{
			if (game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[0][1] != "X" && game[0][1] != "O")
				{
					System.out.println("Computer chooses: " + game[0][1]);
					game[0][1] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "X" && game[0][2] != "O") //Right column
		{
			if (game[1][2] == "X" && game[1][2] != "O")
			{
				if (game[2][2] != "X" && game[2][2] != "O")
				{
					System.out.println("Computer chooses: " + game[2][2]);
					game[2][2] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "X" && game[0][2] != "O")
		{
			if (game[2][2] == "X" && game[2][2] != "O")
			{
				if (game[1][2] != "X" && game[1][2] != "O")
				{
					System.out.println("Computer chooses: " + game[1][2]);
					game[1][2] = "O";
					return;
				}
			}
		}
		if (game[2][2] == "X" && game[2][2] != "O")
		{
			if (game[1][2] == "X" && game[1][2] != "O")
			{
				if (game[0][2] != "X" && game[0][2] != "O")
				{
					System.out.println("Computer chooses: " + game[0][2]);
					game[0][2] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "X" && game[0][0] != "O") //Down diagonal 
		{
			if(game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[2][2] != "X" && game[2][2] != "O")
				{
					System.out.println("Computer chooses: " + game[2][2]);
					game[2][2] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "X" && game[0][0] != "O")
		{
			if (game[2][2] == "X" && game[2][2] != "O")
			{
				if (game[1][1] != "X" && game[1][1] != "O")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][2] == "X" && game[2][2] != "O")
		{
			if (game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[0][0] != "X" && game[0][0] != "O")
				{
					System.out.println("Computer chooses: " + game[0][0]);
					game[0][0] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "X" && game[0][2] != "O") //Up diagonal
		{
			if (game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[2][0] != "X" && game[2][0] != "O")
				{
					System.out.println("Computer chooses: " + game[2][0]);
					game[2][0] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "X" && game[0][2] != "O")
		{
			if (game[2][0] == "X" && game[2][0] != "O")
			{
				if (game[1][1] != "X" && game[1][1] != "O")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][0] == "X" && game[2][0] != "O")
		{
			if (game[1][1] == "X" && game[1][1] != "O")
			{
				if (game[0][2] != "X" && game[0][2] != "O")
				{
					System.out.println("Computer chooses: " + game[0][2]);
					game[0][2] = "O";
					return;
				}
			}
		}
		
		// Computer
		if (game[0][0] == "O" && game[0][0] != "X") // Top row
		{
			if (game[0][1] == "O" && game[0][1] != "X")
			{
				if (game[0][2] != "O" && game[0][2] != "X")
				{
					System.out.println("Computer chooses: " + game[0][2]);
					game[0][2] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "O" && game[0][2] != "X")
		{
			if (game[0][1] == "O" && game[0][1] != "X")
			{
				if (game[0][0] != "O" && game[0][0] != "X")
				{
					System.out.println("Computer chooses: " + game[0][0]);
					game[0][0] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "O" && game[0][0] != "X")
		{
			if (game[0][2] == "O" && game[0][2] != "X")
			{
				if (game[0][1] != "O" && game[0][1] != "X")
				{
					System.out.println("Computer chooses: " + game[0][1]);
					game[0][1] = "0";
					return;
				}
			}
		}
		if (game[1][0] == "O" && game[1][0] != "X") // Middle row
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[1][2] != "O" && game[1][2] != "X")
				{
					System.out.println("Computer chooses: " + game[1][2]);
					game[1][2] = "O";
					return;
				}
			}
		}
		if (game[1][2] == "O" && game[1][2] != "X")
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[1][0] != "O" && game[1][0] != "X")
				{
					System.out.println("Computer chooses: " + game[1][0]);
					game[1][0] = "O";
					return;
				}
			}
		}
		if (game[1][0] == "O" && game[1][0] != "X")
		{
			if (game[1][2] == "O" && game[1][2] != "X")
			{
				if (game[1][1] != "O" && game[1][1] != "X")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][0] == "O" && game[2][0] != "X") //Bottom row
		{
			if (game[2][1] == "O" && game[2][1] != "X")
			{
				if (game[2][2] != "O" && game[2][2] != "X")
				{
					System.out.println("Computer chooses: " + game[2][2]);
					game[2][2] = "O";
					return;
				}
			}
		}
		if (game[2][2] == "O" && game[2][2] != "X")
		{
			if (game[2][1] == "O" && game[2][1] != "X")
			{
				if (game[2][0] != "O" && game[2][0] != "X")
				{
					System.out.println("Computer chooses: " + game[2][0]);
					game[2][0] = "O";
					return;
				}
			}
		}
		if (game[2][0] == "O" && game[2][0] != "X")
		{
			if (game[2][2] == "O" && game[2][2] != "X")
			{
				if (game[2][1] != "O" && game[2][1] != "X")
				{
					System.out.println("Computer chooses: " + game[2][1]);
					game[2][1] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "O" && game[0][0] != "X") //Left column
		{
			if (game[1][0] == "O" && game[1][0] != "X")
			{
				if (game[2][0] != "O" && game[2][0] != "X")
				{
					System.out.println("Computer chooses: " + game[2][0]);
					game[2][0] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "O" && game[0][0] != "X")
		{
			if (game[2][0] == "O" && game[2][0] != "X")
			{
				if (game[1][0] != "O" && game[1][0] != "X")
				{
					System.out.println("Computer chooses: " + game[1][0]);
					game[1][0] = "O";
					return;
				}
			}
		}
		if (game[1][0] == "O" && game[1][0] != "X")
		{
			if (game[2][0] == "O" && game[2][0] != "X")
			{
				if (game[0][0] != "O" && game[0][0] != "X")
				{
					System.out.println("Computer chooses: " + game[0][0]);
					game[0][0] = "O";
					return;
				}
			}
		}
		if (game[0][1] == "O" && game[0][1] != "X") //Middle column
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[2][1] != "O" && game[2][1] != "X")
				{
					System.out.println("Computer chooses: " + game[2][1]);
					game[2][1] = "O";
					return;
				}
			}
		}
		if (game[2][1] == "O" && game[2][1] != "X")
		{
			if (game[0][1] == "O" && game[0][1] != "X")
			{
				if (game[1][1] != "O" && game[1][1] != "X")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][1] == "O" && game[2][1] != "X")
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[0][1] != "O" && game[0][1] != "X")
				{
					System.out.println("Computer chooses: " + game[0][1]);
					game[0][1] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "O" && game[0][2] != "X") //Right column
		{
			if (game[1][2] == "O" && game[1][2] != "X")
			{
				if (game[2][2] != "O" && game[2][2] != "X")
				{
					System.out.println("Computer chooses: " + game[2][2]);
					game[2][2] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "O" && game[0][2] != "X")
		{
			if (game[2][2] == "O" && game[2][2] != "X")
			{
				if (game[1][2] != "O" && game[1][2] != "X")
				{
					System.out.println("Computer chooses: " + game[1][2]);
					game[1][2] = "O";
					return;
				}
			}
		}
		if (game[2][2] == "O" && game[2][2] != "X")
		{
			if (game[1][2] == "O" && game[1][2] != "X")
			{
				if (game[0][2] != "O" && game[0][2] != "X")
				{
					System.out.println("Computer chooses: " + game[0][2]);
					game[0][2] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "O" && game[0][0] != "X") //Down diagonal 
		{
			if(game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[2][2] != "O" && game[2][2] != "X")
				{
					System.out.println("Computer chooses: " + game[2][2]);
					game[2][2] = "O";
					return;
				}
			}
		}
		if (game[0][0] == "O" && game[0][0] != "X")
		{
			if (game[2][2] == "O" && game[2][2] != "X")
			{
				if (game[1][1] != "O" && game [1][1] != "X")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][2] == "O" && game[2][2] != "X")
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[0][0] != "O" && game[0][0] != "X")
				{
					System.out.println("Computer chooses: " + game[0][0]);
					game[0][0] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "O" && game[0][2] != "X") //Up diagonal
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[2][0] != "O" && game[2][0] != "X")
				{
					System.out.println("Computer chooses: " + game[2][0]);
					game[2][0] = "O";
					return;
				}
			}
		}
		if (game[0][2] == "O" && game[0][2] != "X")
		{
			if (game[2][0] == "O" && game[2][0] != "X")
			{
				if (game[1][1] != "O" && game[1][1] != "X")
				{
					System.out.println("Computer chooses: " + game[1][1]);
					game[1][1] = "O";
					return;
				}
			}
		}
		if (game[2][0] == "O" && game[2][0] != "X")
		{
			if (game[1][1] == "O" && game[1][1] != "X")
			{
				if (game[0][2] != "O" && game[0][2] != "X")
				{
					System.out.println("Computer chooses: " + game[0][2]);
					game[0][2] = "O";
					return;
				}
			}
		}
		else
			computerFirstMove();
	}
	public boolean userMove(int position) //user positioning 
	{
		if (position == 1)
		{
			if (game[0][0] != "X" && game[0][0] != "O")
			{
				game[0][0] = "X";
				return true;
			}
			else
				return false;
		}
		else if (position == 2)
		{
			if (game[0][1] != "X" && game[0][1] != "O")
			{
				game[0][1] = "X";
				return true;
			}
			else
				return false;
		}
		else if (position == 3)
		{
			if (game[0][2] != "X" && game[0][2] != "O")
			{
				game[0][2] = "X";
				return true;
			}
			else
				return false;
		}
		else if (position == 4)
		{
			if (game[1][0] != "X" && game[1][0] != "O")
			{
				game[1][0] = "X";
				return true;
			}
			else
				return false;
		}
		else if (position == 5)
		{
			if (game[1][1] != "X" && game[1][1] != "O")
			{
				game[1][1] = "X";
				return true;
			}
			else
				return false;
		}
		else if (position == 6)
		{
			if (game[1][2] != "X" && game[1][2] != "O")
			{
				game[1][2] = "X";
				return true;
			}
			else 
				return false;
		}
		else if (position == 7)
		{
			if (game[2][0] != "X" && game[2][0] != "O")
			{
				game[2][0] = "X";
				return true;
			}
			else 
				return false;
		}
		else if (position == 8)
		{
			if (game[2][1] != "X" && game[2][1] != "O")
			{
				game[2][1] = "X";
				return true;
			}
			else 
				return false;
		}
		else if (position == 9)
		{
			if (game[2][2] != "X" && game[2][2] != "O")
			{
				game[2][2] = "X";
				return true;
			}
			else 
				return false;
		}
		else 
			return false;
	}
	public boolean userWins()
	{
		if (game[0][0] == "X") //left column
			if (game[1][0] == "X")
				if (game[2][0] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[0][1] == "X") //Middle column
			if (game[1][1] == "X")
				if (game[2][1] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[0][2] == "X") //Right column
			if (game[1][2] == "X")
				if (game[2][2] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[0][0] == "X") //Top row
			if (game[0][1] == "X")
				if (game[0][2] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[1][0] == "X") //Middle row
			if (game[1][1] == "X")
				if (game[1][2] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[2][0] == "X") //Bottom row
			if (game[2][1] == "X")
				if (game[2][2] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[0][0] == "X") //Down diagonal
			if (game[1][1] == "X")
				if (game[2][2] =="X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		if (game[2][0] == "X") //Up diagonal
			if (game[1][1] == "X")
				if (game[0][2] == "X")
				{
					System.out.println("Congrats you won!");
					return true;
				}
		else
			return false;
		
		return false;
	}
	public boolean computerWins()
	{
		if (game[0][0] == "O") //left column
			if (game[1][0] == "O")
				if (game[2][0] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[0][1] == "O") //Middle column
			if (game[1][1] == "O")
				if (game[2][1] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[0][2] == "O") //Right column
			if (game[1][2] == "O")
				if (game[2][2] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[0][0] == "O") //Top row
			if (game[0][1] == "O")
				if (game[0][2] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[1][0] == "O") //Middle row
			if (game[1][1] == "O")
				if (game[1][2] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[2][0] == "O") //Bottom row
			if (game[2][1] == "O")
				if (game[2][2] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[0][0] == "O") //Down diagonal
			if (game[1][1] == "O")
				if (game[2][2] =="O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		if (game[2][0] == "O") //Up diagonal
			if (game[1][1] == "O")
				if (game[0][2] == "O")
				{
					System.out.println("Computer wins!");
					return true;
				}
		else
			return false;
		
		return false;
	}
	public boolean Draw() //Checks for a draw game
	{
		if (game[0][0] != "1" && game[0][1] != "2" && game[0][2] != "3" && game[1][0] != "4" && game[1][1] != "5" && game[1][2] != "6" && game[2][0] != "7" && game[2][1] != "8" && game[2][2] != "9")
		{
			System.out.println("Draw!");
			return true;
		}
		
		return false;
	}
}
