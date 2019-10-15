class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> D(n+1, 0);
        D[0]=n>0&&s[0]!='0';
        D[1]=D[0];
        for(int i=2; i<=n; ++i){
            int d = (s[i-2]-'0')*10+s[i-1]-'0';
            if(d==0) {
                return 0;
            }
            if(d>=10&&d<=26){
                D[i]+=D[i-2];
            }
            if(s[i-1]!='0'){
                D[i]+=D[i-1];    
            }
        }        
        return D[n];
    }
};

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

/*
https://oj.leetcode.com/problems/decode-ways/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

E[i] = E[i-1] + E[i-2], if i-2 has path to i
	 = E[i-1], otherwise
*/

class Solution {
public:
    int numDecodings(string s) {
    	int n = s.size();
    	if(n==0) return 0;
    	if(n==1) return s[0]=='0'?0:1;    	
    	if(s[0]=='0') return 0;

    	vector<int> E(n+1, 0);

    	E[0] = 1;
    	E[1] = 1;
    	for(int i=2; i<n+1; ++i){
    		if((s[i-2]=='0'||s[i-2]>'2')&&s[i-1]=='0'){
    			return 0;
    		}
    		else if((s[i-2]=='1'&&s[i-1]!='0')||(s[i-2]=='2'&&s[i-1]<='6'&&s[i-1]>'0')){
    			E[i] = E[i-1]+E[i-2];
    		}else{
    			if(s[i-1]!='0'){
    				E[i] = E[i-1];
    			}else{
    				E[i] = E[i-2];
    			}
    		}
    	}
    	return E[n];
    }
};

int main(){
	Solution s;

	cout<<s.numDecodings("12")<<endl;
	cout<<s.numDecodings("1")<<endl;
	cout<<s.numDecodings("1324")<<endl;

	return 0;
}
