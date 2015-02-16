#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

#define isSpace(c) ((c)==' ')

class Solution {
public:
    void reverseWords(string &s) {
        int l=0, r=s.size()-1, c, l2, b, e, b2;
        char t;
       
        while(isSpace(s[l])){
        	l++;
        }
        while(isSpace(s[r])){
        	r--;
        }

        //reverse word
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
        //reverse string
        b=l2; e=r;
        while(b<e){
        	t=s[b];
        	s[b]=s[e];
        	s[e]=t;
        	b++;
        	e--;
        }
        
        //cout<<s.substr(l2, r-l2+1)<<"#"<<endl;
        
        //remove extra space
        b=l2; e=r; b2=l2;
        while(b<=e){
        	while(b+1<e&&isSpace(s[b])&&isSpace(s[b+1])){
        		b++;
        	}
            b++;
            b2++;
            if(b!=b2){
            	for(int i=0;i<=e-b; i++){
                    s[b2+i] = s[b+i];
                }
                e-=(b-b2);
                //cout<<s.substr(l2, e-l2+1)<<"#"<<endl;
            }
            b=b2;
            //cout<<b<<" "<<b2<<endl;
        }
        s = s.substr(l2, e-l2+1);
    }
};


int main(){
	Solution s;
	string str = "  the   sky   is    blue   ";
	s.reverseWords(str);
	cout<<str<<"#"<<endl;
	return 0;
} 