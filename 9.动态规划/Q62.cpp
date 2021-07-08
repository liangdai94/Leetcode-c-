#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
		memo[1][1] = 1;

		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				memo[i][j] = memo[i-1][j] + memo[i][j-1] + memo[i][j];
			}
		}

		return memo[m][n];
    }
};


int main(){
	Solution s;
	cout << s.uniquePaths(3, 7) << endl;
	return 0;
}
