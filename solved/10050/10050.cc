#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num_cases;
	cin >> num_cases;
	int n;
	while(cin >> n) {
		int numParties;
		cin >> numParties;
		int count = 0;
		vector<int> hartals;
		for(int i = 0; i < numParties; i++) {
			int h;
			cin >> h;
			hartals.push_back(h);
		}
		int ctr = 1;
		for(int day = 1; day <= n; day++) {
			if((ctr != 6) && (ctr != 7)) {
				for(vector<int>::iterator iter = hartals.begin(); iter != hartals.end(); iter++) {
					if((day % *iter) == 0) {
						count++;
						break;
					}
				}
			}
			if(++ctr > 7)
				ctr = 1;
		}
		cout << count << endl;
	}
	return 0;
}