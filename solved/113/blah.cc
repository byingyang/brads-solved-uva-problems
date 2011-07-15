#include <iostream>
#include <cmath>

using namespace std;

int main() {
	unsigned int n;
	double p;
	while(cin >> n >> p) {
		double d = floor(pow(10, (log10(p) / (double)n))+0.5);
		cout << ((long long)(d)) << endl;
	}
	return 0;
}
