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
https://oj.leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

class Solution {
public:
    int reverse(int x) {
    	long long xx = (long long)x;
    	bool neg = false;
        if(xx<0){
        	neg = true;
        	xx  = -xx;
        }

        long long rx = 0;    
        while(xx>0){
        	rx =(xx%10)+rx*10;
        	xx/=10;
        }

        if(neg){
        	rx = -rx;
        }

        return rx>numeric_limits<int>::max()||rx<numeric_limits<int>::min() ? 0 : rx;
    }
};

int main(){
	Solution s;

	cout<<s.reverse(123)<<endl;
	cout<<s.reverse(-120)<<endl;
	cout<<s.reverse(-1000000003)<<endl;

	return 0;
}