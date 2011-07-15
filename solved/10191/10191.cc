//20043 {{ProblemID}}
//Chapter: Problem Name 
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

struct Event {
	int s, f;
};

bool c(const Event a, const Event b) {
	return a.s < b.s;
}

int main() {
	int num = 0;
	int day = 1;
	while(cin >> num) {
		Event e[num+3];
		e[0].s = e[0].f = 600;
		e[num+1].s = e[num+1].f = 1080;
		string dummy;
		For(i, 1, num+1) {
			int h1,m1,h2,m2;
			scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
			getline(cin, dummy);
			e[i].s = h1 * 60 + m1;
			e[i].f = h2 * 60 + m2;
		}
		sort(e, e+num+2, c);
		int best_start = 0;
		int best_span = 0;
		For(i, 1, num+2) {
			int diff = e[i].s - e[i-1].f;
			if(diff > best_span) {
				best_span = diff;
				best_start = e[i-1].f;
			}
		}
		if (best_span < 60)
			printf ("Day #%d: the longest nap starts at %d:%.2d and will last for %d minutes.\n", day++, best_start / 60, best_start % 60, best_span);
		else
			printf ("Day #%d: the longest nap starts at %d:%.2d and will last for %d hours and %d minutes.\n", 
				day++, best_start / 60, best_start % 60, best_span / 60, best_span % 60);
	}
	return 0;
}
