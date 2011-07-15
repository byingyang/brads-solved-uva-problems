#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string s;
	cin >> s;
	while(cin >> s) {
		int numIterations = 0;
		string rev;
		string res;
		do {
			string cpy(s);
			reverse(cpy.begin(), cpy.end());
			unsigned int a = 0;
			unsigned int b = 0;
			stringstream ss(stringstream::in | stringstream::out);
			ss << s;
			ss >> a;
			stringstream ss2(stringstream::in | stringstream::out);
			ss2 << cpy;
			ss2 >> b;
			unsigned int result = a + b;
			stringstream ss3(stringstream::in | stringstream::out);
			ss3 << result;
			ss3 >> res;
			rev = string(res);
			reverse(rev.begin(), rev.end());
			numIterations++;
			s = res;
		} while(res != rev);
		cout << numIterations << " " << res << endl;
	}
	return 0;
}