//20043 10189
//Chapter 1: Minesweeper
//Brad Yinger

#include <iostream>
#include <string>

using namespace std;

#define N 105

int main() {
	int rows = 0, cols = 0;
	int field[N][N];
	int numFields = 0;
	while(cin >> rows) {
		cin >> cols;
		if(rows == 0 && cols == 0) return 0;
		// memset(field, 0, N * N) does not work for some reason!!!! stupid!
		for(int i = 0; i < 100; i++) {
			for(int j = 0; j < 100; j++) {
				field[i][j] = 0;
			}
		}
		
		if(numFields != 0) {
			cout << endl;
		}
		
		// input
		for(int i = 0; i < rows; i++) {
			string str;
			cin >> str;
			for(int j = 0; j < cols; j++) {
				if(str[j] == '*') {
					field[i][j] = -1;
					for(int p = i - 1; p <= i + 1; p++) {
						for(int k = j - 1; k <= j + 1; k++) {
							if(p >= 0 && p < rows && k >= 0 && k < cols && field[p][k] != -1) {
								field[p][k]++;
							}
						}
					}
				}
			}
		}
		
		cout << "Field #" << ++numFields << ":" << endl;
		
		// output
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				int c = field[i][j];
				if(c == -1) {
					// mine
					putchar('*');
				}
				else {
					putchar((char)(c + '0'));
				}
			}
			cout << endl;
		}
	}
	return 0;
}
