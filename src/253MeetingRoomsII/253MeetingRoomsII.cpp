#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int minMeetingRooms(vector<Interval> &intervals) {
    map<int, int> m;
    for (auto &p : intervals) {
      ++m[p.start];
      --m[p.end];
    }
    int global = 0, local = 0;
    for (auto &p : m) {
      local += p.second;
      global = max(global, local);
    }
    return global;
  }
};

int main() { return 0; }