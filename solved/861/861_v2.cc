//20043 10181
//Chapter 8: Little Bishops
//Brad Yinger

#include <iostream> 
#include <algorithm>
#include <cstdio>
 
using namespace std; 

typedef long long LL;

const int MAX = 100;

void setup(LL n, LL whites[MAX], LL blacks[MAX]) { 
	memset(whites, 0, MAX * sizeof(LL));
	memset(blacks, 0, MAX * sizeof(LL));
    for(LL i = 1; i <= n; i++) { 
    	for(LL j = 1 ; j <= n; j++) { 
             if((i + j) & 1) blacks[(i + j) / 2 ]++; 
             else whites[(i + j) / 2]++; 
		} 
	} 
} 

void go(LL n, LL memo[MAX][MAX], LL c[MAX]) { 
     for(int i = 0; i <= n; i++) 
		memo[i][0] = 1;
     for(int i = 1; i <= n; i++) 
         for(LL j = 1; j <= c[i]; j++) 
			memo[i][j] = memo[i - 1][j] + memo[i - 1][j - 1 ] * (c[i] - j + 1); 
} 

int main() { 
	LL n, k, val;
	LL whites[MAX], blacks[MAX], memo1[MAX][MAX], memo2[MAX][MAX]; 

     while((cin >> n >> k) && !(n==0 && k==0)) { 
		setup(n, whites, blacks); 
		sort(whites+1 , whites+n+1); 
		sort(blacks+1, blacks+n); 
		memset(memo1, 0, sizeof(memo1)); 
		memset(memo2, 0, sizeof(memo2));
		go(n, memo1, whites); 
		go(n - 1, memo2, blacks); 
		val = 0;
        for(LL i = 0; i <= k; i++) 
			val += memo1[n][i] * memo2[n - 1][k - i]; 
		cout << val << endl;
	}
    return 0; 
}
