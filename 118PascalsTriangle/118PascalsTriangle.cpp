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
https://oj.leetcode.com/problems/pascals-triangle/

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> rows;
        if(numRows<=0) return rows;

        for(int j=0; j<numRows; ++j){
        	vector<int> row;
        	for(int i=0; i<=j; ++i){
        		if(j==0) row.push_back(1);
        		else{
        			int s = 0;
        			if(i-1>=0) s+=rows[j-1][i-1];
        			if(i<=j-1) s+=rows[j-1][i];
        			row.push_back(s);
        		}
        	}
        	rows.push_back(row);
        }
        return rows;
    }
};

int main(){
	Solution s;

	auto output = s.generate(5);

	for(const auto &p : output){
		for(const auto &q : p){
			cout<<q<<" ";
		}
		cout<<endl;
	}

	return 0;
}