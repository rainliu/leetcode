class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = haystack.size();
        int M = needle.size();
        vector<int> right(128, -1);
        for(int j=0; j<M; ++j){
            right[needle[j]] = j;
        }
        int skip;
        for(int i=0; i<=N-M; i+=skip){
            skip = 0;
            for(int j=M-1; j>=0; --j){
                if(needle[j]!=haystack[i+j]){
                    skip=max(1, j-right[haystack[i+j]]);
                    break;
                }
            }
            if(skip==0) return i;
        }
        return -1;
    }
};

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still 
see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	if(haystack==NULL || needle==NULL) return -1;

    	int hsize = strlen(haystack);
    	int nsize = strlen(needle);
    	
    	if(hsize<nsize) return -1;    
    	
    	for(int i=0; i<=hsize-nsize; i++){
    		bool ret = true;
    		for(int j=0; j<nsize; j++){
    			if(haystack[i+j]!=needle[j]){
    				ret = false;
    				break;
    			}
    		}
    		if(ret) return i;
    	}

    	return -1;
    }
};



int main(){
	Solution s;
	char haystack[] = "abcdefg";
	char needle1[] = "cde";
	char needle2[] = "cdxe";

	cout << s.strStr(haystack, needle1) << endl;
	cout << s.strStr(haystack, needle2) << endl;

	return 0;
} 
