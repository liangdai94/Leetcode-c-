#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;
//记忆化搜索
class Solution {
private:
	vector<vector<int>> memo;
	int helper(vector<vector<int>>& grid, int i, int j, int sum){
		if(i == grid.size() - 1 && j == grid[0].size() - 1){
			
			return sum;
		}

		
		if(memo[i][j] == INT_MAX)
			if(i + 1 < grid.size() && j + 1 < grid[0].size()){
				memo[i][j] = min(helper(grid, i + 1, j , sum + grid[i+1][j]), helper(grid, i, j+1, sum + grid[i][j+1]));
			}
			else if(i + 1 < grid.size() && j + 1 >= grid[0].size()){
				memo[i][j] = helper(grid, i + 1, j , sum + grid[i+1][j]);
			}
			else if(i + 1 >= grid.size() && j + 1 < grid[0].size()){
				memo[i][j] = helper(grid, i , j+1, sum + grid[i][j+1]);
			}

		return memo[i][j];
	}
public:
    int minPathSum(vector<vector<int>>& grid) {
    	memo = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INT_MAX));

		return helper(grid, 0, 0, grid[0][0]);
    }
};

/*动态规划
int minPathSum(vector<vector<int>>& grid){
	auto memo = grid;

	for(int i = 1; i < memo[0].size(); i++){
		memo[0][i] += memo[0][i-1];
	}

	for(int i = 1; i < memo.size(); i++){
		memo[i][0] += memo[i-1][0];
		for(int j = 1; j < grid[0].size(); j++){
			memo[i][j] += min(memo[i-1][j], memo[i][j-1]);
		}
	}

	return memo[grid.size() - 1][grid[0].size() - 1];
}
*/

int main(){
	vector<vector<int>> arr{{1,3,1}, {1,5,1},{4,2,1}};

	Solution s;
	cout <<s.minPathSum(arr) << endl;

	cout << minPath(arr) << endl;
	return 0;
}
