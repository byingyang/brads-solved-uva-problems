//20043 {120
//Chapter 4: Stacks of Flapjacks
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

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

void flip(list<int> &L, list<int>::iterator start, list<int>::iterator end) {
	stack<int> s;
	while(start != end) {
		int elem = *start;
		L.erase(start++);
		s.push(elem);
	}
	while(!s.empty()) {
		L.insert(end, s.top());
		s.pop();
	}
}

int main() {
	string str;
	while(!cin.eof()) {
		getline(cin, str);
		if(str == "" || cin.eof()) break;
		cout << str << endl;
		list<int> items;
		stringstream ss;
		ss << str;
		int val = 0;
		while(ss >> val)
			items.push_back(val);
		
		int sorted = 0;
		
		while(!items.empty()) {
			list<int>::iterator max_pos = items.begin();
			int max_item = -1;
			int max_pos_num = 0;
			int i = 0;
			foreach(x, items) {
				if(*x > max_item) {
					max_item = *x;
					max_pos = x;
					max_pos_num = i;
				}
				i++;
			}
			
			// not already in order
			if(max_pos_num != items.size()-1) {
				if(max_pos != items.begin()) {
					// put it to the head
					list<int>::iterator temp = max_pos;
					temp++;
					flip(items, items.begin(), temp);
					cout << ((items.size() - max_pos_num) + sorted) << " ";
				}
				// flip it back to the tail
				flip(items, items.begin(), items.end());
				cout << (1 + sorted) << " ";
			}
			
			sorted++;
			items.pop_back();
			//cout << endl;
			//foreach(x, items) cout << *x << " ";
			//cout << endl;
		}
		cout << "0" << endl;
	}
	return 0;
}
