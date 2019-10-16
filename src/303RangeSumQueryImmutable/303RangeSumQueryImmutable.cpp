class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); ++i){
            sum[i]=sum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
