#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class position {
public:
	int row;
	int col;
	
	position(int r, int c) {
		row = r;
		col = c;
	}
};

int main() {
	int rows = 0;
	int cols = 0;
	int startCol = 0;
	cin >> rows >> cols >> startCol;
	while(rows != 0) {
		string s;
		vector<string> vec;
		map<int, int> moves;
		position curPos(0, 0);
		int numMoves = 0;
		int numLoopMoves = -1;
		
		for(int i = 0; i < rows; i++) {
			cin >> s;
			vec.push_back(s);
		}
		
		curPos.col = startCol - 1;
		moves[10 * curPos.row + curPos.col - 1] = 1;
		
		while((curPos.row != -1) && (curPos.row < rows) && (curPos.col != -1) && (curPos.col) < cols) {
			char c = vec[curPos.row][curPos.col];
			switch(c) {
				case 'N':
				curPos.row--;
				break;
				case 'S':
				curPos.row++;
				break;
				case 'E':
				curPos.col++;
				break;
				case 'W':
				curPos.col--;
				break;
			}
			int index = 10 * curPos.row + curPos.col - 1;
			int n = moves[index];
			if(n != 0) {
				n--;
				numLoopMoves = numMoves + 1 - n;
				numMoves = n;
				break;
			}
			else {
				numMoves++;
				moves[index] = numMoves + 1;
			}
		}
		
		if(numLoopMoves != -1)
			cout << numMoves << " step(s) before a loop of " << numLoopMoves << " step(s)" << endl;
		else
			cout << numMoves << " step(s) to exit" << endl;
		
		cin >> rows >> cols >> startCol;
	}
    return 0;
}
