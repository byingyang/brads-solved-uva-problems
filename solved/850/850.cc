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

bool cipher_match(string &a, string &b) {
	int alen = a.size();
	int blen = b.size();
	if(alen != blen) return false;
	For(i, 0, alen) {
		char c = a[i];
		char bc = b[i];
		For(j, i+1, alen) {
			if (c == ' ' && bc != ' ') return false;
			if(bc == b[j] && a[j] != c) return false;
		}
	}
	return true;
}

int main() {
	int num_cases;
	cin >> num_cases;
	cin.ignore(2048, '\n').ignore(2048, '\n');
	string str;
	string known = "the quick brown fox jumps over the lazy dog";
	For(i, 0, num_cases) {
		vector<string> data;
		void *result = (void *)getline(cin, str);
		if(result && str.size() == 0) {
			cout << "No solution." << endl;
		}
		else {
			map<char, char> m;
			bool found = false;
			while(result && str.size() > 0) {
				data.push_back(str);
				// !found   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! XD
				if(!found && cipher_match(known, str)) {
					found = true;
					For(k, 0, known.size()) m[str[k]] = known[k];
				}
				result = getline(cin, str);
			}
			if((data.size() == 0) || !found) {
				cout << "No solution." << endl;
			}
			else {
				foreach(iter, data) {
					foreach(c, *iter) {
						if(*c == ' ')
							cout << ' ';
						else
							cout << m[*c];
					}
					cout << endl;
				}
			}
		}
		if(i < num_cases - 1)
			cout << endl;
	}
	return 0;
}