#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector< int > VI;
typedef vector< VI > VVI;

bool is_possible(const VVI& puz) {
    int n_inverse = 0;
    int zero_index;

    for (int k = 0; k < 16; k++) {
		if(puz[k/4][k%4] == 0) {
			zero_index = k;
			continue;
		}
		
        for (int p = k + 1; p < 16; p++) {
            if (puz[p/4][p%4] == 0 && puz[p/4][p%4] < puz[k/4][k%4]) {
                n_inverse++;
            }
        }
    }

    n_inverse += zero_index / 4 + 1;

    if (n_inverse % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

void backtrack(const VVI& puz, const VVI& cmp) {
    if (!is_possible(puz)) {
		cout << "This puzzle is not solvable." << endl;
		return;
	}
	
    pair<VVI, string> start;
    start.first = puz;
    start.second = "";

    set<VVI> s;
    s.insert(puz);
    queue< pair<VVI, string> > q;
    q.push(start);

    while (!q.empty()) {
		pair<VVI, string> x = q.front();
		q.pop();

		if (x.first == cmp) {
			cout << x.second << endl;
			return;
		}

		int i = 0;
		int j = 0;
		// find the spot where the 0 is
		for(int k = 0; k < 16; k++) {
			if (x.first[k/4][k%4] == 0) {
				i = k/4;
				j = k%4;
				break;
			}
		}
		pair<VVI, string> next;
		if (i > 0) {
		    next = x;
		    swap(next.first[i][j], next.first[i-1][j]);
		    if (s.find(next.first) == s.end()) {
				s.insert(next.first);
				next.second += "U";
				q.push(next);
			}
		}
		if (i < 3) {
		    next = x;
		    swap(next.first[i][j], next.first[i+1][j]);
		    if (s.find(next.first) == s.end()) {
				s.insert(next.first);
				next.second += "D";
				q.push(next);
			}
		}
		if (j > 0) {
		    next = x;
		    swap(next.first[i][j], next.first[i][j-1]);
		    if (s.find(next.first) == s.end()) {
				s.insert(next.first);
				next.second += "L";
				q.push(next);
			}
		}
		if (j < 3) {
		    next = x;
		    swap(next.first[i][j], next.first[i][j+1]);
		    if (s.find(next.first) == s.end()) {
				s.insert(next.first);
				next.second += "R";
				q.push(next);
			}
		}
    }
}

int main() {
    int n;
    cin >> n;
    VVI cmp(4, VI(4));
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cmp[i][j] = 4*i+j+1;
		}
	}
	
    cmp[3][3] = 0;
    VVI puz(4, VI(4));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				cin >> puz[j][k];
			}
		}
		backtrack(puz, cmp);
	}
}
