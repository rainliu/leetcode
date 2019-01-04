#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
struct Coord{
	int i;
	int j;
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	if(board.size()==0) return;
    	int n = board.size();
    	int m = board[0].size();
    	queue<Coord> q;

    	for(int i=0; i<n; ++i){
   			if(board[i][0  ]=='O')  q.push(Coord{i,0});
   			if(board[i][m-1]=='O')  q.push(Coord{i,m-1});
   		}
   		for(int j=0; j<m; ++j){
   			if(board[0  ][j]=='O')  q.push(Coord{0,j});
   			if(board[n-1][j]=='O')  q.push(Coord{n-1,j});
   		}
   		
   		while(!q.empty()){
   			auto p = q.front(); q.pop();
   			int i = p.i;
   			int j = p.j;
   			board[i][j] = '1';
	    	if(i-1>=0 && board[i-1][j  ]=='O') q.push(Coord{i-1, j  });
	    	if(j-1>=0 && board[i  ][j-1]=='O') q.push(Coord{i  , j-1});
	    	if(i+1< n && board[i+1][j  ]=='O') q.push(Coord{i+1, j  });
	    	if(j+1>=0 && board[i  ][j+1]=='O') q.push(Coord{i  , j+1});
   		}

   		for(int i=0; i<n; ++i){
   			for(int j=0; j<m; ++j){
   				if(board[i][j]=='O') board[i][j]='X';
   				if(board[i][j]=='1') board[i][j]='O';
   			}
   		}
    }
};

class Solution2 {
public:
    void solve(vector<vector<char>> &board) {
    	if(board.size()==0) return;
    	int n = board.size();
    	int m = board[0].size();

    	for(int i=0; i<n; ++i){
   			if(board[i][0  ]=='O') DFS(board, n, m, i, 0);
   			if(board[i][m-1]=='O') DFS(board, n, m, i, m-1);	
   		}
   		for(int j=0; j<m; ++j){
   			if(board[0  ][j]=='O') DFS(board, n, m, 0,   j);
   			if(board[n-1][j]=='O') DFS(board, n, m, n-1, j);
   		}

   		for(int i=0; i<n; ++i){
   			for(int j=0; j<m; ++j){
   				if(board[i][j]=='O') board[i][j]='X';
   				if(board[i][j]=='1') board[i][j]='O';
   			}
   		}
    }

    void DFS(vector<vector<char>> &board, int n, int m, int i, int j){
    	board[i][j] = '1';
    	if(i-1>=0 && board[i-1][j  ]=='O') DFS(board, n, m, i-1, j  );
    	if(j-1>=0 && board[i  ][j-1]=='O') DFS(board, n, m, i  , j-1);
    	if(i+1< n && board[i+1][j  ]=='O') DFS(board, n, m, i+1, j  );
    	if(j+1>=0 && board[i  ][j+1]=='O') DFS(board, n, m, i  , j+1);
    }
};


int main(){
	Solution s;

	vector<char> b{'X'};
	vector<vector<char>> v;
	v.push_back(b);

	s.solve(v);

	return 0;
}