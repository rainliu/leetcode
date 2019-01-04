#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> result;
    int m = A.size();
    if (m == 0) {
      return result;
    }
    int n = A[0].size();
    if (n == 0) {
      return result;
    }
    int l = B[0].size();
    if (l == 0) {
      return result;
    }

    for (int j = 0; j < m; j++) {
      vector<int> r(l, 0);
      result.push_back(r);
    }

    vector<unordered_map<int, int>> ma(m), mb(l);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (A[j][i] != 0) {
          ma[j][i] = A[j][i];
        }
      }
    }
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < n; j++) {
        if (B[j][i] != 0) {
          mb[i][j] = B[j][i];
        }
      }
    }
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < l; i++) {
        int sum = 0;
        for (auto &p : ma[j]) {
          // cout << p.first << " " << p.second << endl;
          if (mb[i].find(p.first) != mb[i].end()) {
            sum += p.second * mb[i][p.first];
          }
        }
        result[j][i] = sum;
      }
    }
    return result;
  }
};

/*
[[1,0,0],[-1,0,3]]
[[7,0,0],[0,0,0],[0,0,1]]
*/
int main() {
  Solution s;
  vector<vector<int>> A = {
      {1, 0, 0}, {-1, 0, 3},
  };
  vector<vector<int>> B = {
      {7, 0, 0}, {0, 0, 0}, {0, 0, 1},
  };
  auto C = s.multiply(A, B);
  for (int j = 0; j < C.size(); j++) {
    for (int i = 0; i < C[0].size(); i++) {
      cout << C[j][i] << " ";
    }
    cout << endl;
  }
  return 0;
}