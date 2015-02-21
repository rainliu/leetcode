#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given two words (start and end), and a dictionary, 
find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		dict.insert(end);
    	queue<pair<string, int>> q;
    	q.push(make_pair(start,1));
    	while(!q.empty()){
    		auto p = q.front(); q.pop();

    		if(p.first==end) return p.second;

    		for(int j=0; j<p.first.size(); j++){
		    	for(char c='a'; c<='z'; ++c){
		    		if(p.first[j]==c) continue;
		    		string cpy = p.first;		
		    		cpy[j]=c;
		    		
		    		if(dict.find(cpy)!=dict.end()){
		    			q.push(make_pair(cpy,p.second+1));
		    			dict.erase(cpy); 
		    		}
		    	}
			}
    	}

    	return 0;
    }
};


class Solution2 {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
    	unordered_map<string, bool> m;
    	for(const auto &pp : dict){
    		if(oneLetterDiff(end, pp)){
    			m[pp]=true;
    		}
    	}
    	if(m.size()==0) return 0;

    	queue<string> q;
    	queue<int> p;
    	q.push(start); p.push(0);
    	while(!q.empty()){
    		string str = q.front(); q.pop();
    		int   size = p.front(); p.pop();

    		for(const auto &pp : dict){
	    		if(oneLetterDiff(str, pp)){
	    			if(m.find(pp)!=m.end()){
	    				return size+2;
	    			}else{
	    				q.push(pp);
	    				p.push(size+1);
	    			}
	    		}
	    	}
    	}

    	return 0;
    }

    bool oneLetterDiff(string a, string b){
    	int sum=0;
    	for(int i=0; i<a.size(); i++){
    		sum+=a[i]!=b[i];
    		if(sum>1) return false;
    	}
    	return sum==1;
    }
};

int main(){
	return 0;
}