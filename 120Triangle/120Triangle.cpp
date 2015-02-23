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
https://oj.leetcode.com/problems/triangle/

Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int n = triangle.size();
    	if(n==0) return 0;

    	vector<int> E(n, numeric_limits<int>::max());
    	
    	E[0] = triangle[0][0];
    	for(int j=1; j<n; ++j){
    		for(int i=j; i>=0; --i){
    			if(i-1>=0){
    				E[i] = triangle[j][i]+min(E[i-1], E[i]);	
    			}else{
    				E[i] = triangle[j][i]+E[i];
    			}
    		}
    	}

    	int m=numeric_limits<int>::max();
    	for(int i=0; i<n; ++i){
    		if(E[i]<m){
    			m=E[i];
    		}
    	}
    	return m;
    }
};

class Solution2 {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int n = triangle.size();
    	if(n==0) return 0;

    	vector<vector<int>> E;
    	vector<int> e(n, numeric_limits<int>::max());
    	for(int j=0; j<n; ++j){
    		E.push_back(e);
    	}

    	E[0][0] = triangle[0][0];
    	for(int j=1; j<n; ++j){
    		for(int i=0; i<=j; ++i){
    			if(i-1>=0){
    				E[j][i] = triangle[j][i]+min(E[j-1][i-1], E[j-1][i]);	
    			}else{
    				E[j][i] = triangle[j][i]+E[j-1][i];
    			}
    		}
    	}

    	int m=numeric_limits<int>::max();
    	for(int i=0; i<n; ++i){
    		if(E[n-1][i]<m){
    			m=E[n-1][i];
    		}
    	}
    	return m;
    }
};

int main(){
	Solution s;

	vector<vector<int>> triangle{
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3},
	};

	cout<<s.minimumTotal(triangle)<<endl;

	return 0;
}