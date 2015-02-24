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
https://oj.leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
    	string o;
    	int m = a.size();
    	int n = b.size();
    	if(m>=n){
    		o = a;
    	}else{
    		return addBinary(b, a);
    	}  	
    	char c = 0;
    	for(int i=0; i<n; ++i){
    		c += a[m-1-i]-'0'+b[n-1-i]-'0';
    		o[m-1-i]= (c&0x1)+'0';
    		c >>= 1; 
    	}
    	for(int i=0; i<m-n; ++i){
    		c += a[m-n-1-i]-'0';
    		o[m-n-1-i] = (c&0x1)+'0';
    		c >>= 1;
    	}

    	return c==1? "1"+o: o; 
    }
};

int main(){
	Solution s;

	cout<<s.addBinary("11", "1")<<endl;

	return 0;
}