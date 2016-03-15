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
https://oj.leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(int A[], int n) {
    	if(n<=1) return;

    	int i=0, j=n-1, k=0;
    	while(A[i]==0) i++;
		while(A[j]==2) j--;

		k=i;
		while(A[k]==1) k++;
		
		while(k<=j){
			if(A[k]==1) k++;
			else if(A[k]==0) swap(A, i++, k++);
			else swap(A, k, j--);
		}
    }

    void swap(int A[], int i, int j){
    	int tmp = A[i];
    	A[i] = A[j];
    	A[j] = tmp;
    }
};


class Solution2 {
public:
    void sortColors(int A[], int n) {
		countingSort(A, n, 3);        
    }

    void countingSort(int A[], int n, int r){
    	vector<int> B(1+r, 0);
    	for(int i=0; i<n; i++){
    		for(int j=0; j<r; j++){
    			B[1+j]+=A[i]==j;
    		}
    	}
    	for(int j=1;j<r+1; j++){
    		B[j]+=B[j-1];
    	}
    	for(int i=0; i<B[1+0]; i++){
    		A[i]=0;
    	}
    	for(int i=B[1+0]; i<B[1+1]; i++){
    		A[i]=1;
    	}
    	for(int i=B[1+1]; i<B[1+2]; i++){
    		A[i]=2;
    	}
    }
};

int main(){
	return 0;
}