//20043 10310
//Chapter 13: Dog and Gopher
//Brad Yinger

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

double dist(double x1,double y1,double x2,double y2) {
	// sqrt can act screwy
	return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() {
	int n;
	double gx,gy,dx,dy,hx,hy;
	cout << std::setiosflags(ios::fixed);
	cout << std::setprecision(3);
	while(cin >> n >> gx >> gy >> dx >> dy) {
		bool found = false;
		while(--n >= 0 && (cin >> hx >> hy)) {
			if(found) continue;
			double d = dist(hx,hy,dx,dy);
			double g = dist(hx,hy,gx,gy);
			if(g*4 <= d) {
				found = true;
				cout << "The gopher can escape through the hole at (" << hx << "," << hy << ")." << endl;
			}
		}
		if(!found) cout << "The gopher cannot escape." << endl;
	}
	return 0;
}
