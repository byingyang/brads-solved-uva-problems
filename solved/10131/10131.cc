//20043 10131
//Chapter 11: Is Bigger Smarter?
//Brad Yinger

#include <iostream>
#include <stack>
#include <algorithm>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

#define MAXELEPHANTS 1005

struct elephant {
	int iq;
	int wt;
	int n;
};

bool compare(elephant a, elephant b) {
	return (a.iq >= b.iq);
}

elephant e[MAXELEPHANTS];

int memo[MAXELEPHANTS];
int parent[MAXELEPHANTS];

int main() {
	For(i, 0, MAXELEPHANTS) {
		memo[i] = 1;
		parent[i] = -1;
	}
	int num = 0;
	while(cin >> e[num].wt) {
		cin >> e[num].iq;
		e[num].n = num+1;
		num++;
	}
	
	// sort by iq asc
	sort(e, e + num, compare);
	
	// now we know that iq is in the correct order, so just check weight
	For(i, 1, num) {
		For(j, 0, i) {
			if(e[j].wt < e[i].wt && memo[i] < memo[j] + 1) {
				memo[i] = memo[j] + 1;
				parent[i] = j;
			}
		}
	}
	
	int max = 0;
	int maxIdx = -1;
	For(i, 0, num) {
		if(memo[i] > max) {
			max = memo[i];
			maxIdx = i;
		}
	}
	
	// roll em up in order
	stack<elephant> elStack;
	while(maxIdx != -1) {
		elStack.push(e[maxIdx]);
		maxIdx = parent[maxIdx];
	}
	
	cout << elStack.size() << endl;
	while(!elStack.empty()) {
		elephant e = elStack.top();
		elStack.pop();
		cout << e.n << endl;
	}
	
	return 0;
}
