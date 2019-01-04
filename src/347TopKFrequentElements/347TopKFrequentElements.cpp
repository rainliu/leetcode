#include <iostream>
#include <priority_queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }
    // Using lambda to compare elements.
    auto cmp = [](const pair<int, int> &left, const pair<int, int> &right) {
      return left.second < right.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    for (auto &p : m) {
      pq.push(p);
    }
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(pq.top().first);
      pq.pop();
    }
    return result;
  }
};

int main() { return 0; }