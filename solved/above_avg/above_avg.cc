#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(cin >> n) {
		int *vals = new int[n];
		int sum = 0;
		for(int i = 0; i < n; i++) {
			int c;
			cin >> c;
			vals[i] = c;
			sum += c;
		}
		float avg = (float)sum / n;
		int numAboveAvg = 0;
		for(int i = 0; i < n; i++) {
			if(vals[i] > avg) {
				numAboveAvg++;
			}
		}
		
		cout << setprecision(3) << fixed << ((float)numAboveAvg / n) * 100 << "%" << endl;
		
		delete[] vals;
	}
	return 0;
}