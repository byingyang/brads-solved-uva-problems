//20043 {{ProblemID}}
//Chapter: Problem Name 
//Brad Yinger

#include <iostream>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

int main() {
	int n;
	cin >> n;
	For(i, 0, n) {
		int l;
		cin >> l;
		unsigned int *bin = new unsigned int[l];
		For(k, 0, l) {
			cin >> bin[k];
		}
		int total = 0;
		while(true) {
			int p = 0;
			For(k, 0, l-1) {
				if(bin[k] > bin[k+1]) {
					unsigned int temp = bin[k];
					bin[k] = bin[k+1];
					bin[k+1] = temp;
					p++;
				}
			}
			total += p;
			if(!p) break;
		}
		delete bin;
		cout << "Optimal train swapping takes " << total << " swaps." << endl;
	}
	return 0;
}
