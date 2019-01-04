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
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	int i=-1, c=0;
    	int p=0, q=0;
	    while(q<n){
	    	while(q<n&&A[p]==A[q]){
	    		c++;
	    		A[i+c]=A[q];
	    		q++;
	    	}
	    	if(c<=2){
	    		i+=c;
	    	}else{
	    		i+=2;
	    	}
	    	c=0;
	    	p=q;
	    }
	    return i+1;
    }
};

int main(){
	return 0;
}