#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> memo(nums.size(), 1);
		int tmp;

		for(int i = 1; i < nums.size(); i++){
			tmp = 1;
			for(int j = 0; j < i; j++){
				if(nums[j] < nums[i]){
					tmp = tmp > memo[j] ? tmp : (memo[j] + 1);
				}
			}
			memo[i] = tmp;
		}

		for(auto it : memo){
			tmp = max(tmp, it);
		}

		return tmp;
    }
};

int main(){
	vector<int> nums{7,7,1,7,7,7};
	Solution s;

	cout << s.lengthOfLIS(nums) << endl;
	
	return 0;
}
