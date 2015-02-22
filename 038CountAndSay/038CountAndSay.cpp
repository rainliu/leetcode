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
https://oj.leetcode.com/problems/count-and-say/

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ... (312211, 13112221, 1113213211...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
    	if(n<=0) return "";

    	string str="1";
    	while(--n){
    		str = countSay(str);
    	}
        return str;	
    }

    string countSay(string str){
    	ostringstream oss;

    	int size = str.size();
    	int i=0, j, count;
    	while(i<size){
    		j=i;
    		
    		count=0;
    		while(j<size&&str[j]==str[i]){
    			count++;
    			j++;
    		}	
    		oss<<count<<str[i];
    		i=j;
    	}

    	return oss.str();
    }
};

int main(){
	Solution s;

	cout<<s.countAndSay(1)<<endl;
	cout<<s.countAndSay(2)<<endl;
	cout<<s.countAndSay(3)<<endl;
	cout<<s.countAndSay(4)<<endl;
	cout<<s.countAndSay(5)<<endl;
	cout<<s.countAndSay(6)<<endl;
	return 0;
}