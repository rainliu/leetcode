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
https://oj.leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n)
to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int i=m-1;
    	int j=n-1;
    	int k=m+n-1;
    	while(i>=0&&j>=0){
    		A[k--] = A[i]>B[j] ? A[i--]: B[j--];
    	}
    	if(j<0){
    		while(i>=0) A[k--] = A[i--];
    	}else{
    		while(j>=0) A[k--] = B[j--];
    	}
    }
};

int main(){
	Solution s;

	return 0;
}