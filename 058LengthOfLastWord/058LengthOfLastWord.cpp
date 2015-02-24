#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

/*
https://oj.leetcode.com/problems/length-of-last-word/

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	int b=0; 
    	int e=int(strlen(s))-1;
    	
    	//remove space at begin and end;
    	while(b<=e&&s[b]==' ') ++b;
    	while(b<=e&&s[e]==' ') --e;

    	//reverse serach last word
    	int l = 0;
    	while(b<=e&&s[e]!=' ') {--e; l++;}

     	return l;   
    }
};

int main(){
	Solution s;
	{
		const char *str = "   Hello   word   ";
		cout<<s.lengthOfLastWord(str)<<endl;
	}
	{
		const char *str = "   ";
		cout<<s.lengthOfLastWord(str)<<endl;
	}
	{
		const char *str = "";
		cout<<s.lengthOfLastWord(str)<<endl;
	}
	return 0;
}