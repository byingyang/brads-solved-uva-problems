//20043 10082
//Chapter: WERTYU 
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

char arr[47] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	int c;
	while((c = getchar()) != EOF) {
		if(c == '\n' || c == '\r') {
			cout << endl;
			continue;
		}
		if(c == (int)' ') {
			cout << ' ';
			continue;
		}
		For(i, 0, 46) {
			if(arr[i] == c) {
				char newc = arr[i-1];
				cout << newc;
				break;
			}
		}
	}
	return 0;
}