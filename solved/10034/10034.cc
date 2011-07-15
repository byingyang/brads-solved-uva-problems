//20043 10034
//Chapter 10: freckles
//Brad Yinger

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

#define MAXV 105
#define MAXDEGREE 105

double prim(double graph[][MAXV], int n, int start) {
    int visited[n], parent[n];
    double d[n], min, minWeight;
    int u, v;

    for (int i = 0; i < n; i++) {
                d[i] = graph[start][i];
                visited[i] = 0;
                parent[i] = start;
        }

    visited[start] = 1;
        minWeight = 0;
        for (int i = 0; i < n-1; i++)
        {
                min = 999;
                for (int j = 0; j < n; j++)
                {
                        if (!visited[j] && d[j] < min)
                        {
                                min = d[j];
                                u = j;
                        }
                }
                visited[u] = 1;
                minWeight = minWeight + d[u]; //graph[i][u];
                for (v = 0; v < n; v++)
                        if (!visited[v] && (graph[u][v] < d[v]))
                        {
                                d[v] = graph[u][v];
                                parent[v] = u;
                        }
        }
    return minWeight;
}

int n;
double g[MAXV][MAXDEGREE];

int main() {
	int numCases;
	bool cr = false;
	cin >> numCases;
	For(p,0,numCases) {
		cin >> n;
		vector<pair<double,double> > v;
		For(i,0,n) {
			double x,y;
			cin >> x >> y;
			v.push_back(pair<double,double>(x,y));
		}
		
		For(i,0,n) {
			For(j,i,n) {
				if(i==j) continue;
				double d = sqrt ((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
				g[i][j] = g[j][i] = d;
			}
		}
		double result = prim(g,n,1);
		if(cr) cout << endl;
		cr = true;
		printf ("%.2lf\n", result);
	}
	return 0;
}
