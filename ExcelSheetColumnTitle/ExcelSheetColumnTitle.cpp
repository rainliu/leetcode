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
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
*/

class Solution {
public:
    string convertToTitle(int n) {
    	ostringstream oss;
    	do{
    		oss<<char((n-1)%26+'A');
    		n=(n-1)/26;	
    	}while(n>0);
    	string str = oss.str();
    	ostringstream oss_reverse;
    	int size = str.size();
    	for(int i=size-1; i>=0; --i){
    		oss_reverse<<str[i];
    	}
    	return oss_reverse.str();
    }
};

int main(){
	Solution s;


	cout<<s.convertToTitle(1)<<endl;
	cout<<s.convertToTitle(26)<<endl;

	cout<<s.convertToTitle(27)<<endl;
	cout<<s.convertToTitle(52)<<endl;

	cout<<s.convertToTitle(1*26*26+1*26+26)<<endl;

	return 0;
}