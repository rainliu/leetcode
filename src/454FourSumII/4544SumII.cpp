class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        int n = A.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                ++m[A[i]+B[j]];
            }
        }
        int count = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                int target = C[i]+D[j];
                auto it = m.find(-target);
                if(it!=m.end()){
                    count+=it->second;
                }
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
