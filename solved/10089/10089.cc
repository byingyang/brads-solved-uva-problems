//20043 10089
//Chapter 7: Repackaging
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

const double EPS = 1e-9;

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

struct PT {
	long long x;
	long long y;
};

long long pts[1000][3];

long long check(int x,int y) {
	long long x1=pts[x][0]-pts[x][1],x2=pts[x][0]-pts[x][2];
	long long y1=pts[y][0]-pts[y][1],y2=pts[y][0]-pts[y][2];
	if(x1*y2>x2*y1)
		return 1;
	if(x1*y2<x2*y1)
		return -1;
	if(x2*y2<0||x1*y1<0||(!x1&&!x2)||(!y1&&!y2))
		return 0;
	return 2;
}

bool inside(int n) {
	int i1=0,i2=0;
	for(int i=1;i<n;i++){
		if(check(0,i)==-1&&check(i1,i)==-1)
			i1=i;
		if(check(0,i)==1&&check(i2,i)==1)
			i2=i;
		if(check(i1,i2)*check(i1,0)==-1&&check(i2,i1)*check(i2,0)==-1
		||check(i1,i2)*check(i1,0)==0||check(i2,i1)*check(i2,0)==0)
			return true;
	}
	return false;
}

int main() {
	int n;
	while((cin >> n) && n) {
		For(i, 0, n)  {
			cin >> pts[i][0] >> pts[i][1] >> pts[i][2];
		}
		cout << (inside(n) ? "Yes" : "No") << endl;
	}
	return 0;
}


