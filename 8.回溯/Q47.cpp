#include<vector>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	set<vector<int>> memo;
	void helper(vector<int>& nums, int x){
		if(x == nums.size()){
			auto it = memo.insert(nums);
			if(it.second)
				res.push_back(nums);
			return;
		}
		for(int i = x; i < nums.size(); i++){
			swap(nums[x], nums[i]);
			helper(nums, x + 1);
			swap(nums[x], nums[i]);
		}

		return;
	}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
		helper(nums, 0);
		return res;
    }
};

int main(){
	vector<int>nums{1,1,3};
	Solution s;
	auto ans = s.permute(nums);

	for(auto it : ans){
		for(auto it1 : it){
			cout << it1 << "\t";
		}
		cout << endl;
	}
	return 0;
}
