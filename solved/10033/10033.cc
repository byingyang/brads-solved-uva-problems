//20043 10033
//Chapter 1: Interpreter
//Brad Yinger

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> commands;
int ct = 0;
int ip = 0;
int reg[12];

void ex() {
	ct++;
	
	int a = commands[ip] / 100;
	int b = (commands[ip] % 100) / 10;
	int c = commands[ip] % 10;
	
	if(a == 1) return;
	// 0ds means goto the location in register d unless register s contains 0
	if(a == 0 && reg[c] != 0) {
		ip = reg[b] - 1;
	}
	//2dn means set register d to n (between 0 and 9)
	else if(a == 2) {
		reg[b] = c % 1000;
	}
	//3dn means add n to register d
	else if(a == 3) {
		reg[b] += c;
		reg[b] = reg[b] % 1000;
	}
	//4dn means multiply register d by n
	else if(a == 4) {
		reg[b] *= c;
		reg[b] = reg[b] % 1000;
	}
	//5ds means set register d to the value of register s
	else if(a == 5) {
		reg[b] = reg[c] % 1000;
	}
	//6ds means add the value of register s to register d
	else if(a == 6) {
		reg[b] += reg[c];
		reg[b] = reg[b] % 1000;
	}
	//7ds means multiply register d by the value of register s
	else if(a == 7) {
		reg[b] *= reg[c];
		reg[b] = reg[b] % 1000;
	}
	//8da means set register d to the value in RAM whose address is in register a
	else if(a == 8) {
		stringstream ss (stringstream::in | stringstream::out);
		reg[b] = commands[reg[c]];
	}
	//9sa means set the value in RAM whose address is in register a to the value of register s
	else if(a == 9) {
		stringstream ss (stringstream::in | stringstream::out);
		commands[reg[c]] = reg[b];
	}
	ip++;
	ex();
}

int main() {
	int num;
	cin >> num;
	char instr[5];
	fgets(instr, sizeof(instr), stdin);
	fgets(instr, sizeof(instr), stdin);
	for(int i = 0; i < num; i++) {
		ct = 0;
		ip = 0;
		for(int j = 0; j < 12; j++) reg[j] = 0;
		commands.clear();
		
		if (i != 0) {
			cout << endl;
		}
		
		while(fgets(instr, sizeof(instr), stdin) != NULL) {
			if (instr[0] == '\n') break;
			commands.push_back((instr[0] - '0') * 100 + (instr[1] - '0') * 10 + (instr[2] - '0'));
		}
		ex();
		cout << ct << endl;
	}
	
	return 0;
}