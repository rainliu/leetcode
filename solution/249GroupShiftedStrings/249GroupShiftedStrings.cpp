#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupStrings(vector<string> &strings) {
    vector<vector<string>> results;
    for (int i = 0; i < strings.size(); i++) {
      bool find = false;
      for (int j = 0; j < results.size(); j++) {
        if (results[j][0].size() == strings[i].size()) {
          int n = strings[i].size();
          int d = (strings[i][0] - results[j][0][0] + 26) % 26;
          bool same = true;
          for (int k = 1; k < n; k++) {
            if ((strings[i][k] - results[j][0][k] + 26) % 26 != d) {
              same = false;
              break;
            }
          }
          if (same) {
            results[j].push_back(strings[i]);
            find = true;
            break;
          }
        }
      }
      if (!find) {
        results.push_back(vector<string>{strings[i]});
      }
    }
    return results;
  }
};

int main() { return 0; }