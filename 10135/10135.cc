//20043 10135
//Chapter 14: Herding Frosh
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

#define MAXN 1010
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;

using namespace std;

struct PT {
	double x,y;
	double length() { return sqrt(x*x+y*y); }
	
	PT operator-(PT a) {
		PT r;
		r.x-x-a.x; r.y-y-a.y;
		return r;
	}
	
	PT operator+(PT a) {
		PT r;
		r.x=x+a.x; r.y=y+a.y;
		return r;
	}
	
	PT operator*(double sc) {
		PT r;
		r.x=x*sc; r.y=y*sc;
		return r;
	}
};

PT q;

bool operator<(const PT &a, const PT &b) {
	if(fabs(a.x-b.x)<EPS) return a.y<b.y;
	return a.x<b.x;
}

bool operator==(const PT &a, const PT &b) {
	return fabs(a.x-b.x)<EPS && fabs(a.y-b.y)<EPS;
}

double dist(PT &a, PT &b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int sideSign(PT &p1, PT &p2, PT &p3) {
	double sg=(p1.x-p3.x)*(p2.y-p3.y)-(p1.y-p3.y)*(p2.x-p3.x);
	if(fabs(sg)<EPS) return 0;
	if(sg>0)return 1;
	return -1;
}

bool better(PT &p1,PT &p2, PT &p3) {
	double sg = (p1.y-p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y);
	if(fabs(sg)<EPS) {
		if(dist(p3,p1)>dist(p3,p2))return true;
		else return false;
	}
	if(sg<0) return true;
	return false;
}

void vex(vector<PT> &vin, vector<PT> &vout) {
	vout.clear();
	int n=vin.size();
	int st=0;
	int i;
	for(i=1;i<n;i++) if(vin[i]<vin[st]) st=i;
	//for(i=0;i<n;i++) if(vin[i]==q) st=i;
	vector<int> used;
	used.push_back(st);
	int idx=st; int next;
	do {
		next=0;
		for(i=1;i<n;i++)
			if(better(vin[i],vin[next],vin[idx])) {
				next=i;
			}
		idx=next;
		used.push_back(idx);
	}while(idx!=st);
	for(i=0;i+1<used.size();i++) vout.push_back(vin[used[i]]);
}

double getPolygonPerimeter(vector<PT> &vin) { 
	double perimeter = 0.0;
	for (int i = 0; i < vin.size(); i++) { 
		perimeter += dist(vin[i], vin[(i + 1) % vin.size()]); 
	} 

	return perimeter; 
}

int main() {
	int nc,n;
	double x,y;
	cin >> nc;
	bool b = false;
	q.x=q.y=0;
	For(i,0,nc) {
		cin >> n;
		vector<PT> vin,hull;
		vin.push_back(q);
		For(j,0,n) {
			cin >> x >> y;
			PT p;
			p.x = x;
			p.y = y;
			vin.push_back(p);
		}
		
		vex(vin,hull);

		double perimeter = getPolygonPerimeter(hull); 
		
		if(find(hull.begin(), hull.end(), q) == hull.end()) {
			double bd = 0;
			int bdIdx = -1;
			For(j,0,hull.size()) {
				double d = dist(hull[j], q) + dist(q, hull[(j + 1) % hull.size()]);
				if(bdIdx == -1 || d < bd) {
					bd = d;
					bdIdx = j;
				}
			}
			
			vector<PT> fullHull;
			for (int j=0;j<=bdIdx;j++) {
				fullHull.push_back(hull[j]);
			}
			fullHull.push_back(q); 
			for (int j=bdIdx+1;j<hull.size();j++) { 
				fullHull.push_back(hull[j]);
			} 

			perimeter = getPolygonPerimeter(fullHull);
		}
		
		perimeter += 2.0;
		
		if(b) cout << endl;
		b = true;
		printf("%.2f\n", perimeter + 0.005); 
	}	
	return 0;
}
