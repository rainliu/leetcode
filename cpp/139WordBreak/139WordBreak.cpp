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
https://oj.leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

E[j] = true, if (s[0, j] in dict) or (E[k]==true and s[k+1, j] in dict) k=[0, j)
     = false, otherwise can't find k
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	int n = s.size();
    	if(n==0) return false;

    	vector<bool> E(n+1, false);

    	for(int j=1; j<n+1; ++j){    		
    		if(dict.find(s.substr(0, j))!=dict.end()){
    			E[j] = true;
    		}else{
    			E[j] = false;
    			for(int k=1; k<j; ++k){
    				if(E[k]==true&&k<j&&dict.find(s.substr(k, j-k))!=dict.end()){
    					E[j] = true;
    					break;
    				}
    			}
    		}    		
    	}

    	return E[n];
    }
};

int main(){
	Solution s;
	{
		unordered_set<string> dict{
			"aaaa",
			"aa",
		};
		cout<<s.wordBreak("aaaaaaa", dict)<<endl;
	}
	
	return 0;
}