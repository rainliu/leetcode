class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mab;
        unordered_map<int, int> mcd;
        int n = A.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                ++mab[A[i]+B[j]];
                ++mcd[C[i]+D[j]];
            }
        }
        int count = 0;
        for(const auto& [ab, c] : mab){
            if(mcd.find(-ab)!=mcd.end()){
                count+=c*mcd[-ab];
            }
        }
        
        return count;
    }
};

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    int n = A.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        m[-(A[i] + B[j])]++;
      }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (m[C[i] + D[j]] > 0) {
          result += m[C[i] + D[j]];
        }
      }
    }
    return result;
  }
};

int main() { return 0; }
