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
https://oj.leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> v(2, 0);
        
        int n = numbers.size();
        if(n<2) return v;

        unordered_map<int, int> m;

        for(int i=0; i<n; ++i){
        	m[numbers[i]] = i;
        }

        for(int i=0; i<n; ++i){
        	if(m.find(target-numbers[i])!=m.end()&&m[target-numbers[i]]!=i){
        		return vector<int>{i+1, m[target-numbers[i]]+1};
        	}
        }

        return v;
    }
};

int main(){
	Solution s;
	
	vector<int> numbers {2, 7, 11, 15};
	auto output = s.twoSum(numbers, 9);
	cout<<output[0]<<","<<output[1]<<endl;

	return 0;
}