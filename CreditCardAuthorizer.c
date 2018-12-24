//Author: Christian Boin
//Date: Nov 29, 2015
//0914666
//Luhn's Algorithm

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void readCC(int credCard[50]);
void isValid(int cardNombre[50]);
int  runLuhn(int num[50]);

int main(void) {  //main function: main fn for running prog & calling functions readcc & isValid

	int userCred[50];

	readCC(userCred);
	isValid(userCred);

return 0;

}

void readCC(int credCard[50]) {  //reads cred card from user as string, converts to integer array

	char credC[50];
	int i = 0;
	
	printf("\n\nEnter your credit card number: ");
	scanf("%s", credC);

	if (strlen(credC) != 16)
	{
		printf("Error! Must be a 16 digit number. Terminating.\n\n");
		exit(-1);  //terminates program, (-1) indicates error in input.
	} 

	else 
	{
		for (i=0; i<16; i++) 
		{

			if(credC[i] >= 48 && credC[i] <=57)  //anything but these ASCII values are not digits
			{
		    	credCard[i] = credC[i] - 48;
			}

			else 
			{
				printf("Error! Credit card number must not contain characters.  Terminating.\n\n");
				exit(-1);
			}
		}
	}

return;

}

void isValid(int cardNombre[50]) {  //checks if credit card is valid by calling runLuhn fn

	if (runLuhn(cardNombre) == 0)  //if checkSum is evenly divisible by 10
	{
		printf("Credit card is valid.  Goodbye.\n\n");
	}

	else
	{
		printf("Credit card is invalid.  Goodbye.\n\n");
	}

return;

}

int runLuhn(int num[50]) { //runs Luhn's algorithm to determine the sum to be checked by isValid fn

	int i = 0;
	int checkSum = 0;

	for (i=0; i <16; i++) {

		if(i%2 == 0)
		{
			num[i] *= 2;
		}

		if(num[i] > 9) 
		{
			checkSum += num[i] / 10;  //splits even positioned nums > 9, adding to checkSum
			checkSum += num[i] % 10;
		} 

		else 
		{
			checkSum += num[i];
		}
	}

return checkSum % 10;

}
