#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size();
    if (n == 0)
      return 0;
    int m = matrix[0].size();
    if (m == 0)
      return 0;

    int global = 0;
    vector<vector<int>> E;
    for (int j = 0; j < n; j++) {
      vector<int> e(m, 0);
      E.push_back(e);
    }

    for (int j = 0; j < n; j++) {
      E[j][0] = matrix[j][0] == '1' ? 1 : 0;
      global = max(E[j][0], global);
    }
    for (int i = 0; i < m; i++) {
      E[0][i] = matrix[0][i] == '1' ? 1 : 0;
      global = max(E[0][i], global);
    }
    for (int j = 1; j < n; j++) {
      for (int i = 1; i < m; i++) {
        if (matrix[j][i] == '1') {
          E[j][i] = min(min(E[j][i - 1], E[j - 1][i]), E[j - 1][i - 1]) + 1;
          global = max(E[j][i], global);
        }
      }
    }
    return global * global;
  }
};