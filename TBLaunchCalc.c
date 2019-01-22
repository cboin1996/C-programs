#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ConsMomen(double massA, double massB, double Vbix, double Vbiy);
void EnergyCalc(double massSys, double massP, double accelG, double height, double angle, double* vBallx, double* vBally);
double elasStretch(double massShoot, double kElast, double velShoot); //returns delta x
double DegtoRad(double Deg);
double MeterToCm(double meter);
double GramToKG(double grams);
double findRange(double vBally, double vBallx, double heightNet, double maxHeightBall, double aG);

int main(void) {
	//double const distPins = 0.596; //m  FIXME
	//double const radiusHoop = 0.10; //m FIXME
	double const heightNet = 2.0; //m  FIXME
	double kVal = 0.0;
	double maxHeight = 0.0;
	double const A_G = 9.81;
	double massPong = 0.0;
	double massSling = 0.0;
	double velBalinitx = 0.0;
	double velBalinity = 0.0;
	double theta = 0.0;
	double finalVelSling = 0.0;
	double deltaXm = 0.0;
	
	printf("Enter the k values for your elastic(s) (N/m): ");
	scanf("%lf", &kVal);
	printf("\nEnter the max height you wish your ball to reach (m): ");
	scanf("%lf", &maxHeight);
	printf("\nEnter the launch angle in degrees: ");
	scanf("%lf", &theta);
	printf("\nEnter the mass of your ping pong ball (g): ");
	scanf("%lf", &massPong);
	printf("\nEnter the mass of your launch system (g): ");
	scanf("%lf", &massSling);
	
	massPong = GramToKG(massPong);
    massSling = GramToKG(massSling);
	
	theta = DegtoRad(theta);
	EnergyCalc(massSling, massPong, A_G, maxHeight, theta, &velBalinitx, &velBalinity);
	
	printf("\n---------------------------------------------------\n");
	printf("Initial components of velocity of the ball are: Vix: %0.2lfm/s, & Viy: %0.2lfm/s", velBalinitx, velBalinity);
	
	finalVelSling = ConsMomen(massSling, massPong, velBalinitx, velBalinity);
	printf("\n\nVelocity of Slingshot at impact is: %0.2lfm/s", finalVelSling);
	
	deltaXm =  elasStretch(massSling, kVal, finalVelSling);
	
    printf("\n\nStretch your elastics back: %0.2lfcm", MeterToCm(deltaXm));
 
    printf("\n\nYour horizontal range to the height of the net is: %0.2lfm", findRange(velBalinity, velBalinitx, heightNet, maxHeight, A_G));

	printf("\n\nYour should shoot the ball %0.2lfm from the hoop", findRange(velBalinity, velBalinitx, heightNet, maxHeight, A_G) - 0.10);

    return 0;
}

double DegtoRad(double Deg) {

return Deg * ( M_PI / 180);
	
}

void EnergyCalc(double massSys, double massP, double accelG, double height, double angle, double* vBallx, double* vBally) {
	
	double vBall = 0.0;
	
	vBall = (sqrt(2 * accelG * height));
	*vBallx = vBall * cos(angle); // 
	*vBally = vBall * sin(angle);
	
	return;
	
}

double ConsMomen(double massA, double massB, double Vbix, double Vbiy) {
	
	return  sqrt(pow((massB * Vbix) / massA, 2.0) + pow((massB * Vbiy) / massA, 2.0)); //returns the velocity of the slingshot system
	                                                                                        //at moment of impact with pong ball
}

double elasStretch(double massShoot, double kElast, double velShoot) {

    return sqrt((massShoot * pow(velShoot, 2.0)) / kElast);
}

double MeterToCm(double meter) {
	
	return meter * 100;
}

double GramToKG(double grams) {
	
	return grams / 1000;
}

double findRange(double vBally, double vBallx, double heightNet, double maxHeightBall, double aG) {
	
	double timeToMax = 0.0;
	double rangeAtMax = 0.0;
	double dispMaxtoNet = 0.0;
	double timeFromMax = 0.0;
	double rangeFromMax = 0.0;
	
	timeToMax = vBally / aG;
	
	rangeAtMax = vBallx * timeToMax;
	
	dispMaxtoNet = maxHeightBall - heightNet;
	
	timeFromMax = sqrt(dispMaxtoNet / aG);
	
	rangeFromMax = vBallx * timeFromMax;
	
	return rangeAtMax + rangeFromMax;
	
}
