#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int showDice (int diceroll) {  //a if case for every possible die orientation
	
	if (diceroll == 1){  
		printf("+-------+\n");
		printf("|       |\n");
		printf("|   O   |\n");
		printf("|       |\n");
		printf("+-------+ \n");
	}
		if (diceroll == 2){
		printf("+-------+\n");
		printf("|     O |\n");
		printf("|       |\n");
		printf("| O     |\n");
		printf("+-------+\n");
	}
		if (diceroll == 3){
		printf("+-------+\n");
		printf("|     O |\n");
		printf("|   O   |\n");
		printf("| O     |\n");
		printf("+-------+\n");
	}
		if (diceroll == 4){
		printf("+-------+ \n");
		printf("| O   O |\n");
		printf("|       |\n");
		printf("| O   O |\n");
		printf("+-------+\n");
	}
		if (diceroll == 5){
		printf("+-------+\n");
		printf("| O   O |\n");
		printf("|   O   |\n");
		printf("| O   O |\n");
		printf("+-------+\n");
	}
		if (diceroll == 6){
		printf("+-------+\n");
		printf("| O   O |\n");
		printf("| O   O |\n");
		printf("| O   O |\n");
		printf("+-------+\n");
	}
	return 0;
	
}





int main(void) {
	
	int totalS; //game total
	int diceroll;
	srand(time(NULL));
	char lett1;
	int turnscore1, turnscore2, playerscore1, playerscore2, turnnumber;
	turnscore1 = 0;
	turnscore2 = 0;
	playerscore1 = 0;
	playerscore2 = 0;
	turnnumber = 0;
	
	
printf("Welcome to the game of Pig!\n\nInput a game total: ");
scanf("%d", &totalS);
printf("Your game total is: %d\n---------------\n", totalS);
	
	
	while ((totalS  > playerscore1) && (totalS > playerscore2)) {  //as long as total score set by user is greater than both player's scores, //game runs
			
	
			while ((turnnumber % 2 == 0) && (playerscore1 < totalS)) { //turnnumber starts at 0. Even numbers module 0 = 0, allowing the loop to execute.
				printf("Player 1: (r)oll or (h)old? \n");
				scanf("%c", &lett1);
				lett1 = getchar();
			
				if (lett1 == 'r') {
									
					diceroll = (rand() % 6) + 1;  //'rolls' die
					showDice(diceroll);
								
					if (diceroll > 1) {
						turnscore1 += diceroll;  //turnscore = dice + turnscore
					
						if ((turnscore1 + playerscore1) >= totalS) { //if the sum of playerscore and turnscore is > total score, branch executes.
							playerscore1 += turnscore1;
							printf("Player 1's total score is: %d\n",playerscore1);
							printf("Player 1 wins!\n");
							
							return 0; //ends the game
						}
						printf("Rolled %d: Your turn score is: %d\n",diceroll, turnscore1);
						playerscore1 = turnscore1 + playerscore1; //to display the playerscore sum of turnscore + playerscore is = to playerscore
						printf("Your total score is: %d\n-----------------\n", playerscore1);
						playerscore1 = playerscore1 - turnscore1; //to reset playerscore, incase a 1 is rolled, b/c turnscore = 0 when 1's rolled
						
					} 
					
					else if (diceroll == 1){
						turnscore1 = 0;
						
						turnnumber++; //adds one to turnnumber, breaking loop, moving to player twos loop.
						printf("Player 1 rolled a 1, lose a turn.\nTurnscore set to %d\n\n", turnscore1);
						printf("Total Score: %d\n---------------\n", playerscore1);
						break;
					}

				} 
				else if (lett1 == 'h') { //player holds
				 playerscore1 += turnscore1; //sets playerscore value
					if (playerscore1 >= totalS) {
						printf("Player 1 wins!\n");
						continue; //continues, b/c above if branch is not always true.
					}
					
					turnscore1 = 0;
					turnnumber++; //adds one to turnnumber, making module return a value not = to 0, so while loop 2 executes.
					printf("Player 1 holds: Total score is %d\n--------------------\n", playerscore1);
					break;
				}		
				
			}
		
			while ((turnnumber % 2 != 0) && (playerscore2 < totalS)) { /*while loop 2*/				printf("Player 2: (r)oll or (h)old?  \n");
				scanf("%c", &lett1);
				lett1 = getchar();
					
				if (lett1 == 'r') {
															
					diceroll = (rand() % 6) + 1;
					showDice(diceroll);
														
					if (diceroll > 1) {
						turnscore2 += diceroll;
						
						if ((playerscore2 + turnscore2) >= totalS) {
							playerscore2 += turnscore2;
							
							printf("Player 2's score is: %d\n", playerscore2);
							printf("Player 2 wins!\n");
							
							return 0;  //ends the game
						}
						printf("Rolled %d: Your turn score is: %d\n", diceroll, turnscore2);
						playerscore2 = turnscore2 + playerscore2;
						printf("Yourr total score is: %d\n-----------------\n", playerscore2);
						playerscore2 = playerscore2 - turnscore2;
					} 
					else if (diceroll == 1){
						turnscore2 = 0;
						turnnumber++;
						printf("Player 2 rolled a 1, lose a turn.\nTurnscore set to %d\nTotal Score: %d\n---------------\n", turnscore2, playerscore2);
						break;
					}

				} 
				
				else if (lett1 == 'h') {
				playerscore2 += turnscore2;
					if (playerscore2 >= totalS) {
						printf("Player 2 wins!\n");
						continue;
					}
					turnscore2 = 0;
					turnnumber++;
					printf("Player 2 holds: Total score is %d\n----------------\n", playerscore2);
					break;
				}							
			}
		
			
	}
	return 0;
}

