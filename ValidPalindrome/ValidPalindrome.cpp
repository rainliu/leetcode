#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
      	transform(s.begin(), s.end(), s.begin(), ::tolower);
		
        ostringstream ss;
        for(auto p = s.begin(); p!=s.end(); ++p){
        	char c = *p;
        	if( (c>='0' && c<='9') || (c>='a' && c<='z') ){
        		ss << c;
        	} 
        }
        s = ss.str();
        
        if(s.size()==0) return true;

        int i = 0;
        int j = s.size()-1;
        while(i<j){
        	char c = s[i];
        	s[i] = s[j];
        	s[j] = c;
        	++i;
        	--j;
        }

        return s==ss.str();
    }
};


int main(){
	Solution s;

	string a1= "A man, a plan, a canal: Panama";
	string a2= "race a car";
	string a3= "a MAN 123 3 2 1 nAMA";

	cout<<s.isPalindrome(a1)<<endl;
	cout<<s.isPalindrome(a2)<<endl;
	cout<<s.isPalindrome(a3)<<endl;

	return 0;
} 