//20043 10209
//Chapter 13: Is this integration?
//Brad Yinger

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

#define PI  2.0*acos(0.0)

int main(int argc, char *argv[]) {
	double a,area,x,y,z,t=3*sqrt(3.0);
    while(cin >> a) {
        area = a * a;
		z=(PI+3-t)/3*area;
		x=(.5*PI*area-z-area)/2;
		y=(area-z-4*x)/4;
        printf("%-3.3f %-3.3f %-3.3f\n",z,x*4,y*4);
    }
    return 0;
}
