#include <iostream>
#include <vector>

using namespace std;

unsigned int binary_encrypt(unsigned int num) {
	unsigned int count = 0;
	do {
		if(num & 0x01) {
			count++;
		}
	} while(num >>= 1);
	return count;
}

unsigned int hex_encrypt(unsigned int num) {
	unsigned int count = 0, dig;
	do {
		dig = num % 10;
		count += binary_encrypt(dig);
	} while(num /= 10);
	return count;
}

int main() {
	unsigned int n, num;
	cin >> n;
	vector<unsigned int> nums;
	while(cin >> num) {
		nums.push_back(num);
	}
	for(int i = 0; i < n; i++) {
		num = nums[i];
		cout << binary_encrypt(num) << " " << hex_encrypt(num) << endl;
	}
	return 0;
}
