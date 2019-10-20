class NumArray {
    vector<int> preSum;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        preSum.resize(nums.size()+1);
        for(int j=1; j<=nums.size();++j){
            preSum[j] = preSum[j-1]+nums[j-1];
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        for(int j=i+1; j<=nums.size(); ++j){
            preSum[j] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        return preSum[j+1]-preSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
