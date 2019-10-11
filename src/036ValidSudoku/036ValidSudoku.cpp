class Solution {
    static constexpr int offset_x[9] = {0,3,6,0,3,6,0,3,6};
    static constexpr int offset_y[9] = {0,0,0,3,3,3,6,6,6};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(); if(m==0) return false;
        int n = board[0].size(); if(n==0) return false;
        for(int j = 0; j < m; ++j) {
            unordered_set<int> s;
            for(int i = 0; i < n; ++i){
                if(board[j][i] != '.') {
                    int d = board[j][i]-'0';
                    if(s.find(d) != s.end()) {
                        return false;
                    }else{
                        s.insert(d);
                    }
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for(int j = 0; j < m; ++j){
                if(board[j][i] != '.') {
                    int d = board[j][i]-'0';
                    if(s.find(d) != s.end()) {
                        return false;
                    }else{
                        s.insert(d);
                    }
                }
            }
        }
        for(int k=0; k<9; ++k){
            unordered_set<int> s;
            for(int y=0; y<3; ++y){
                for(int x=0; x<3; ++x){
                    int i = offset_x[k]+x;
                    int j = offset_y[k]+y;
                    if(board[j][i] != '.') {
                        int d = board[j][i]-'0';
                        if(s.find(d) != s.end()) {
                            return false;
                        }else{
                            s.insert(d);
                        }
                    }
                }
            }
        }
        return true;
    }
};

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules. http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
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

	return 0;
}
