//20043 10149
//Chapter: yahtzee 
//Brad Yinger

#include <algorithm>
#include <iostream>

using namespace std;

const int SLOTS = 13;
const int POSSIBILITIES = (1 << 13);
enum Category { ones,twos,threes,fours,fives,sixes,chance,three_kind,four_kind,five_kind,short_straight,long_straight,full_house };

// represents the highest possible score if categories 0..SLOTS 
//have been used with POSSIBILITIES turn indices
int memo[SLOTS][POSSIBILITIES];

int get_score(int move[], int cat) {
	int occurences[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int sum = 0;
	for(int i = 0; i < 5; i++) {
		occurences[move[i]]++;
		sum += move[i];
	}
	switch(cat) {
		case ones:
		case twos:
		case threes:
		case fours:
		case fives:
		case sixes:
			return occurences[cat+1] * (cat+1);
		case chance:
			return sum;
		case three_kind:
			for(int i = 1; i <= 6; i++) if(occurences[i] >= 3) return sum;
			return 0;
		case four_kind:
			for(int i = 1; i <= 6; i++) if(occurences[i] >= 4) return sum;
			return 0;
		case five_kind:
			for(int i = 1; i <= 6; i++) if(occurences[i] >= 5) return 50;
			return 0;
		case short_straight:
			for(int i = 1; i <= 3; i++)
				if(occurences[i] > 0 && occurences[i+1] > 0 && occurences[i+2] > 0 && occurences[i+3] > 0)
					return 25;
			return 0;
		case long_straight:
			for(int i = 1; i <= 2; i++)
				if(occurences[i] > 0 && occurences[i+1] > 0 && occurences[i+2] > 0 && occurences[i+3] > 0 && occurences[i+4] > 0)
					return 35;
			return 0;
		case full_house:
			for(int i = 1; i <= 6; i++)
				for(int j = 1; j <= 6; j++)
					if(occurences[i] == 2 && occurences[j] == 3)
						return 40;
			return 0;
	}
	return 0;
}

int process_move(int move[]) {
	
}

int turns[SLOTS][5];
int best_move[SLOTS][POSSIBILITIES];

/*
need to compute a table that notes used categories with which turns were used and yields the maximum score
takes (1 << 13) * 13 * 13 = 1.3M cycles which is not bad
*/
int main() {
	while(cin >> turns[0][0]) {
		// get data
		for(int i = 1; i < 5; i++) cin >> turns[0][i];
		for(int i = 1; i < SLOTS; i++)
			for(int j = 0; j < 5; j++) cin >> turns[i][j];
		
		// reset the memos
		for(int i = 0; i < SLOTS; i++)
			for(int j = 0; j < (1 << SLOTS); j++)
		    	memo[i][j] = best_move[i][j] = INT_MIN;
		
		// ones
		for(int i = 0; i < SLOTS; i++) {
			int m = 1 << i;
			memo[ones][m] = get_score(turns[i], ones);
			best_move[ones][m] = i;
		}
		
		// everything else
		for(int i = twos; i <= full_house; i++) {
			for(int j = 0; j < POSSIBILITIES; j++) {
				// the turns used should equal the slots used
				if(__builtin_popcount(j) != i+1) continue;
				// find the slot that yields the largest score with respect to previous turns
				for(int k = 0; k < SLOTS; k++) {
					// get the score that occurred without using this slot
					int oldTotal = memo[i-1][j & ~(1 << k)];
					int newTotal = oldTotal + get_score(turns[k], i);
					if(newTotal > memo[i][j]) {
						memo[i][j] = newTotal;
						best_move[i][j] = k;
					}
					// bonus = +35
					if(i == sixes && memo[i][j] >= 63)
			        	memo[i][j] += 35;
				}
			}
		}
		
		// make a list of all the best moves to take
		int moves[SLOTS];
		// this gives us all moves left (1111111111111)
		int m = (1 << SLOTS) - 1;
		for(int i = SLOTS - 1; i >= 0; i--) {
			int best = best_move[i][m];
			moves[i] = best;
			// kill that move from the "list" of moves
			m = m & ~(1 << best);
		}
		// "play the game"
		int sum = 0;
		int bonus = 0;
		for(int i = ones; i <= full_house; i++) {
			int score = get_score(turns[moves[i]], i);
			cout << score << " ";
			sum += score;
			// bonus = +35
			if(i == sixes && sum >= 63) {
				bonus = 35;
				sum += bonus;
			}
		}
		cout << bonus << " " << sum << endl;
	}
	
	return 0;
}
