#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
    	if(n == 1 || n == 2)
    		return 1;
    	static vector<int> memo(n+1, -1);
    	int res = 0;
		if(memo[n] == -1){
			for(int i = 1; i < n/2 + 1; i++){
				int tmp1 = integerBreak(i);
				int tmp2 = integerBreak(n-i);
				int tmp = max(tmp1 * tmp2, tmp1 * (n-i));
				tmp = max(tmp, i * tmp2);
				tmp = max(tmp, i * (n - i));
				res = res > tmp ? res : tmp;
			}
			
			memo[n] = res;
		}

		return memo[n];
    }
};

/*
class Solution {
public:
    int integerBreak(int n) {
    	if(n == 1 || n == 2)
    		return 1;
    	vector<int> memo(n+1, -1);

    	for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				int tmp = max(memo[j], j) * max(memo[i-j], i-j);
				memo[i] = memo[i] > tmp ? memo[i] : tmp;
			}
    	}
		return memo[n];
    }
};
*/

int main(){
	Solution s;
	cout << s.integerBreak(58) << endl;
	return 0;
}
