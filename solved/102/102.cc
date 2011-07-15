#include <iostream>
#include <map>

using namespace std;

int main() {
	int a;
	char colors[] = {'B', 'G', 'C'};
	const char *possibilities[] = {"BGC", "BCG", "GBC", "GCB", "CGB", "CBG"};
	while(true) {
		map<const char, unsigned int> bins[3];
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(!(cin >> a))
					return 0;
				bins[i][colors[j]] = a;
			}
		}
		unsigned int minSum = -1;
		const char *str;
		for(int i = 0; i < 6; i++) {
			const char *possibility = possibilities[i];
			unsigned int sum = 0;
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k < 3; k++) {
					char c = possibility[k];
					if(c != possibility[j]) {
						sum += bins[j][c];
					}
				}
			}
			if((minSum == -1) || (sum < minSum) || ((sum == minSum) && string(possibility) < string(str))) {
				minSum = sum;
				str = possibility;
			}
		}
		cout << str << " " << minSum << endl;
	}
	return 0;
}