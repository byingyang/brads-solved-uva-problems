//20043 701
//Chapter 5: The Archeologists' Dilemma
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
	long double num = 0;
	const long double logtenbasetwo = log2l(10);
	while(cin >> num) {
		long double num_absent_digits = ceill(log10l(num+0.1))+1;
		long double lbound = log2l(num);
		long double ubound = log2l(num+1);
		long double add;
		while(1) {
			add = num_absent_digits * logtenbasetwo;
			if(ceill(lbound + add) == floorl(ubound + add)) break;
			num_absent_digits++;
		}
		// you can't know that there is not a satisfactory value
		cout << (ceill(lbound + add)) << endl;
	}
	return 0;
}
