#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  bool validTree(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> nbr(n);
    for (auto &p : edges) {
      nbr[p.first].push_back(p.second);
      nbr[p.second].push_back(p.first);
    }

    vector<bool> visited(n, false);
    int cc = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        cc++;
        stack<pair<int, int>> s;
        s.push(make_pair(i, i));
        while (!s.empty()) {
          auto p = s.top();
          s.pop();
          int v = p.first, u = p.second;
          visited[v] = true;
          for (auto w : nbr[v]) {
            if (visited[w]) {
              if (w != u) {
                return false;
              }
            } else {
              s.push(make_pair(w, v));
            }
          }
        }
      }
    }
    return cc == 1;
  }
};

int main() { return 0; }