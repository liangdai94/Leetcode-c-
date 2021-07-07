#include<vector>
#include<iostream>
#include<limits.h>

using namespace std;
//记忆搜索
class Solution {
private:
	vector<int> memo;
public:
    int numSquares(int n) {
    	if(n == 1 || n == 2 || n == 0){
			return n;
    	}
    	int res = INT_MAX;
    	static vector<int> memo(n+1, -1);
    	if(memo[n] == -1){
			for(int i = 1; i * i <= n; i++){
				if(i * i == n)
					return 1;
				int tmp = numSquares(i*i) + numSquares(n-i*i);
				res = res > tmp ? tmp : res; 
	 		}
	 		memo[n] = res;
	 	}

 		return memo[n];
    }
};
//动态规划
int numSquares(int n){
	if(n == 0 || n == 1){
		return 1;
	}

	vector<int> memo(n+1, INT_MAX);
	memo[1] = 1;
	memo[0] = 1;

	for(int i = 2; i <=n; i++){
		for(int j = 1; j <= i/2; j++){
			if(j * j == i){
				memo[i] = 1;
				break;
			}
			memo[i] = memo[i] > memo[j] + memo[i - j] ? memo[j] + memo[i - j] : memo[i];
		}
	}

	return memo[n];
}


int main(){
	Solution s;
	cout << s.numSquares(13) << endl;
	cout << numSquares(15778) << endl;
	return 0;
}
