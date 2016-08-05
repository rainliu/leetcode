#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
    	unordered_map<int, int> memap;
    	int halfn = num.size()/2;
    	for(const int &x : num){
    		if(memap.find(x)!=memap.end()){
    			memap[x]++;
    			if(memap[x]>halfn)
    				return x;
    		}else{
    			memap[x]=1;
    		}
    	}    

    	return num[0];
    }
};

int main(){
	Solution s;

	return 0;
}