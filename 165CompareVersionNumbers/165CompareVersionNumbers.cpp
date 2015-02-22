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
https://oj.leetcode.com/problems/compare-version-numbers/

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int f1=0, f2=0;
    	int p1=0, p2=0;
    	int i1=0, i2=0;
    	int s1=version1.size(), s2=version2.size();

    	while(p1<s1||p2<s2){
	    	f1=0; f2=0;
	    	i1=p1; i2=p2;
	    	while(p1<s1&&version1[p1]!='.'){
	    		p1++;
	    	}
	    	while(p2<s2&&version2[p2]!='.'){
	    		p2++;
	    	}
	    
	    	stringstream ss1, ss2;
	    	if(p1<=s1){
				ss1<<version1.substr(i1, p1-i1); 
		    	ss1>>f1;
		    }
		    if(p2<=s2){
		    	ss2<<version2.substr(i2, p2-i2); 
		    	ss2>>f2;
		    }
	    	
	    	if(f1>f2) return 1;
	    	else if (f1<f2) return -1;

	    	p1++; p2++;
    	}

    	return 0;
    }
};

int main(){
	Solution s;

	cout<<s.compareVersion("0.1", "1.1")<<endl;
	cout<<s.compareVersion("1.1", "1.10")<<endl;
	cout<<s.compareVersion("1.2", "13.37")<<endl;
	cout<<s.compareVersion("0.1", "1")<<endl;
	cout<<s.compareVersion("1.2", "1")<<endl;
	cout<<s.compareVersion("10.6.5", "10.6")<<endl;
	cout<<s.compareVersion("10.0.0", "10")<<endl;
	return 0;
}