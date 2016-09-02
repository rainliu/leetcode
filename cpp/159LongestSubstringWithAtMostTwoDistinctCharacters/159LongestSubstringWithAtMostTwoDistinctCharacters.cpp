#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/
#define MIN(a, b) ((a)<(b)?(a):(b))
#define MAX(a, b) ((a)>(b)?(a):(b))

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int max=0, j;
     	unordered_map<char, int> substrmap1, substrmap2;
     	
     	for(int i=0; i<s.size(); ++i){
     		char c = s[i];
     		if(substrmap1.find(c)==substrmap1.end()){
     			if(substrmap1.size()>1){
     				auto p1=substrmap2.begin();
     				auto p2=++p1;//substrmap2.begin()+1;
     				p1=substrmap2.begin();
     				//cout<<p1->second<<" "<<p2->second<<endl;
     				if(p1->second>p2->second){
     					j = p2->second;
     					max = MAX(max, 1+p1->second - MIN(substrmap1[p2->first], substrmap1[p1->first]));
     					//cout<<" "<<p1->second<<" "<<MIN(substrmap1[p2->first], substrmap1[p1->first])<<endl;
     				}else{
     					j = p1->second;
     					max = MAX(max, 1+p2->second - MIN(substrmap1[p2->first], substrmap1[p1->first]));
     					//cout<<" "<<p2->second<<" "<<MIN(substrmap1[p2->first], substrmap1[p1->first])<<endl;
     				}
     				substrmap1.clear();
     				substrmap2.clear();
     				substrmap1[s[j+1]] = j+1;
     				substrmap2[s[i-1]] = i-1;
     			}
     			substrmap1[c]=i;
     		}
     		substrmap2[c]=i;
     	}
 		if(substrmap1.size()>1){
			auto p1=substrmap2.begin();
			auto p2=++p1;//substrmap2.begin()+1;
			p1=substrmap2.begin();
			//cout<<p1->second<<" "<<p2->second<<endl;
			if(p1->second>p2->second){
				max = MAX(max, 1+p1->second - MIN(substrmap1[p2->first], substrmap1[p1->first]));
			}else{
				max = MAX(max, 1+p2->second - MIN(substrmap1[p2->first], substrmap1[p1->first]));
			}
		}else if(max==0){
			max = s.size();
		}
 		
     	return max;   
    }
};


int main(){
	Solution s;

	cout<<s.lengthOfLongestSubstringTwoDistinct("eceba")<<endl;
	cout<<s.lengthOfLongestSubstringTwoDistinct("bbbbb")<<endl;
	cout<<s.lengthOfLongestSubstringTwoDistinct("c")<<endl;
	cout<<s.lengthOfLongestSubstringTwoDistinct("aab")<<endl;
	cout<<s.lengthOfLongestSubstringTwoDistinct("dvdf")<<endl;
	cout<<s.lengthOfLongestSubstringTwoDistinct("asljlj")<<endl;
	
	return 0;
} 