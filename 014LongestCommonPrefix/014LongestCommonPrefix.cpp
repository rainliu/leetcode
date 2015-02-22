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
https://oj.leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.size()==0) return "";
    	
        int size = numeric_limits<int>::max();
        for(int i=0; i<strs.size(); ++i){
        	if(strs[i].size()<size){
        		size = strs[i].size();
        	}
        }

        ostringstream oss;
        for(int i=0; i<size; ++i){
        	char c = strs[0][i];
        	for(int j=1; j<strs.size(); ++j){
        		if(c!=strs[j][i]){
        			return oss.str();
        		}
        	}
        	oss<<c;
        }

        return oss.str();
    }
};

int main(){
	Solution s;

	vector<string> strs {
		"abcdefghig",
		"abcdefghigdsfsdfsdf",
		"abcdefghigasdfasdf",
		"abcdefghigsdfsdfw",
		"abcdefghigsdfdf",
		"abcdefghigsf",
	};

	cout<<s.longestCommonPrefix(strs)<<endl;

	return 0;
}