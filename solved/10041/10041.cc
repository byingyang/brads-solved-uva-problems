//20043 10041
//Chapter 3: Vito's Family 
//Brad Yinger

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <numeric>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

int main() {
	int num;
	cin >> num;
	while(cin >> num) {
		int addr = 0;
		vector<int> addresses;
		For(i, 0, num) {
			cin >> addr;
			addresses.push_back(addr);
		}
		sort(addresses.begin(), addresses.end());
		int val = addresses[num / 2];
		if(num % 2 == 0) {
			val = (val + addresses[num / 2 - 1]) / 2;
		}
		int sum = 0;
		For(i, 0, num) {
			sum += abs(addresses[i] - val);
		}
		cout << sum << endl;
	}
	return 0;
}
