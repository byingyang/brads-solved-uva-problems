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

int g[105][105];

void setup(int v) {
	For(i,1,v+1) {
		For(j,1,v+1) {
			g[i][j] = INT_MIN;
		}
		g[i][i] = 0;
	}
}

void read_graph(int v, int e) {
	For(i,1,e+1) {
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		g[a][b] = g[b][a] = w-1;
	}
}

int c = 0;
int main() {
	int v, e;
	while((cin >> v >> e) && (v && e)) {
		setup(v);
		read_graph(v,e);
		int s,d,t;
		scanf("%d %d %d",&s,&d,&t);
		cout << "Scenario #" << (++c) << endl;
		if (s == d) {
			cout << "Minimum Number of Trips = 1" << endl << endl;
        }
		else {
			For(k,1,v+1) {
				For(i,1,v+1) {
					if(g[i][k] != INT_MIN) {
						For(j,1,v+1) {
							if(g[k][j] != INT_MIN && i != j)
								g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
						}
					}
				}
			}
			int tpt = t / g[s][d];
			if(tpt * g[s][d] < t) tpt++;
			cout << "Minimum Number of Trips = " << tpt << endl << endl;
		}
	}
	return 0;
}
