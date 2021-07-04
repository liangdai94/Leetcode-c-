#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
	bool check(string & s, int i, int j, int k) {
		string s1(s.begin(), s.begin() + i + 1);
		cout << s1 << endl;
		if (i > 0 && s[0] == '0')
			return false;
		int tmp = atoi(s1.c_str());
		if (tmp > 255)
			return false;

		string s2(s.begin() + i + 1, s.begin()  + j + 1);
		cout << s2 << endl;
		if (j - i >= 2 && s[i + 1] == '0')
			return false;
		tmp = atoi(s2.c_str());
		if (tmp > 255)
			return false;

		string s3(s.begin() + j + 1, s.begin() + k + 1);
		cout << s3 << endl;
		if (k - j >= 2 && s[j + 1] == '0')
			return false;
		tmp = atoi(s3.c_str());
		if (tmp > 255)
			return false;

		string s4(s.begin() + k + 1, s.end());
		cout << k <<  "\t" <<  s.size()<< endl;
		if (s.size() - k > 2 && s[k + 1] == '0')
			return false;
		cout << s4 << endl;
		tmp = atoi(s4.c_str());
		if (tmp > 255)
			return false;

		return true;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		if (s.size() < 4)    return res;

		for (size_t i = 0; i < 3; i++) {
			for (auto j = i + 1; j < i + 4 && j < s.size() - 2; j++) {
				for (auto k = j + 1; k < j + 4 && k < s.size()- 1; k++) {
					if (s.size() - k > 4)
						continue;
					string tmp = s;
					tmp.insert(i + 1, ".");
					tmp.insert(j + 2, ".");
					tmp.insert(k + 3, ".");
					cout << tmp << endl;
					if (check(s, i, j, k))
						res.push_back(tmp);
				}
			}
		}
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