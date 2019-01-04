#include <vector>
using namespace std;

class Solution {
public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    int n = rooms.size();
    if (n == 0)
      return;
    int m = rooms[0].size();
    if (m == 0)
      return;
    static const int offset_x[] = {-1, 1, 0, 0};
    static const int offset_y[] = {0, 0, -1, 1};

    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
        if (rooms[j][i] == 0) {
          queue<pair<int, int>> q;
          q.push(make_pair(j * m + i, 0));
          while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first % m, y = p.first / m, d = p.second;
            for (int k = 0; k < 4; k++) {
              int u = x + offset_x[k], v = y + offset_y[k];
              if (u >= 0 && u < m && v >= 0 && v < n && rooms[v][u] > d + 1) {
                rooms[v][u] = d + 1;
                q.push(make_pair(v * m + u, d + 1));
              }
            }
          }
        }
      }
    }
  }
};

int main() { return 0; }