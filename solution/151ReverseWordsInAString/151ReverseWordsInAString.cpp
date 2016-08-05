#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

#define isSpace(c) ((c)==' ')

class Solution {
public:
    void reverseWords(string &s) {
        int l=0, r=s.size()-1, c, l2, b, e;
        char t;
        while(isSpace(s[l])){
        	l++;
        }
        while(isSpace(s[r])){
        	r--;
        }
        c=l; l2=l;
        //cout<<s.substr(l2, r-l2+1)<<"#"<<endl;
        while(l<r){
        	while(c<=r&&!isSpace(s[c])){
        		c++;
        	}
        	b=l; e=c-1;
        	while(b<e){
        		t=s[b];
        		s[b]=s[e];
        		s[e]=t;
        		b++;
        		e--;
        	}
        	while(c<=r&&isSpace(s[c])){
        		c++;
        	}
        	l=c;
        }
        //cout<<s.substr(l2, r-l2+1)<<"#"<<endl;

        b=l2; e=r;
        while(b<e){
        	t=s[b];
        	s[b]=s[e];
        	s[e]=t;
        	b++;
        	e--;
        }
        ostringstream oss;

        b=l2; e=r;
        while(b<=e){
        	while(b+1<e&&isSpace(s[b])&&isSpace(s[b+1])){
        		b++;
        	}
        	oss<<s[b];
        	b++;
        }
        s=oss.str();
        //s = s.substr(l2, r-l2+1);
    }
};


int main(){
	Solution s;
	string str = "  the   sky   is    blue   ";
	s.reverseWords(str);
	cout<<str<<"#"<<endl;
	return 0;
} 