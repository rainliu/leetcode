#include <iostream>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> m;
    for (auto c : tasks) {
      ++m[c];
    }
    priority_queue<int> q;
    for (auto &p : m) {
      q.push(p.second);
    }
    int cycle = n + 1, intervals = 0;
    while (!q.empty()) {
      vector<int> tmp;
      int times = 0;
      for (int i = 0; i < cycle; ++i) {
        tmp.push_back(q.top());
        q.pop();
        times++;
        if (q.empty())
          break;
      }
      for (auto cnt : tmp) {
        if (--cnt) {
          q.push(cnt);
        }
      }
      intervals += !q.empty() ? cycle : times;
    }

    return intervals;
  }
};

int main() { return 0; }