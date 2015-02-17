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
Given two strings S and T, determine if they are both one edit distance apart.
*/

#define MIN(a,b) ((a)<(b)?(a):(b))
#define DIFF(a,b) ((a)==(b)?0:1)

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
    	int size[2];
    	size[0] = s.size();
    	size[1] = t.size();
    	
    	if((size[0]==0 && size[1]==0) || abs(size[1]-size[0])>1) return false;
    	if((size[0]==0 && size[1]==1) || (size[1]==0 && size[0]==1)) return true;
		
    	int result=0;
    	if(size[0]==size[1]){
    		for(int i=0; i<size[0]; i++){
    			result += DIFF(s[i], t[i]);
    			if(result>1)
    				break;
    		}
    	}else if(size[0]<size[1]){
    		int i=0, j=0;
    		while(j<size[1]){
    			if(DIFF(s[i], t[j])){
    				result+=DIFF(s[i], t[j]);
    				j++;
    				if(result>1)
    					break;	
    			}else{
	    			i++;
	    			j++;
	    		}
    		}
    	}else{
    		int i=0, j=0;
    		while(i<size[0]){
    			if(DIFF(s[i], t[j])){
    				result+=DIFF(s[i], t[j]);
    				i++;
    				if(result>1)
    					break;	
    			}else{
	    			i++;
	    			j++;
	    		}
    		}
    	}

    	return result==1;
    }
};

class Solution2 {
public:
    bool isOneEditDistance(string s, string t) {
    	int size[2];
    	size[0] = s.size();
    	size[1] = t.size();

    	if((size[0]==0 && size[0]==0) || abs(size[1]-size[0])>1) return false;
    	if((size[0]==0 && size[1]==1) || (size[1]==0 && size[0]==1)) return true;

    	int **E;
    	E = new int*[size[0]+1];
    	for(int i=0; i<size[0]+1; i++){
    		E[i] = new int[size[1]+1];
    	}

    	for(int i=0; i<size[0]+1; i++){
    		E[i][0] = i;
    	}
    	for(int j=0; j<size[1]+1; j++){
    		E[0][j] = j;
    	}
    	for(int i=1; i<size[0]+1; i++){
    		for(int j=1; j<size[1]+1; j++){
    			E[i][j] = MIN(MIN(E[i-1][j]+1, E[i][j-1]+1), E[i-1][j-1]+DIFF(s[i-1], t[j-1]));
    		}
    	}
    	bool result = E[size[0]][size[1]]==1;

    	for(int i=0; i<size[0]+1; i++){
    		delete []E[i];
    	}
    	delete []E;

    	return result;
    }
};


int main(){
	Solution s;

	cout << s.isOneEditDistance("", "a") <<endl;

	return 0;
} 
