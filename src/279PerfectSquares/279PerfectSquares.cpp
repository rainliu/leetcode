class Solution {
public:
    int numSquares(int n) {
        vector<int> D(n+1, 0);
        for(int k=1; k<=n; ++k){
            int local = numeric_limits<int>::max();
            for(int i=1; i*i<=k; ++i){
                local = min(local, D[k-i*i]+1);
            }
            D[k]=local;
        }
        return D[n];
    }
};

#include <iostream>
using namespace std;

// E[n] = min(E[n-i*i]+1)
class Solution {
public:
  int numSquares(int n) {
    vector<int> E(n + 1, n);
    E[0] = 0;
    for (int j = 1; j <= n; j++) {
      int i = 1;
      while (j - i * i >= 0) {
        E[j] = min(E[j], E[j - i * i] + 1);
        i++;
      }
    }
    return E[n];
  }
};

int main() { return 0; }
