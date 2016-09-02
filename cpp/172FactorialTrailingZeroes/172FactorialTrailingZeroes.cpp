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
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        do{
        	n /= 5;
        	sum+=n;
        }while(n);

        return sum;
    }
};

int main(){
	Solution s;

	return 0;
}