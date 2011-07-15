//20043 10035
//Chapter 5: Primary Arithmetic
//Brad Yinger
#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	while(cin >> a) {
		cin >> b;
		if(a == "0" && b == "0")
			return 0;
		int carries = 0;
		int carry = 0;
		bool adone = false, bdone = false;
		for(string::reverse_iterator it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend() || it2 != b.rend(); it1 += (adone ? 0 : 1), it2 += (bdone ? 0 : 1)) {
			if(it1 == a.rend())
				adone = true;
			if(it2 == b.rend())
				bdone = true;
			int first = 0;
			if(!adone)
				first = *it1 - (int)('0');
			int second = 0;
			if(!bdone)
				second = *it2 - (int)('0');
			int sum = carry + first + second;
			carry = ((sum > 9) ? 1 : 0);
			carries += carry;
		}
		
		if(!carries)
			cout << "No";
		else
			cout << carries;
		cout << " carry ";
		if(!carries || carries == 1)
			cout << "operation.";
		else
			cout << "operations.";
		cout << endl;
		
	}
	
	return 0;
}