class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        for (int i = 0; i < n; ++i){
            sum[i+1] = sum[i]+nums[i];
        }
        unordered_map<int,int> m;
        int count = 0;
        for (int i = 0; i < n+1; ++i) {
            if (m.find(sum[i]-k) != m.end()){
                count += m[sum[i]-k];
            }
            m[sum[i]]++;
        }
        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        for (int i = 0; i < n; ++i){
            sum[i+1] = sum[i]+nums[i];
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if(sum[j]-sum[i]==k) {
                    ++count;
                }
            }
        }
        return count;
    }
};
