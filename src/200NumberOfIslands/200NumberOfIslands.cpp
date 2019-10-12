class union_find{
    vector<int> id;
    vector<int> sz;
    int cnt;
public:
    union_find(int N){
        cnt = N;
        id.resize(N);
        sz.resize(N);
        for(int i=0; i<N; ++i){
            id[i]=i;
            sz[i]=1;
        }
    }
    
    int find(int i){
        while(i!=id[i]){
            id[i]=id[id[i]];
            i=id[i];
        }
        return i;
    }
    bool connected(int p, int q){
        return find(p)==find(q);
    }
    void unioning(int p, int q){
        int i = find(p);
        int j = find(q);
        if(i==j) return;
        else if (sz[i]<sz[j]) {
            id[i]=j; sz[j]+=sz[i];
        }else{
            id[j]=i; sz[i]+=sz[j];
        }
        --cnt;
    }
    int count(){
        return cnt;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); if(m==0) return 0;    
        int n = grid[0].size(); if(n==0) return 0;
        union_find uf(m*n);
        int zeros = 0;
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(grid[j][i]=='1'){
                    if(i>0&&grid[j][i-1]=='1'){
                        uf.unioning(j*n+i, j*n+i-1);
                    }    
                    if(j>0&&grid[j-1][i]=='1'){
                        uf.unioning(j*n+i, (j-1)*n+i);
                    }
                }else{
                    ++zeros;
                }
            }
        }
        return uf.count()-zeros;
    }
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i,
           int j, int m, int n) {
    visited[j][i] = true;
    int offset_x[4] = {-1, +1, 0, 0};
    int offset_y[4] = {0, 0, -1, +1};
    for (int k = 0; k < 4; k++) {
      int x = i + offset_x[k];
      int y = j + offset_y[k];
      // cout << x << " " << y << endl;
      if (x >= 0 && x < m && y >= 0 && y < n && grid[y][x] == '1' &&
          !visited[y][x]) {
        dfs(grid, visited, x, y, m, n);
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    if (n == 0) {
      return 0;
    }
    int m = grid[0].size();
    if (m == 0) {
      return 0;
    }
    vector<vector<bool>> visited;
    for (int j = 0; j < n; j++) {
      vector<bool> v(m, false);
      visited.push_back(v);
    }
    // cout << visited.size() << " " << visited[0].size() << endl;
    int num = 0;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
        // cout << i << " " << j << endl;
        if (grid[j][i] == '1' && !visited[j][i]) {
          num++;
          dfs(grid, visited, i, j, m, n);
        }
      }
    }
    return num;
  }
};

int main() {
  vector<vector<char>> grid = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'},
  };
  Solution s;
  cout << s.numIslands(grid) << endl;
}
