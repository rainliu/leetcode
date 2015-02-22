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
https://oj.leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


/////////////////////////////////////////
ZigZag[0][i] = ZigZag[nRow-1][i-1] + (nRows-1)

for j=[1, nRow-2] {
	ZigZag[j][2i  ] = ZigZag[0][i]   + j            
	ZigZag[j][2i+1] = ZigZag[nRow-1][i] +(nRows-1-j)
}

ZigZag[nRows-1][i] = ZigZag[0][i] + (nRows-1)
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1) return s;

        ostringstream oss;
        int size = s.size();
        for(int j=0; j<nRows; j++){
        	int i=0;
        	int k;
        	while( (k=ZigZag(nRows, j, i++)) < size ) oss<<s[k];
        }
        return oss.str();
    }

    int ZigZag(int nRows, int j, int i){
    	if(i==0) return j;

    	if(j==0){
    		return ZigZag(nRows, nRows-1, i-1) + nRows-1;
    	}else if(j==nRows-1){
    		return ZigZag(nRows, 0,       i  ) + nRows-1;
    	}else{
    		if(i&0x1){//odd
    			return ZigZag(nRows, nRows-1, i/2) + nRows-1-j;
    		}else{//even
    			return ZigZag(nRows, 0,       i/2) + j;
    		}
    	}
    }
};

int main(){
	Solution s;

	cout<<s.convert("PAYPALISHIRING", 1)<<endl;
	cout<<s.convert("PAYPALISHIRING", 2)<<endl;
	cout<<s.convert("PAYPALISHIRING", 3)<<endl;

	return 0;
}