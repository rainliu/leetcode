class Solution {
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //D[n]= max(D[k]) for k=0..n-1, if s[k..] is in wordDict
        int n = s.size();
        unordered_set<string> dict;
        for(const auto& word : wordDict){
            dict.insert(word);
        }
        unordered_map<int, bool> m;    
        return wordBreak(s, dict, n, m);
    }
    
    bool wordBreak(string& s, unordered_set<string>& dict, int n, unordered_map<int, bool>& m){
        if(n==0) return true;
        
        for(int k = n-1; k>=0; --k){
            if(dict.find(s.substr(k,n-k))!=dict.end()){
                bool d;
                if(m.find(k)!=m.end()){
                    d = m[k];
                }else{
                    d = wordBreak(s, dict, k, m);        
                    m[k] = d;
                }
                if(d){
                    return true;
                }
            }
        }
        return false;
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
