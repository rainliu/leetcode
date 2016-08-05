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
https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int lo = 0;
    	int hi = n-1;
    	int mi;

    	while(lo+1<hi&&A[lo+1]==A[lo]) lo++;
    	while(lo<hi-1&&A[hi-1]==A[hi]) hi--;
    	while(lo<hi&&A[lo]==A[hi]) hi--;

    	while(lo<=hi){
    		mi = lo + (hi-lo)/2;
    		if(A[mi]==target) return true;
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
    		while(lo+1<hi&&A[lo+1]==A[lo]) lo++;
    		while(lo<hi-1&&A[hi-1]==A[hi]) hi--;
    		while(lo<hi&&A[lo]==A[hi]) hi--;
    	}    

    	return false;
    }
};

int main(){
	return 0;	
}