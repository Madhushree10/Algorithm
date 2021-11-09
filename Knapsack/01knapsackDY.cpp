
// Dynamic programming method of 0-1 knapsack problem

#include <iostream>
#include <algorithm>
using namespace std;


int solve(int n, int vals[], int weights[], int S) {
	int memo[n+1][S+1];
	for (int i = 0; i <= S; ++i) memo[0][i] = 0;
	for(int i=1; i<=n; ++i) {
		for(int s=0; s <= S; ++s) {
			if(weights[i-1] > s)
				memo[i][s] = memo[i-1][s];
			else {
				memo[i][s] = max(memo[i-1][s], memo[i-1][s-weights[i-1]]+vals[i-1]);
			}
		}
	}
	return memo[n][S];
}

int main(int argc, char* argv[]) {
	int n; // the number of items
	cin >> n;
	int vals[n], weights[n];
	for(int i=0; i<n; ++i) {
		cin >> vals[i] >> weights[i];
	}
	int S; // the weight of the knapsack
	cin >> S;
	int max_amount = solve(n, vals, weights, S);
	cout << max_amount << endl;
	return 0;
}
