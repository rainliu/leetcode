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
https://oj.leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	sort(A, A+n);

    	int j=0;        	
		while(j<n&&A[j]!=elem){
			j++;
		}
		int i=j;
		while(j<n&&A[j]==elem){
			j++;
		}
		while(j<n){
			A[i++]=A[j++];
		}

		return i;
    }
};

int main(){
	Solution s;

	return 0;
}