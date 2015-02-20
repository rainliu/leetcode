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
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> result(size1+size2+1, 0);

        for(int i=0; i<size1; ++i){
        	int n = int(num1[size1-1-i]-'0'); //cout<<n<<"*";
        	for(int j=0; j<size2; ++j){
        		int m = int(num2[size2-1-j]-'0');//cout<<m<<"=";
        		result[i+j] += m*n; //cout<<m*n<<endl;
        	}
        }
        for(int k=0; k<size1+size2; k++){
        	result[k+1]+=result[k]/10;
        	result[k] %=10;
        }

        ostringstream oss;
        bool nonzero = false;
        for(int k=size1+size2-1; k>=0; --k){
        	if(result[k]!=0) nonzero=true;
        	if(nonzero) oss<<result[k];
        }
        if(!nonzero) oss<<"0";

        return oss.str();
    }
};

int main(){
	Solution s;

	cout<<s.multiply("378", "43")<<endl;
	cout<<s.multiply("99", "99")<<endl;
	cout<<s.multiply("100", "100")<<endl;

	return 0;
}