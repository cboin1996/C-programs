#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include <time.h> 

		
//Author: Christian Boin
//Date: Oct. 18, 2015
//0914666
//Find the Mugwump
	
void showBoard(int x, int y)  //array for the showboard function
{
	char row0[11] = {' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char row1[11] = {'0', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row2[11] = {'1', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row3[11] = {'2', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row4[11] = {'3', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row5[11] = {'4', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row6[11] = {'5', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row7[11] = {'6', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row8[11] = {'7', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row9[11] = {'8', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
	char row10[11] = {'9', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};  //array for board
	
	x++;   //gives proper coordinates as
	y++;   //the array starts indexing at 0
	
	switch (x) {  //switch statements execute for each array based off x coordinate entry to determine the location of user guess 'W'
		case 1:
			row1[y]='W';
			break;
			
		case 2:
			row2[y]='W';
			break;
			
		case 3:
			row3[y]='W';
			break;
			
		case 4:
			row4[y]='W';
			break;
			
		case 5:
			row5[y]='W';
			break;
			
		case 6:
			row6[y]='W';
			break;
			
		case 7:
			row7[y]='W';
			break;
			
		case 8:
			row8[y]='W';
			break;
			
		case 9:
			row9[y]='W';
			break;
			
		case 10: 
			row10[y]='W';
			break;
	}
	
	 for (int row = 0; row <= 10 ; row++) { //generates row until position 10 in row0 is reached, newline moves to next for loop generating 
											 //following rows in a similar process following rows
			printf("%c ", row0[row]);
	 }
		printf("\n");
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row1[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row2[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row3[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row4[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row5[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row6[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row7[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row8[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row9[row]);
	 }
		printf("\n");
		
	 for (int row = 0; row <= 10 ; row++) {
			printf("%c ", row10[row]);
	 }
		printf("\n");
		
}

		



int main(void) { //main function (core of game)
		

		srand(time(0));
		int randomX = rand() % 10; //generates a number between one and 9
		int randomY = rand() % 10; //generates a number between one and 9
		int row, col; //user entered x y values
		int distX;
		int distY;
		float dist;
		int turn;
				
		printf("-------------------------------\nWelcome to the Find the Mugwamp\n\nType '57 09' to quit\n\n");
		
			for (turn = 1; turn <=10; turn++) {
			printf("Turn number: %d\n", turn);
			printf("Please enter x y values [0 to 9]: ");//above lines are initial outputs upon start of program
			scanf("%d %d", &row, &col); //reads users x y input
			printf("\n");  
			
				if (row == 57 && col == 9) {
					turn = 10;
					printf("You have ended the game.\n---------------------------\n"); //end game feature
				}
				
				else if (row < 0 || col < 0 || row >= 10 || col >= 10) { 
					printf("Error! x y values must be greater than or equal to 0 and less than 10.							\n--------------------\n"); //values must be between 0 & 9, to access the board
					turn--;
				}
				
				
				else {
						showBoard(row, col);  //calls showboard function displaying the board
						distX = pow(abs(row - randomX), 2);  //finds distance from user guess to mugwump in x direction and y direction
						distY = pow(abs(col - randomY), 2);  
		
						dist = sqrt(distX + distY); //pythagorean theorem for the distance from mugWamp compared to user input
		
						printf("\nYou entered: %d, %d, ", row, col);
						printf("you are %.2f units away from the mugwamp. \n------------------------\n", dist);
			
								if (dist == 0) { //sets turn to ten, ending the game, then printing you have found the mugwump
								turn = 10;
								printf("You have found the Mugwamp!\n\n");
								}
								
								else if (turn == 10) {
								printf("You have exceeded the allowed the allowed amount of turns, game over.										\n------------------------\n"); //turns exceeded (10 allowed max), game ends
								}
				}
			}	
			
return 0;
		
}
