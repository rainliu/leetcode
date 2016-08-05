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
https://oj.leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	if(grid.size()==0) return 0;

    	int n = grid.size();
    	int m = grid[0].size();
    	vector<vector<int>> E;
    	vector<int> e(m, 0);
    	for(int j=0; j<n; ++j){
    		E.push_back(e);
    	}

    	E[0][0] = grid[0][0];
    	for(int i=1; i<m; ++i){
    		E[0][i]=E[0][i-1]+grid[0][i];
    	}
    	for(int j=1; j<n; ++j){
    		E[j][0]=E[j-1][0]+grid[j][0];
    	}

    	for(int j=1; j<n; ++j){
    		for(int i=1; i<m; ++i){
    			E[j][i] = min(E[j][i-1], E[j-1][i])+grid[j][i];
    		}
    	}
        
        return E[n-1][m-1];
    }
};

int main(){
	return 0;
}