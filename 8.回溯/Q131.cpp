#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
private:
	vector<vector<string>> res;
	bool check(string &s){
		int i = 0;
		int j = s.size() - 1;

		while(i < j){
			if(s[i] != s[j])
				return false;
			i++;
			j--;
		}

		return true;
	}
	void helper(string &s, int x, vector<string>& strs){
		if(x >= s.size()){
			res.push_back(strs);
			return;
		}
		
		for(int i = x + 1; i <= s.size(); i++){
			string tmp(s.begin() + x, s.begin() + i);
			
			if(check(tmp) == false)
				continue;
			//cout << x << "\t" << i << endl;
			strs.push_back(tmp);
			//cout << tmp << endl;
			helper(s, i, strs);
			strs.erase(strs.end() - 1);
		}
		return;
	}
public:
    vector<vector<string>> partition(string s) {
    	vector<string>tmp;
    	helper(s, 0, tmp);
		return res;
    }
};


int main(){
	string str = "aaba";

	Solution s;
	auto ans = s.partition(str);

	for(auto it : ans){
		for(auto it1 : it){
			cout << it1 << endl;
		}

		cout << endl;
	}
	
	return 0;
}
