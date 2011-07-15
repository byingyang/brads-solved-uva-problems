//20043 10181
//Chapter 8: 15-Puzzle Problem
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

typedef vector<int> VI;
typedef vector< vector<int> > VVI;

struct snapshot {
	VVI puz;
	int zi;
	int zj;
};

typedef list<snapshot> LS;

char opposite(char command) {
	switch(command) {
		case 'U':
		return 'D';
		case 'D':
		return 'U';
		case 'L':
		return 'R';
		case 'R':
		default:
		return 'L';
	}
}

void Execute(VVI &puz, int &zi, int &zj, char command) {
	switch(command) {
		case 'U':
		puz[zi][zj] = puz[zi-1][zj];
		zi--;
		break;
		case 'D':
		puz[zi][zj] = puz[zi+1][zj];
		zi++;
		break;
		case 'L':
		puz[zi][zj] = puz[zi][zj-1];
		zj--;
		break;
		case 'R':
		puz[zi][zj] = puz[zi][zj+1];
		zj++;
		break;
	}
	puz[zi][zj] = 0;
}

bool is_a_solution(char a[], VVI &puz, int zi, int zj, int k) {
	int i = 1;
	For(i, 0, 4) {
		For(j, 1, 4) {
			if(puz[i][j] == 0)  {
				continue;
			}
			if(puz[i][j] != i) return false;
			i++;
		}
	}
	return true;
}

bool finished = false;

void process_solution(char a[], int k) {
	For(i, 0, k)
		cout << a[i];
	cout << endl;
	finished = true;
}

bool equal(VVI &a, VVI &b) {
	For(i, 0, 4) {
		For(j, 0, 4) {
			if(a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}

bool try_move(VVI &puz, LS &prev, int zi, int zj, char command) {
	bool valid = true;
	// try going up
	Execute(puz, zi, zj, command);
	// go back until the zero is in the same spot
	for(LS::iterator iter = prev.end(); iter != prev.begin(); --iter) {
		if((iter->zi == zi) && (iter->zj == zj)) {
			if(equal(puz, iter->puz)) {
				valid = false;
				break;
			}
		}
	}
	// undo
	Execute(puz, zi, zj, opposite(command));
	return valid;
}

int cycle(char vm[], VVI &puz, LS &prev, int zi, int zj) {
	int count = 0;
	if(zi > 0) {
		if(try_move(puz,prev,zi,zj,'U')) {
			vm[count] = 'U';
			count++;
		}
	}
	if(zi < 3) {
		if(try_move(puz,prev,zi,zj,'D')) {
			vm[count] = 'D';
			count++;
		}
	}
	if(zj > 0) {
		if(try_move(puz,prev,zi,zj,'L')) {
			vm[count] = 'L';
			count++;
		}
	}
	if(zj < 3) {
		if(try_move(puz,prev,zi,zj,'R')) {
			vm[count] = 'R';
			count++;
		}
	}
	return count;
}

void construct_candidates(VVI &puz, LS &prev, int k, int zi, int zj, char c[], int *ncandidates) {
	*ncandidates = cycle(c,puz,prev,zi,zj);
}

void backtrack(char a[], VVI puz, LS prev, int zi, int zj, int k) {
	char c[4]; /* candidates for next position */
	int ncandidates; /* next position candidate count */
	int i; /* counter */

	if (is_a_solution(a,puz,zi,zj,k)) {
		process_solution(a,k);
	}
	else {
		k++;
		construct_candidates(puz,prev,k,zi,zj,c,&ncandidates);
		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			Execute(puz, zi, zj, a[k]);
			snapshot s;
			s.puz = puz;
			s.zi = zi;
			s.zj = zj;
			prev.push_back(s);
			backtrack(a,puz,prev,zi,zj,k);
			Execute(puz, zi, zj, opposite(a[k]));
			if (finished) return; /* terminate early */
		}
	}
}

int main() {
	int n;
	cin >> n;
	For(i, 0, n) {
		VVI puz(4, VI(4));
		LS prev;
		int zi, zj;
		For(j, 0, 4) {
			For(k, 0, 4) {
				cin >> puz[j][k];
				if(puz[j][k] == 0) {
					zi = j;
					zj = k;
				}
			}
		}

		char a[100] = {0};
		backtrack(a, puz, prev, zi, zj, 0);
	}
	
	return 0;
}
