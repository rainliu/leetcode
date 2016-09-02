#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
https://oj.leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
    	if(n<=0) return 0;
    	if(n==1) return 1;

    	vector<int> E(n+1, 0);

    	E[0] = 1;
    	E[1] = 1;
    	for(int i=2; i<n+1; ++i){
    		E[i] = E[i-1]+E[i-2];
    	}
    	return E[n];
    }
};

int main(){
	Solution s;

	cout<<s.climbStairs(0)<<endl;
	cout<<s.climbStairs(1)<<endl;
	cout<<s.climbStairs(2)<<endl;
	cout<<s.climbStairs(3)<<endl;
	cout<<s.climbStairs(4)<<endl;

	return 0;
}