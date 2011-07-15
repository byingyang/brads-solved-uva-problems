#include <iostream>
#include <string>

using namespace std;

int main() {
	char c;
	bool b = false;
	c = getchar();
	while(c != EOF) {
		if(c == '"') {
			cout << (b ? "''" : "``");
			b = !b;
		}
		else {
			cout << c;
		}
		c = getchar();
	}
	
	return 0;
}