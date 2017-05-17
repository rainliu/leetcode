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
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0, j=0, k=0;
        while(j<n){
        	while(j<n&&A[j]==A[i]){
        		j++;
        	}
        	A[k++]=A[i];
        	i=j;
        }
        return k;
    }
};

int main(){
	Solution s;

	int A[] = {1,1,2};	
	cout<<s.removeDuplicates(A, 3)<<":";
	for(const auto&p:A){
		cout<<p<<" ";
	}
	cout<<endl;

	return 0;
}