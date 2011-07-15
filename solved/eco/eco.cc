#include <iostream>

using namespace std;

class farmer {
public:
	unsigned int animal_count;
	unsigned int eco_friendliness;
	unsigned int farm_space;
	farmer(unsigned int a_cnt, unsigned int eco_fr, unsigned int farm_sp) : animal_count(a_cnt), eco_friendliness(eco_fr), farm_space(farm_sp) {
		
	}
	
	float value() {
		float animal_avg = (float)farm_space / animal_count;
		float value_per_animal = animal_avg * eco_friendliness;
		return value_per_animal * animal_count;
	}
};

int main() {
	int n;
	cin >> n;
	while(cin >> n) {
		float sum = 0;
		for(int i = 0; i < n; i++) {
			unsigned int size;
			unsigned int count;
			unsigned int eco;
			cin >> size;
			cin >> count;
			cin >> eco;
			farmer f(count, eco, size);
			sum += f.value();
		}
		cout << (unsigned int)sum << endl;
	}
	return 0;
}