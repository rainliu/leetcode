#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> diff_map;
        vector<int> result;

        for(int i=0; i<numbers.size(); i++){
        	diff_map[target-numbers[i]] = i; 
        }

        for(int i=0; i<numbers.size(); i++){
        	if(diff_map.find(numbers[i])!=diff_map.end()){
        		result.push_back(i+1);
        		result.push_back(diff_map[numbers[i]]+1);
        		return result;
        	}
        }
    
    	return result;
    }
};

int main(){
	Solution s;

	return 0;
} 