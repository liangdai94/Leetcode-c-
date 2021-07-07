//记忆化搜索
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution{
private:
	vector<vector<int>> memo;
	int helper(vector<vector<int>>& triangle, int i, int j){
		if(i == triangle.size() - 1){
			memo[i][j] = triangle[i][j];
			return triangle[i][j];
		}
		if(memo[i][j] == INT_MAX){
			memo[i][j] = min(helper(triangle, i + 1, j), helper(triangle, i + 1, j + 1)) + triangle[i][j];
		}

		return memo[i][j];
	}
public:
	int minimumTotal(vector<vector<int>>& triangle){
		memo = triangle;
		for(auto &it  : memo){
			for(auto &it1 : it){
				it1 = INT_MAX;
			}
		}
		return helper(triangle, 0, 0);
	}
};

int main(){
	vector<vector<int>> arr{{2}, {3,4},{6,5,7},{4,1,8,3}};

	Solution s;
	cout <<s.minimumTotal(arr) << endl;
	return 0;
}
