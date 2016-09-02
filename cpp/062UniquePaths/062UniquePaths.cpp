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
https://oj.leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
    	if(m<=0||n<=0) return 0;
    	if(m==1&&n==1) return 1;

    	vector<vector<int>> E;
    	vector<int> e(n, 0);
    	for(int i=0; i<m; ++i){
    		E.push_back(e);
    	}    

    	for(int i=0; i<m; ++i){
    		E[i][0] = 1;
    	}
    	for(int j=0; j<n; ++j){
    		E[0][j] = 1;
    	}

    	for(int i=1; i<m; ++i){
    		for(int j=1; j<n; ++j){
    			E[i][j] = E[i-1][j]+E[i][j-1];
    		}
    	}


    	return E[m-1][n-1];
    }
};

int main(){
	return 0;
}