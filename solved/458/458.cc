#include <iostream>

using namespace std;

int main() {
	char c = getchar();
	while(c != EOF) {
		cout << ((c == '\n') ? c : (char)((int)c - 7));
		c = getchar();
	}
	return 0;
}