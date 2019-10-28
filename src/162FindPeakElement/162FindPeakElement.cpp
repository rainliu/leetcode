class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mi = lo + (hi-lo)/2;
            if( (mi-1<0||nums[mi-1]<nums[mi])&&
                (mi+1>n-1||nums[mi]>nums[mi+1]) ){
                return mi;
            }else if( (mi-1<0||nums[mi-1]<nums[mi])&&
                      (mi+1<=n-1&&nums[mi]<nums[mi+1]) ){
                lo = mi+1;
            }else{
                hi = mi-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = int(nums.size())-1;
        while(lo<=hi){
            int mi = lo + (hi-lo)/2;
            if( (mi==0 || nums[mi]>nums[mi-1]) && 
                (mi==int(nums.size())-1 || nums[mi]>nums[mi+1])
              ){
                return mi;
            }else if( (mi==0 || nums[mi]>nums[mi-1]) && 
                      (mi==int(nums.size())-1 || nums[mi]<nums[mi+1])
                    ){
                lo = mi + 1;
            }else{
                hi = mi - 1;
            }
        }
        return -1;
    }
};


#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
    	int low = 0;
    	int hig = num.size()-1;
    	int mid;
    	while(low<=hig){
    		mid = low + (hig-low)/2;
    		long long left = mid-1<0?numeric_limits<long long>::min():num[mid-1];
    		long long center = num[mid];
    		long long right = mid+1>=num.size()?numeric_limits<long long>::min():num[mid+1];
    		if(center>left&&center>right) return mid;
    		else if(center>left&&center<right) low = mid+1;
    		else hig = mid-1;
    	} 
    	return 0;
    }
};

int main(){
	Solution s;

	return 0;
}
