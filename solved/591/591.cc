//20043 {{ProblemID}}
//Chapter: Problem Name 
//Brad Yinger

#include <iostream>
#include <vector>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

int main() {
	unsigned int nstacks = 0, setcount = 1;
	while(cin >> nstacks && nstacks) {
		cout << "Set #" << setcount++ << endl;
		vector<unsigned int> nums;
		unsigned int sum = 0;
		For(i, 0, nstacks) {
			unsigned int t;
			cin >> t;
			sum += t;
			nums.push_back(t);
		}
		unsigned int val = sum / nstacks;
		unsigned int nummoves = 0;
		For(i, 0, nstacks) {
			if(nums[i] > val) {
				nummoves += nums[i] - val;
			}
		}
		cout << "The minimum number of moves is " << nummoves << "." << endl << endl;
	}
	return 0;
}
