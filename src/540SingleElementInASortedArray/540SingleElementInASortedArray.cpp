class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        return singleNonDuplicate(nums, 0, n-1);
    }
    
    int singleNonDuplicate(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return nums[lo];
        int mi = lo + (hi-lo)/2;
        if (mi%2==0) {
            if (nums[mi-1]!=nums[mi]) {
                return singleNonDuplicate(nums, mi, hi);
            }else{
                return singleNonDuplicate(nums, lo, mi-2);
            }
        }else{
            if (nums[mi-1]==nums[mi]) {
                return singleNonDuplicate(nums, mi+1, hi);
            }else{
                return singleNonDuplicate(nums, lo, mi-1);
            }
        }
    }
};
