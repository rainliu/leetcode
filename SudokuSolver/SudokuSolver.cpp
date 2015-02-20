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
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> startpos = {0, 3, 6};
        int size = board.size();
        int i,j,m,n;
        
        //row
        for(j=0; j<size; j++){
        	unordered_map<char, int> sudoku;
	        for(i=0; i<size; i++){
	        	if(board[j][i]!='.'){
	        		if(sudoku.find(board[j][i])!=sudoku.end()){
	        			return false;
	        		}else{
	        			sudoku[board[j][i]] = 1;
	        		}
	        	}
	        }
		}
        //col
        for(i=0; i<size; i++){
        	unordered_map<char, int> sudoku;
	        for(j=0; j<size; j++){
	        	if(board[j][i]!='.'){
	        		if(sudoku.find(board[j][i])!=sudoku.end()){
	        			return false;
	        		}else{
	        			sudoku[board[j][i]] = 1;
	        		}
	        	}
	        }
		}
        //grid
        for(n=0; n<3; n++){
        	int y = startpos[n];
        	for(m=0; m<3; m++){
        		unordered_map<char, int> sudoku;
        		int x = startpos[m];
        		for(j=y; j<y+3;j++){
        			for(i=x; i<x+3;i++){
        				if(board[j][i]!='.'){
			        		if(sudoku.find(board[j][i])!=sudoku.end()){
			        			return false;
			        		}else{
			        			sudoku[board[j][i]] = 1;
			        		}
			        	}
        			}
        		}
        	}
        }

        return true;
    }
};

int main(){
	Solution s;

	return s;
}