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