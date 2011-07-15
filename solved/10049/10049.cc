//20043 10049
//Chapter: Self Describing Sequence
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

using namespace std;

int numbers[700000];
int size = 0;

void gen_numbers() {
	int const max_number = 2000000000;
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 4;
	int i = 1;
	
	for(; numbers[ numbers[i] - 1 ] < max_number; ++i) {
		for(int j = numbers[i]; j < numbers[i + 1]; ++j) {
			numbers[j] = numbers[j - 1] + i + 1;
		}
	}
	size = numbers[i] - 1;
}

int main() {
	gen_numbers();
	for(int n; cin >> n && n != 0;) {
		cout << (upper_bound(numbers, numbers + size, n) - numbers) << endl;
	}
	return 0;
}
