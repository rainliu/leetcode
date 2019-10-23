class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // D[W] = min(for any wj<=W, 1+D[W-wj])
        if(amount<=0) return 0;
        vector<int> D(amount+1, amount+1);
        D[0] = 0;
        for(int j=1; j<=amount; ++j){
            for(const auto& coin : coins){
                if(coin<=j){
                    D[j]=min(D[j], 1+D[j-coin]);    
                }
            }                                                   
        }
        return D[amount]==amount+1? -1 : D[amount];
    }
};

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
private:
  void backtracking(vector<int> &coins, int amount, int64_t sum, int k,
                    int &global, int local) {
    if (sum > amount) {
    } else if (sum == amount) {
      global = min(global, local);
    } else {
      for (int i = k; i >= 0; --i) {
        sum += coins[i];
        ++local;
        backtracking(coins, amount, sum, i, global, local);
        --local;
        sum -= coins[i];
      }
    }
  }

public:
  int coinChangeTimeout(vector<int> &coins, int amount) {
    sort(coins.begin(), coins.end());
    int global = numeric_limits<int>::max();
    backtracking(coins, amount, 0, int(coins.size()) - 1, global, 0);
    return global == numeric_limits<int>::max() ? -1 : global;
  }

  int coinChange(vector<int> &coins, int amount) {
    vector<int> E(amount + 1, amount + 1);
    E[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] <= i) {
          E[i] = min(E[i], 1 + E[i - coins[j]]);
        }
      }
    }
    return E[amount] > amount ? -1 : E[amount];
  }
};

int main() {
  Solution s;
  {
    vector<int> coins = {186, 419, 83, 408};
    cout << s.coinChange(coins, 6249) << endl;
  }
  {
    vector<int> coins = {346, 29, 395, 188, 155, 109};
    cout << s.coinChange(coins, 9401) << endl;
  }
  return 0;
}
