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
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
    	/*
    	vector<int> n1(n+1);

    	n1[0] = 1;
    	for(int i=1;i<n+1; i++){
    		n1[i] = i*n1[i-1];
    	}   

    	int low = 1;
    	int hig = n;
    	int mid;
    	while(low<=hig){
    		mid = low+(hig-low)/2;
    		if(n1[mid]==k) {hig = mid; break;}
    		else if(n1[mid]>k) hig = mid-1;
    		else low = mid+1;
    	} 

		*/
    }
};

int main(){
	Solution s;

	return 0;
}