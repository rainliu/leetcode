#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	int m = searchrange(matrix, target, true, 0);    
    	if(m<0||m>=matrix.size()){
    		return false;
    	}else if(matrix[m][0]==target){
    		return true;
    	
    	}else{
    		int n = searchrange(matrix, target, false, m);
    		if(n<0||n>=matrix[0].size()){
    			return false;
    		}else if(matrix[m][n]==target){
    			return true;
    		}else{
    			return false;
    		}
    	}
    }

    int searchrange(vector<vector<int> > &matrix, int target, bool bCol, int m) {
    	int mi, lo=0, hi=bCol?matrix.size()-1:matrix[0].size()-1;
    	while(lo<=hi){
    		mi = lo+(hi-lo)/2;
    		if     (matrix[bCol?mi:m][bCol?m:mi]<target) lo=mi+1;
    		else if(matrix[bCol?mi:m][bCol?m:mi]>target) hi=mi-1;
    		else return mi;
    	}
    	return hi;
    }
};

int main(){
	Solution s;

	return 0;
}