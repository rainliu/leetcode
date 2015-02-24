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
https://oj.leetcode.com/problems/plus-one/

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	int n=digits.size();
    	int c=1;
    	for(int i=n-1; i>=0; --i){
    		digits[i] +=c;
    		if(digits[i]==10){
    			digits[i]=0;
    			c=1;
    		}else{
    			c=0;
    		}
    	}
    	if(c>0){
    		digits.insert(digits.begin(), c);
    	}
  		return digits;      
    }
};

int main(){
	Solution s;
	vector<int> digits{9,9};
	auto q = s.plusOne(digits);
	for(const auto &p:q){
		cout<<p;
	}
	cout<<endl;
	return 0;
}