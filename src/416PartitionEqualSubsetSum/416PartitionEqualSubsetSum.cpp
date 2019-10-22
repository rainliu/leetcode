class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); if(n<=1) return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1) return false;
        int target = sum/2;
        vector<vector<bool>> D(n, vector<bool>(max(100,target)+1, false));
        D[0][nums[0]]=true;
        for(int i=1; i<n; ++i){
            for(int t=1; t<=target; ++t){
                if(nums[i]<=t){
                    D[i][t] = D[i-1][t-nums[i]]||D[i-1][t];
                }else{
                    D[i][t] = D[i-1][t];
                }
            }
        }
        return D[n-1][target];
    }
};
