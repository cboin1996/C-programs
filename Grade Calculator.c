

#include <stdio.h>
#include <math.h>

int main(void) {
	
	float weight1 = 0.0;
	float weight2 = 0.0;
	float weight3 = 0.0;
	float weight4 = 0.0;
	float weight5 = 0.0;
	float weight6 = 0.0;
	float weight7 = 0.0;
	float weight8 = 0.0;
	float weight9 = 0.0;
	float weight10 = 0.0;
	int marknum;
	
	float mark1 = 0.0;
	float mark2 = 0.0;
	float mark3 = 0.0;
	float mark4 = 0.0;
	float mark5 = 0.0;
	float mark6 = 0.0;
	float mark7 = 0.0;
	float mark8 = 0.0;
	float mark9 = 0.0;
	float mark10 = 0.0;
	float totalweight;
	int markNumTot;
	float average = 0;
		
	
	printf("Enter the amount of marks you wish to enter (up to 10): ");
	scanf("%d", &markNumTot);
	marknum = 1;
	
	if (marknum == 1) {
		printf("Enter your 1st mark an its weight: ");
				scanf("%f %f", &mark1, &weight1);
				
		totalweight = weight1;
		average = (mark1 * weight1) / (weight1);
				marknum++;
		}
	
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark2, &weight2);
				
		totalweight = weight1 + weight2;
		average = ((mark1 * weight1) + (mark2 * weight2)) / totalweight;
				marknum++;
		}
	
		
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark3, &weight3);
				
		totalweight = weight1 + weight2 + weight3;
		average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3)) / totalweight;
				marknum++;
		}
	
		
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark4, &weight4);
				
		totalweight = weight1 + weight2 + weight3 + weight4;
		average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4)) / totalweight;
				marknum++;
		}	
	
	
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark5, &weight5);
				
		totalweight = weight1 + weight2 + weight3 + weight4 + weight5;
		average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4) + (mark5 * weight5)) / totalweight;
						marknum++;
		}
	
		
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark6, &weight6);
		totalweight = weight1 + weight2 + weight3 + weight4 + weight5 + weight6;
		average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4) + (mark5 * weight5) + (mark6 * weight6)) / totalweight;
						marknum++;
		}

			
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark7, &weight7);
		totalweight = weight1 + weight2 + weight3 + weight4 + weight5 + weight6 + weight7;
		average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4) + (mark5 * weight5) + (mark6 * weight6) + (mark7 * weight7)) / totalweight;
						marknum++;
		}
	
			
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark8, &weight8);
		totalweight = weight1 + weight2 + weight3 + weight4 + weight5 + weight6 + weight7 + weight8;
											average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4) + (mark5 * weight5) + (mark6 * weight6) + (mark7 * weight7) + (mark8 * weight8)) / totalweight;
						marknum++;
		}
	
	
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark9, &weight9);
		totalweight = weight1 + weight2 + weight3 + weight4 + weight5 + weight6 + weight7 + weight8 + weight9;
														average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4) + (mark5 * weight5) + (mark6 * weight6) + (mark7 * weight7) + (mark8 * weight8) + (mark9 * weight9)) / totalweight;
						marknum++;		
		}
	
		
	if (marknum <= markNumTot) {
		printf("Enter mark %d and its weight:  ", marknum);
				scanf("%f %f", &mark10, &weight10);
		
		totalweight = weight1 + weight2 + weight3 + weight4 + weight5 + weight6 + weight7 + weight8 + weight9 + weight10;
														average = ((mark1 * weight1) + (mark2 * weight2) + (mark3 * weight3) + (mark4 * weight4) + (mark5 * weight5) + (mark6 * weight6) + (mark7 * weight7) + (mark8 * weight8) + (mark9 * weight9) + (mark10 * weight10)) / totalweight;
						marknum++;
		}
	
	printf("Your average is: %.2f\n\n", average);
			
	return 0;	

}
