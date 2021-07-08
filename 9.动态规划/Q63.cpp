#include<iostream>
#include<vector>
//#include<array>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid[0][0] == 1)return 0;
		vector<vector<int>> memo(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));
		int i, j;
		for(i = 0; i < obstacleGrid.size(); i++){
			for(j = 0; j < obstacleGrid[0].size(); j++){
				if(obstacleGrid[i][j] == 1){
					memo[i+1][j+1] = -1;
				}
			}
		}
		memo[1][1] = 1;
		for(i = 1; i < memo.size(); i++){
			for(j = 1; j < memo[0].size(); j++){
				if(memo[i][j] == -1){
					memo[i][j] = 0;
					continue;
				}
				memo[i][j] = memo[i-1][j] + memo[i][j-1] + memo[i][j];
			}
		}

		return memo[i-1][j-1];
    }
};

int main(){

	Solution s;
	vector<vector<int>> tmp{{0,0,0},{0,1,0},{0,0,0}};

	cout << s.uniquePathsWithObstacles(tmp) << endl;
	return 0;
}
