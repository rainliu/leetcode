#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
     	int low = 0;
     	int hig = n-1;
     	int mid;
        while(low<=hig){
     		mid = low + (hig-low)/2;
     	
     		if(A[mid]<target){
     			low = mid+1;
     		}else if(A[mid]>target){
     			hig = mid-1;
     		}else{
     			return mid; 
     		}
     	}

     	return A[mid]<target ? mid+1 : mid;
    }
};



int main(){
	Solution s;

	int A[] = {1, 3, 5, 6};

	cout << 5 << "->" << s.searchInsert(A, 4, 5) <<endl;
	cout << 2 << "->" << s.searchInsert(A, 4, 2) <<endl;
	cout << 7 << "->" << s.searchInsert(A, 4, 7) <<endl;
	cout << 0 << "->" << s.searchInsert(A, 4, 0) <<endl;

    int A2[] = {1, 3};
    cout << 2 << "->" << s.searchInsert(A2, 2, 2) <<endl;
	return 0;
} 