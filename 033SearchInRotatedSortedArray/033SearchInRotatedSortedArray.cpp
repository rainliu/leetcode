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
https://oj.leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
    	int lo = 0;
    	int hi = n-1;
    	int mi;

    	while(lo<=hi){
    		mi = lo + (hi-lo)/2;
    		if(A[mi]==target) return mi;
    		else if(A[mi]>target){
    			if(A[hi]>A[mi]){
    				hi = mi-1;
    			}else if(A[lo]>target){
    				lo = mi+1;
    			}else{
    				hi = mi-1;
    			}
    		}else{//A[mi]<target
    			if(A[lo]<=A[mi]){
    				lo = mi+1;
    			}else if(A[hi]>=target){
    				lo = mi+1;
    			}else{
    				hi = mi-1;
    			}
    		}
    	}    

    	return -1;
    }
};

int main(){
	Solution s;

	int A[] = {4, 5, 6, 7, 0, 1, 2};
	cout<<s.search(A, 7, 3)<<endl;
	cout<<s.search(A, 7, 1)<<endl;
	cout<<s.search(A, 7, 5)<<endl;

	return 0;
}