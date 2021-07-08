//记忆化搜索
#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	vector<int> memo;
	int helper(vector<int>& nums, int index){
		if(index >= nums.size()){
			return 0;
		}
		else if(index == nums.size() - 1){
			memo[nums.size() - 1] = nums[nums.size() - 1];
			return nums[nums.size() - 1];
		}
		
		if(memo[index] == -1)
			memo[index] = max(helper(nums, index + 2) + nums[index], helper(nums, index + 1));
		return memo[index];
	}
public:
    int rob(vector<int>& nums) {
		memo = vector<int>(nums.size(), -1);
		helper(nums, 0);
		return memo[0];
    }
};

/*动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.size() == 1) return nums[0];
		auto memo = nums;
		if(nums.size() > 2)
			memo[2] = memo[2] + memo[0];
		for(int i = 3; i < memo.size(); i++){
			memo[i] = memo[i] + max(memo[i-2], memo[i-3]);
		}

		return max(memo[memo.size() - 1], memo[memo.size() - 2]);
    }
};
*/

int main(){
	vector<int> tmp{2,7,9,3,1};
	Solution s;
	cout << s.rob(tmp)  << endl;
	return 0;
}
