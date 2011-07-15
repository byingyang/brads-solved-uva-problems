#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		int last, next;
		bool jolly = true;
		bool found[n+2];
		memset(found, 0, n+2);
		cin >> last;
		for(int i = 0; i < n - 1; i++) {
			cin >> next;
			if(!jolly)
				continue;
			int val = abs(next - last);
			if(val >= n || val == 0 || found[val]) {
				jolly = false;
			}
			found[val] = true;
			last = next;
		}
		cout << (jolly ? "Jolly" : "Not jolly") << endl;
	}
	return 0;
}