#include <vector>
using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int n = grid.size();
    if (n == 0)
      return 0;
    int m = grid[0].size();
    if (m == 0)
      return 0;
    static const int offset_x[] = {-1, 1, 0, 0};
    static const int offset_y[] = {0, 0, -1, 1};
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        if (grid[j][i] == 1) {
          for (int k = 0; k < 4; ++k) {
            int y = j + offset_y[k], x = i + offset_x[k];
            if (x >= 0 && x < m && y >= 0 && y < n) {
              if (grid[y][x] == 0) {
                ++sum;
              }
            } else {
              ++sum;
            }
          }
        }
      }
    }
    return sum;
  }
};

int main() { return 0; }