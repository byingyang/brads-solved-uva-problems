#include <iostream>

using namespace std;

struct entry {
	unsigned int i;
	unsigned int j;
	unsigned int val;
};

#define N 1000000

unsigned int cache[N];

unsigned int cycle_len(unsigned int i) {
	if(i <= 0)
        return 0;
	if(i >= N) {
		unsigned int temp = 0;
      while(i >= N) {
      	if(i % 2)
				i = 3 * i + 1;
         else
            i >>= 1;
         temp++;
      }  
      return cycle_len(i) + temp;
	}
	else {
		if(!cache[i]) {
			if(i % 2) {
				cache[i] = cycle_len(3 * i + 1) + 1;
			}
			else {
				cache[i] = cycle_len(i >> 1) + 1;
			}
		}
	}
	
	return cache[i];
}

int main() {
	cache[1] = 1;
	unsigned int i = 0;
	while(cin >> i) {
		entry e;
		e.i = i;
		cin >> e.j;
		unsigned int small = 0;
		unsigned int big = 0;
		if(e.i > e.j) {
			small = e.j;
			big = e.i;
		}
		else {
			small = e.i;
			big = e.j;
		}
		e.val = 0;
		for(unsigned int i = small; i <= big; i++) {
			if(!cache[i]) {
				cycle_len(i);
			}
			if(cache[i] > e.val) {
				e.val = cache[i];
			}
		}
		
		cout << e.i << " " << e.j << " " << e.val << endl;
	}
	return 0;
}
