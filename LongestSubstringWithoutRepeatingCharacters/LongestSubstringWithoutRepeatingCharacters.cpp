#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     	int max=0, j;
     	unordered_map<char, int> substrmap;
     	for(int i=0; i<s.size(); ++i){
     		char c = s[i];
     		auto p = substrmap.find(c);
     		if(p!=substrmap.end()){
     			if(substrmap.size()>max){
     				max = substrmap.size();
     			}
     			j=p->second;
     			auto pp=substrmap.begin();
     			while(pp!=substrmap.end()){
     				if(pp->second<=j){
     					pp=substrmap.erase(pp);
     				}else{
     					++pp;
     				}
     			}
     		}
     		substrmap[c]=i;
     	}
     	if(substrmap.size()>max){
			max = substrmap.size();
		}
     	return max;   
    }
};

int main(){
	Solution s;

	cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
	cout<<s.lengthOfLongestSubstring("bbbbb")<<endl;
	cout<<s.lengthOfLongestSubstring("c")<<endl;
	cout<<s.lengthOfLongestSubstring("aab")<<endl;
	cout<<s.lengthOfLongestSubstring("dvdf")<<endl;
	cout<<s.lengthOfLongestSubstring("asljlj")<<endl;
	
	return 0;
} 