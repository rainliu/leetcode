class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(); if(m==0) return;
        int n = matrix[0].size(); if(n==0) return;
        if(m!=n) return;
        for(int j=0; j<n/2; ++j){
            swap(matrix[j], matrix[n-1-j]);
        }
        for(int j=0; j<n; ++j){
            for(int i=j+1; i<n; ++i){
                swap(matrix[j][i], matrix[i][j]);
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
https://oj.leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
    	for(int j=0; j<n; ++j){
    		for(int i=0; i<n/2; ++i){
    			int tmp = matrix[j][i];
    			matrix[j][i] = matrix[j][n-1-i];
    			matrix[j][n-1-i]= tmp;
    		}
    	}
    	for(int j=0; j<n-1; ++j){
    		for(int i=0; i<n-1-j; ++i){
    			int tmp = matrix[j][i];
    			matrix[j][i] = matrix[n-1-i][n-1-j];
    			matrix[n-1-i][n-1-j] = tmp;
    		}
    	}
    }
};

class Solution1 {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<int>> matrix2 {matrix};
    	int n = matrix.size();
    	for(int j=0; j<n; ++j){
    		for(int i=0; i<n; ++i){
    			matrix[j][i] = matrix2[n-1-i][j];
    		}
    	}
    }
};


int main(){
	Solution s;

	vector<vector<int>> matrix={
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};

	s.rotate(matrix);

	for(const auto &p : matrix){
		for(const auto &q : p){
			cout<<q<<" ";
		}
		cout<<endl;
	}

	return 0;
}
