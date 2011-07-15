//20043 846
//Chapter: Steps
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

int stepsEven(int val) {
	return floor((-2 + sqrt(4+16*val))/2);
}

int stepsOdd(int val) {
	return floor(2*(sqrt(val)-1)+1);
}

int maxvalEven(int steps) {
	steps = steps / 2;
	return steps*(steps+1);
}

int maxvalOdd(int steps) {
	return pow(((steps-1)/2.0+1),2);
}

int maxval(int steps) {
	return steps % 2 == 0 ? maxvalEven(steps) : maxvalOdd(steps);
}

int main() {
	int from, to, val;
	cin >> to;
	while(cin >> from) {
		cin >> to;
		val = to - from;
		//D(val);
		if(val == 0) {
			cout << "0" << endl;
			continue;
		}
		int steps = stepsEven(val);
		//D(steps);
		//cout << (maxval(steps-1)) << endl;
		if(val <= maxval(steps-1)) {
			steps -= 1;
		}
		else if(val > maxval(steps)) {
			steps++;
		}
		cout << steps << endl;
	}
	return 0;
}
