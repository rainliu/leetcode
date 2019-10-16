class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); assert(n>0);
        int local_min = nums[0];
        int local_max = nums[0];
        int global = nums[0];
        
        for(int i=1; i<n; ++i){
            int tmp   = max(max(local_min*nums[i], nums[i]), local_max*nums[i]);
            local_min = min(min(local_min*nums[i], nums[i]), local_max*nums[i]);
            local_max = tmp;
            global = max(local_max, global);
        }
        
        return global;
    }
};

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
https://oj.leetcode.com/problems/maximum-product-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
        vector<int> e(n, 0);
        vector<int> E(n, 0);

        e[0] = A[0];
        E[0] = A[0];
        for(int j=1; j<n; ++j){
        	E[j] = max(max(A[j],A[j]*E[j-1]), A[j]*e[j-1]);
        	e[j] = min(min(A[j],A[j]*E[j-1]), A[j]*e[j-1]);
        }

        int m = numeric_limits<int>::min();
        for(int j=0; j<n; ++j){
        	if(E[j]>m){
        		m=E[j];
        	}
        }

        return m;
    }
};

int main(){
	Solution s;

	{
		int A[] = {2,-5,-2,-4,3};
		cout<<s.maxProduct(A, 5)<<endl;
	}

	{
		int A[] = {2,3,-2,-4};
		cout<<s.maxProduct(A, 4)<<endl;
	}

	{
		int A[] = {0,2};
		cout<<s.maxProduct(A, 2)<<endl;
	}

	{
		int A[] = {-2,3,-4};
		cout<<s.maxProduct(A, 3)<<endl;
	}

	{
		int A[] = {-2,3,0,-4};
		cout<<s.maxProduct(A, 4)<<endl;
	}

	return 0;
}
