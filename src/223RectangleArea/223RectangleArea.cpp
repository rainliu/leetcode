#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int common = 0;
    // cout << H << " " << B << endl;
    if (F >= D || H <= B || E >= C || G <= A) {
      common = 0;
    } else {
      int a = max(A, E);
      int b = max(B, F);
      int c = min(C, G);
      int d = min(D, H);
      common = abs(a - c) * abs(b - d);
    }
    // cout << common << endl;
    return abs(A - C) * abs(B - D) + abs(E - G) * abs(F - H) - common;
  }
};

int main() {
  Solution s;
  cout << s.computeArea(4, -5, 5, 0, -3, -3, 3, 3) << endl;
}