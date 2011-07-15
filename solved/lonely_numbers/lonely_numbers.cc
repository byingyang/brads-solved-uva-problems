#include <iostream>

using namespace std;

bool Supported(unsigned int x) {
	if(x == 0 || x == 1)
		return false;
	int xCpy = x;
	do {
		int candidate = --xCpy;
		int count = 0;
		while(candidate) {
			count += candidate & 0x01;
			candidate >>= 1;
		}
		if(count + xCpy == x)
			return true;
	}
	// it has to be within 32 of the original number
	while((x - xCpy <= 32) && (xCpy > 1));
	return false;
}

int main() {
	unsigned int x;
	cin >> x;
	while(cin >> x)
		cout << (Supported(x) ? "SUPPORTED" : "LONELY") << endl;

	return 0;
}
