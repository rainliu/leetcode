class UnionFind{
    vector<int> id;
    vector<int> sz;
    int cnt;
    
public:
    UnionFind(int N){
        cnt = N;
        id.resize(N);
        sz.resize(N);
        for(int i=0; i<N; ++i){
            id[i]=i;
            sz[i]=1;
        }
    }
    
    int Find(int i){
        while(i!=id[i]){
            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }
    
    void Union(int p, int q){
        int i = Find(p);
        int j = Find(q);
        if(i==j) return;
        else if (sz[i]<sz[j]) {
            id[i]=j; sz[j]+=sz[i];
        }else{
            id[j]=i; sz[i]+=sz[j];
        }
        --cnt;
    }
    int Count(){
        return cnt;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(); if(m==0) return;
        int n=board[0].size(); if(n==0) return;
        UnionFind uf(m*n);
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(board[j][i]=='O'){
                    if(i==0||j==0||i==n-1||j==m-1){
                        uf.Union(0, j*n+i);
                    }
                    if(i>0&&board[j][i-1]=='O'){
                        uf.Union(j*n+i-1, j*n+i);
                    }
                    if(j>0&&board[j-1][i]=='O'){
                        uf.Union((j-1)*n+i, j*n+i);
                    }
                }
            }
        }
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(board[j][i]=='O'&&uf.Find(j*n+i)!=uf.Find(0)){
                    board[j][i]='X';
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
