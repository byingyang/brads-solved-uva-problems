//20043 10154
//Chapter: Weights and Measures 
//Brad Yinger

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

#ifndef MAXTURTLES
#define MAXTURTLES 6000
#endif

#define INF 10000000 

struct turtle {
	int strength;
	int weight;
	int carry;
	} t[MAXTURTLES];

bool compare(turtle a, turtle b) {
	return (a.carry < b.carry);
}

int memo[MAXTURTLES][MAXTURTLES]; // starting with i and i've used j

int do_stack(int n) {
	for(int i = 0; i <= n; i++) 
		for(int j = 0; j <= n; j++) 
			memo[i][j] = INF; 
	for(int i = 0; i <= n; i++)
		memo[i][0] = 0;		
		
	For(i, 1, n+1) {
		For(j, 1, i+1) {
			memo[i][j] = min(memo[i][j], memo[i-1][j]);
			if(memo[i-1][j-1] <= t[i].carry) {
				memo[i][j] = min(memo[i][j], memo[i-1][j-1] + t[i].weight);
			}
		}
	}
}

int main() {
	int n = 0;
	while(cin >> t[n+1].weight) {
		n++;
		cin >> t[n].strength;
		t[n].carry = t[n].strength - t[n].weight;
	}
	
	sort(t+1, t+n+1, compare);
	do_stack(n);
	for(int i = n; i >= 1; i--) {
		if(memo[n][i] < INF) {
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
