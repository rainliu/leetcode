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
https://oj.leetcode.com/problems/pascals-triangle-ii/

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 0);    

        for(int j=0; j<=rowIndex; ++j){
            for(int i=j; i>=0; --i){
                if(j==0) row[i]=1;
                else     row[i]+=(i-1>=0)?row[i-1]:0;
            }
        }

        return row;
    }
};

int main(){
	Solution s;

	auto output = s.getRow(3);

	for(const auto &p : output){
		cout<<p<<" ";
	}
    cout<<endl;

	return 0;
}