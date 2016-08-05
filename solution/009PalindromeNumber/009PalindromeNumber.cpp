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
https://oj.leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, 
note the restriction of using extra space.

You could also try reversing an integer. 
However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    bool isPalindrome(int x) {
    	long long xx = x;
    	long long rx = 0;
    	while(xx>0){
    		rx = rx*10+xx%10;
    		xx/=10;
    	}    	
    	return x==rx;
    }
};

int main(){
	Solution s;

	cout<<s.isPalindrome(-121)<<endl;
	cout<<s.isPalindrome(0)<<endl;
	cout<<s.isPalindrome(1234)<<endl;
	cout<<s.isPalindrome(1221)<<endl;
	cout<<s.isPalindrome(121)<<endl;

	return 0;
}