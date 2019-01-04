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
https://oj.leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an, 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
    	int n = height.size();
    	int i=0, j=n-1, k;
    	int max = 0;
    	while(i<j){
			int area = (j-i)*min(height[i], height[j]);
			if(area>max){
				max = area;
			}
			if(height[i]<height[j]){
				k = i;
				do{
					++i;
				}while(height[i]<height[k]&&i<j);
			}else{
				k = j;
				do{
					--j;
				}while(height[j]<height[k]&&i<j);
			} 	
		}
    	return max;
    }
};

class Solution2 {
public:
    int maxArea(vector<int> &height) {
    	int n = height.size();
    	int i, j;

    	int max = 0;
    	for(i=0; i<n-1; ++i){
    		for(j=i+1; j<n; ++j){
    			int area = (j-i)*min(height[i], height[j]);
    			if(area>max){
    				max = area;
    			}
    		}
    	}

    	return max;
    }
};

int main(){
	return 0;
}