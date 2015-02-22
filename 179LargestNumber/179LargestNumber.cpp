#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <assert.h>

using namespace std;

/*
https://oj.leetcode.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
class Solution {
public:
    string largestNumber(vector<int> &num) {
    	vector<string> numstr;
    	int size = num.size();
    	for(int i=0; i<size; ++i){
    		numstr.push_back(to_string(num[i]));
    	}
        
    	sort(numstr.begin(), numstr.end(), [](const string &a, const string &b){
    		return (a+b)<(b+a);
    	});

    	ostringstream oss;
    	bool nonzero = false;
    	for(int i=size-1; i>=0; --i){
    		if(!nonzero){
    			nonzero = numstr[i]!="0";
    		}
    		if(nonzero){
    			oss<<numstr[i];
    		}
    	}
    	if(!nonzero) return "0";
    	else return oss.str();
    }
};


class Solution2 {
public:
    string largestNumber(vector<int> &num) {
    	vector<string> numstr;
    	int size = num.size();
    	for(int i=0; i<size; ++i){
    		numstr.push_back(to_string(num[i]));
    	}
        
    	quickSort(numstr, 0, size-1);

    	ostringstream oss;
    	bool nonzero = false;
    	for(int i=size-1; i>=0; --i){
    		if(!nonzero){
    			nonzero = numstr[i]!="0";
    		}
    		if(nonzero){
    			oss<<numstr[i];
    		}
    	}
    	if(!nonzero) return "0";
    	else return oss.str();
    }

    void quickSort(vector<string> &numstr, int low, int high){
    	if(low>=high) return;

    	int i=low+1;
    	int j=high;
    	
    	while( LessThan(numstr[i], numstr[low])&&i<=j) i++;
    	while(!LessThan(numstr[j], numstr[low])&&i<=j) j--;
    	
    	while(i<=j){
    		swap(numstr, i++, j--);
    	}
    	swap(numstr, j, low);

    	quickSort(numstr, low, j-1);
    	quickSort(numstr, j+1, high);
    }

    void swap(vector<string> &numstr, int i, int j){
    	string tmp = numstr[i];
    	numstr[i]  = numstr[j];
    	numstr[j]  = tmp;
    }

    bool LessThan(string a, string b){
    	string ab = a+b;
    	string ba = b+a;

    	return ab<ba;
    	/*for(int i=0; i<ab.size(); i++){
    		if(ab[i]>ba[i]) return false;
    	}
    	return true;*/
    }
};

int main(){
	Solution s;
	{
		vector<int> num{1, 1, 1};
		cout<<s.largestNumber(num)<<endl;
	}
	{
		vector<int> num{2, 1};
		cout<<s.largestNumber(num)<<endl;
	}
	{
		vector<int> num{0, 0};
		cout<<s.largestNumber(num)<<endl;
	}
	return 0;
}