//20043 861
//Chapter 8: Little Bishops
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
#define For(i, a, b) for (LL i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

typedef long long LL;

using namespace std;

bool is_a_solution(LL a[], LL k, LL n, LL maxc) {
	return (k == maxc);
}

LL solution_count = 0;

void process_solution(LL a[], LL k) {
	solution_count++;
}

void construct_candidates(LL a[], LL k, LL n, LL c[], LL *ncandidates) {
	int i,j,p;
	bool legal_move;
	
	*ncandidates = 0;
	for(i=1; i<=n; i++) {
		legal_move = true;
		for(j=1; j<k; j++) {
			if(i == a[j]) legal_move = false;
		}
		if(legal_move) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
	
	//for(i=1; i<=n; i++) {
	//	legal_move = true;
	//	for(j=1; j<k; j++) {
	//		if(abs((k)-j) == abs(i-a[j]))
	//			legal_move = false;
	//	}
	//	if(legal_move == true) {
	//		c[*ncandidates] = i;
	//		*ncandidates = *ncandidates + 1;
	//	}
	//}
}

bool finished = false;	/* found all solutions yet? */

void backtrack(LL a[], LL k, LL input, LL maxc) {
	LL c[maxc]; /* candidates for next position */
	LL ncandidates; /* next position candidate count */
	LL i; /* counter */
	
	
	if (is_a_solution(a,k,input,maxc))
		process_solution(a,k);
	else {
		k = k+1;
		construct_candidates(a,k,input,c,&ncandidates);
		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			backtrack(a,k,input,maxc);
			if (finished) return; /* terminate early */
		}
	}
}

int main() {
	LL n, k;
	while((cin >> n >> k) && (n!=0 && k!=0)) {
		LL a[100] = {0};
		solution_count = 0;
		backtrack(a, 0, n, k);
		backtrack(a, 0, n, k);
		cout << solution_count << endl;
	}
	
	return 0;
}
