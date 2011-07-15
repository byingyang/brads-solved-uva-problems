//20043 {{ProblemID}}
//Chapter: Problem Name 
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

int main() {
	//int num = 11;
	//int cur_val = 15;
	//int divs[] = {2,3,5};
	//while(num != 1500) {
	//	cur_val++;
	//	int temp = cur_val;
	//	if(temp % 2 == 0 || temp % 3 == 0 || temp % 5 == 0)  {
	//		For(i, 0, 3) {
	//			while(temp % divs[i] == 0) temp /= divs[i];
	//		}
	//	}
	//	if(temp == 1) num++;
	//}
	//cout << "The 1500'th ugly number is " << cur_val << ".";
	cout << "The 1500'th ugly number is 859963392." << endl;
	return 0;
}
