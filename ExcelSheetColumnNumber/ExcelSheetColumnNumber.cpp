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
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.


...M*26*26+N*26+X
(X=1..26)
*/
class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size();  //assert(size>0);
        int n = 0;
        int base = 1;
        for(int i=size-1; i>=0; --i){
            n+=((int)(s[i]-'A')+1)*base;
            base*=26;
        }
        return n;
    }

    string convertToTitle(int n) {
    	ostringstream oss;
    	do{
    		oss<<char((n-1)%26+'A');
    		n=(n-1)/26;	
    	}while(n>0);
    	string str = oss.str();
    	ostringstream oss_reverse;
    	int size = str.size();
    	for(int i=size-1; i>=0; --i){
    		oss_reverse<<str[i];
    	}
    	return oss_reverse.str();
    }
};

int main(){
	Solution s;

	cout<<s.titleToNumber("A")<<endl;
	cout<<s.titleToNumber("Z")<<endl;
	cout<<s.titleToNumber("AA")<<endl;
	cout<<s.titleToNumber("AZ")<<endl;
	cout<<s.titleToNumber("AAZ")<<endl;

	return 0;
}