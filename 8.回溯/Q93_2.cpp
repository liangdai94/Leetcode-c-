//回溯法
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
private:
	vector<string> res;
	void helper(string & s, int x, int c, string ip){
		if(c >= 3){
			if(distance(s.begin() + x, s.end()) > 3){
				return;
			}

			if(distance(s.begin() + x, s.end()) >= 2 && s[x] == '0'){
				return;
			}
			
			string tmp(s.begin() + x, s.end());
			if(atoi(tmp.c_str()) > 255){
				return;
			}
			//cout << ip + tmp << endl;
			res.push_back(ip + tmp);
			return;
		}

		for(int i = x; i < s.size() && i < x + 4; i++){
			if((i - x > 1 && s[x] == '0') || i == x){
				continue;
			}
			string tmp(s.begin() + x, s.begin() + i);
			if(atoi(tmp.c_str()) > 255){
				continue;
			}
			
			helper(s, i, c + 1, ip + tmp + ".");
		}
	}
public:
	vector<string> restoreIpAddresses(string s) {
		if(s.size() < 4)	return res;

		helper(s, 0, 0, "");
		return res;
	}
};

int main() {
	string s = "172162541";

	Solution res;
	auto ans = res.restoreIpAddresses(s);
	cout << endl;
	for (auto it : ans) {
		cout << it << endl;
	}

	return 0;
}
