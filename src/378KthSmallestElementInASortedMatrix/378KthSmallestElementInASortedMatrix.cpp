class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(); if(m==0) return 0;
        int n = matrix[0].size(); if(n==0) return 0;
        
        auto cmp = [](const auto& p, const auto& q){
            return p.first > q.first;    
        };
        priority_queue<pair<int, pair<int,int>>, 
                     vector<pair<int, pair<int,int>>>,
                     decltype(cmp)> pq(cmp);
        
        for(int j=0; j<m; ++j){
            pq.push({matrix[j][0], {j, 0}});
        }
        int result = 0;
        while(k--){
            auto [v, p] = pq.top(); pq.pop();
            p.second += 1;
            if(p.second < n){
                pq.push({matrix[p.first][p.second], p});
            }
            result = v;
        }
        return result;
    }
};

#include <iostream>
#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> qp(
        cmp);
    int n = matrix.size();
    for (int j = 0; j < n; j++) {
      qp.push(make_pair(matrix[j][0], j * n + 0));
    }
    int result;
    while (k) {
      auto p = qp.top();
      qp.pop();
      int i = p.second % n;
      int j = p.second / n;
      result = p.first;
      if (i + 1 < n) {
        qp.push(make_pair(matrix[j][i + 1], j * n + i + 1));
      }
      k--;
    }
    return result;
  }
};

int main() { return 0; }
