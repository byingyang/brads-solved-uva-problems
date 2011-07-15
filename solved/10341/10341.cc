#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

#define EPS 1e-7

using namespace std;

int p,q,r,s,t,u;

double f(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bs(){
  double lo = 0, hi = 1;
  while (lo + EPS < hi) {
    double x = (lo+hi)/2;
    if (f(lo) * f(x) <= 0){
      hi = x;
    } else {
      lo = x;
    }
  }
  return (lo+hi)/2;
}

int main() {
	while(cin >> p >> q >> r >> s >> t >> u) {
		if((f(0) * f(1)) > 0) {
			cout << "No solution" << endl;
		}
		else {
			printf("%.4lf\n", bs());
		}
	}
	return 0;
}
