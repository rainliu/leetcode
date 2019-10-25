class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1; i<nums.size(); ++i){
            if(i&0x1){
                if(nums[i-1]>nums[i]){
                    swap(nums[i-1], nums[i]);
                }
            }else{
                if(nums[i-1]<nums[i]){
                    swap(nums[i-1], nums[i]);
                }
            }
        }   
    }
};
