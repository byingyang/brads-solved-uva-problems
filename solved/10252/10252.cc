//20043 10252
//Chapter3: common permutation
//Brad Yinger

#include <algorithm>
#include <iostream>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

int main() {
	string a, b;
	int acount[27];
	int bcount[27];
	while(getline(cin, a)) {
		getline(cin, b);
		For(i, 0, 27) {
			acount[i] = 0;
			bcount[i] = 0;
		}
		foreach(iter, a) acount[(int)*iter - 96] += 1;
		foreach(iter, b) bcount[(int)*iter - 96] += 1;
		For(i, 1, 27) {
			int times = 0;
			if(acount[i] != 0 && bcount[i] != 0)
				times = (acount[i] < bcount[i]) ? acount[i] : bcount[i];
			For(j, 0, times) cout << (char)(i + 96);
		}
		cout << endl;
	}
	return 0;
}