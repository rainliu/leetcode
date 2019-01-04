#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  unordered_map<char, char> LUT = {
      {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
  vector<char> cands = {'0', '1', '6', '8', '9'};
  vector<char> symms = {'0', '1', '8'};

  void backtracking(int k, int n, vector<string> &results,
                    vector<char> &result) {
    if (k == n / 2) {
      if (n % 2) {
        for (int i = 0; i < symms.size(); i++) {
          ostringstream oss;
          for (int j = 0; j < k; j++) {
            oss << result[j];
          }
          oss << symms[i];
          for (int j = k - 1; j >= 0; j--) {
            oss << LUT[result[j]];
          }
          auto s = oss.str();
          if (!(s.size() > 1 && s[0] == '0')) {
            results.push_back(s);
          }
        }
      } else {
        ostringstream oss;
        for (int j = 0; j < k; j++) {
          oss << result[j];
        }
        for (int j = k - 1; j >= 0; j--) {
          oss << LUT[result[j]];
        }
        auto s = oss.str();
        if (!(s.size() > 1 && s[0] == '0')) {
          results.push_back(s);
        }
      }
    } else {
      k++;
      for (int i = 0; i < cands.size(); i++) {
        result.push_back(cands[i]);
        backtracking(k, n, results, result);
        result.pop_back();
      }
    }
  }

public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> results;
    vector<char> result;
    backtracking(0, n, results, result);
    return results;
  }
};

int main() {
  Solution s;
  auto out1 = s.findStrobogrammatic(1);
  for (auto &x : out1) {
    cout << x << " ";
  }
  cout << endl;
  auto out2 = s.findStrobogrammatic(2);
  for (auto &x : out2) {
    cout << x << " ";
  }
  cout << endl;
  auto out3 = s.findStrobogrammatic(3);
  for (auto &x : out3) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}