#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n+1,0);
        for(int i=1; i<=n; i++){
            sum[i]+=sum[i-1]+nums[i-1];
        }
        for(int i=0;i<n-1; i++){
            for(int j=i+2; j<=n; j++){
                if((!k && sum[j]-sum[i]==k) || (k && (sum[j]-sum[i])%k==0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
  return 0;
}