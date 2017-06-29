#include <iostream>
using namespace std;

class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    int n = wall.size();
    if (n == 0)
      return 0;
    unordered_map<int, int> m;
    int global = n;
    for (int j = 0; j < n; ++j) {
      for (int i = 0, sum = 0; i < int(wall[j].size()) - 1; ++i) {
        global = min(global, n - (++m[sum += wall[j][i]]));
      }
    }
    return global;
  }
};

int main() { return 0; }