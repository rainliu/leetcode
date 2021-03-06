class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); if(m==0) return;
        int n = matrix[0].size(); if(n==0) return;
        bool row = false, col = false;
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(i==0&&j==0){
                    row = col = matrix[j][i]==0;
                }else if(i==0){
                    col = col || matrix[j][i]==0;   
                }else if(j==0){
                    row = row || matrix[j][i]==0;
                }else{
                    if(matrix[j][i]==0){
                        matrix[j][0]=0;
                        matrix[0][i]=0;
                    }
                }
            }
        }
        for(int j=1; j<m; ++j){
            for(int i=1; i<n; ++i){
                if(matrix[j][0]==0||matrix[0][i]==0){
                    matrix[j][i] = 0;
                }
            }
        }
        if(col){
            for(int j=0; j<m; ++j){
                matrix[j][0]=0;
            }
        }
        if(row){
            for(int i=0; i<n; ++i){
                matrix[0][i]=0;
            }
        }
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); if(m==0) return;
        int n = matrix[0].size(); if(n==0) return;
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                row[j] = row[j] || matrix[j][i]==0;
                col[i] = col[i] || matrix[j][i]==0;
            }
        }
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(row[j]||col[i]){
                    matrix[j][i]=0;
                }
            }
        }
    }
};

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
https://oj.leetcode.com/problems/set-matrix-zeroes/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	if(matrix.size()==0) return;

    	int rows = matrix.size();
    	int cols = matrix[0].size();
    	bool r0=false, c0=false;
        for(int row=0; row<rows; ++row){
        	for(int col=0; col<cols; ++col){
        		if(col==0&&row==0){
        			r0 = c0 = matrix[row][col]==0;
        		}else if(col==0){
        			r0 = r0||matrix[row][col]==0;
        		}else if(row==0){
        			c0 = c0||matrix[row][col]==0;
        		}else{
	        		if(matrix[row][col]==0){
	        			matrix[row][0]=0;
	        			matrix[0][col]=0;
	        		}
	        	}
        	}
        }

        for(int row=1; row<rows; ++row){
        	for(int col=1; col<cols; ++col){
        		matrix[row][col] = (matrix[row][0]==0||matrix[0][col]==0)?0:matrix[row][col];
        	}
        }
        for(int row=0; row<rows; ++row){
        	matrix[row][0]=r0?0:matrix[row][0];
        }
        for(int col=0; col<cols; ++col){
        	matrix[0][col]=c0?0:matrix[0][col];
        }
    }
};

class Solution1 {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	if(matrix.size()==0) return;

    	int m = matrix.size();
    	int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		row[i]=row[i]||matrix[i][j]==0;
        		col[j]=col[j]||matrix[i][j]==0;
        	}
        }

        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		matrix[i][j] = (row[i]||col[j])?0:matrix[i][j];
        	}
        }
    }
};

int main(){
	return 0;
}
