//20043 10110
//Chapter 7: Light, more light
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
#define For(i, a, b) for (unsigned int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

int main() {
	unsigned int num;
	while(cin >> num && num != 0) {
		unsigned int check = floor(sqrt(num));
		if(check * check == num)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
