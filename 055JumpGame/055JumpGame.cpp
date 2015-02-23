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
https://oj.leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned 
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(int A[], int n) {
    	int i=0;
    	while(i+A[i]<n-1 && A[i]!=0){
    		int m = A[i]+A[i+A[i]];
    		int k = i+A[i];
    		for(int j=i+A[i]-1; j>i; --j){
	    		if(A[i]-(i+A[i]-j)+A[j]>m){
	    			m=A[i]-(i+A[i]-j)+A[j];
	    			k=j;
	    		}
	    	}
	    	//cout<<" "<<k<<endl;
	    	i=k;
        }
        //cout<<" "<<i+A[i]<<" "<<A[i]<<endl;
        return i+A[i]>=n-1;
    }
};

int main(){
	Solution s;

	int A0[] = {1,1,2,2,0,1,1};//return true;
	cout<<s.canJump(A0, 7)<<endl;

	int A1[] = {2,3,1,1,4};// return true.
	cout<<s.canJump(A1, 5)<<endl;

	int A2[] = {3,2,1,0,4};// return false.
	cout<<s.canJump(A2, 5)<<endl;

	return 0;
}