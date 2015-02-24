#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
https://oj.leetcode.com/problems/rotate-array/

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n<=1) return;
        if(k%n==0) return;
        
        k=k%n;

        for(int i=0; i<(n-k)/2; ++i){
        	swap(nums, i, n-k-1-i);
        }

        for(int j=n-k; j<n-k+(k/2); ++j){
        	swap(nums, j, n-k+n-1-j);
        }

        for(int i=0; i<n/2; ++i){
        	swap(nums, i, n-1-i);
        }
    }

    void swap(int nums[], int i, int j){
    	int tmp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = tmp;
    }
};

int main(){
	Solution s;

	{	
		int nums[] = {1,2,3,4,5,6,7};
		s.rotate(nums, 7, 3);
		for(const auto &p : nums){
			cout<<p<<" ";
		}
		cout<<endl;
	}

	return 0;
}