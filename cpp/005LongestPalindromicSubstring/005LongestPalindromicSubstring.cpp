#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
    	int size = s.size();
    	if(size==0||size==1) return s;

    	int max = 0, b = 0, e = size-1;
    	for(int i=0; i<size; i++){
    		int len1 = expandCenter(s, i, i); 
    		int len2 = expandCenter(s, i, i+1);
    		if(len1*2-1>len2*2){
    			if(len1*2-1>max){
    				max = len1*2-1;
    				b = i-(len1-1);
    				e = i+(len1-1);
    			}
    		}else{
    			if(len2*2>max){
    				max = len2*2;
    				b = i-(len2-1);
    				e = i+1+(len2-1);
    			}
    		}
    	}
    	
  		return s.substr(b, e-b+1);
    }

    int expandCenter(string s, int l, int r){
    	int b = 0;
    	int e = s.size()-1;
    	int len = 0;
    	while(l>=b && r<=e){
    		if(s[l]!=s[r]){
    			break;
    		}
    		len++;
    		l--;
    		r++;
    	}

    	return len;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
    	int size = s.size();
    	if(size==0||size==1) return s;

    	int max=0, b=0, e=size-1;
    	int L=0, R=size-1;
    	int l, r;

    	while(L<size-max){
    		l=L; r=R;
    		while(l<r&&s[l]!=s[r]) --r;
    		
    		int  plen = r-l+1;
    		int  pb   = l;
    		int  pe   = r;

    		do{
		    	bool palindrome = true;
		    	while(l<r){
		    		if(s[l]!=s[r]){
		    			palindrome = false;
		    			break;
		    		}
		    		++l;
		    		--r;
		    	}
		    	if(palindrome){
		    		if(plen > max){
		    			max = plen;
		    			b = pb;
		    			e = pe;
		    		}
		    	}
		    	pe--;
		    	plen--;
		    	r=pe;
		    	l=pb;
		    }while(l<r && plen>max);
	    	L++;
	    }
  		
  		return s.substr(b, e-b+1);
    }
};


int main(){
	Solution s;

	cout<<s.longestPalindrome("a")<<endl;
	cout<<s.longestPalindrome("aba")<<endl;
	cout<<s.longestPalindrome("aaabaaaa")<<endl;
	cout<<s.longestPalindrome("abb")<<endl;
	return 0;
} 