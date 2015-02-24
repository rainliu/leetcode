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
https://oj.leetcode.com/problems/3sum-closest/

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
    	
    	int m=num[0]+num[1]+num[2];
    	int n=num.size();
    	int k=0;
    	while(k<n-2){
    		
    		int b = k+1;
    		int e = n-1;
    		while(b<e){
    			if(num[k]+num[b]+num[e]==target){
    				return target;
    			}else if(num[k]+num[b]+num[e]>target){
    				if(abs(num[k]+num[b]+num[e]-target)<abs(m-target)){
    					m=num[k]+num[b]+num[e];
    				}
    				int i=e;
					do{
						--i;
					}while(b<i&&num[i]==num[e]);
					e=i;
    			}else{
    				if(abs(num[k]+num[b]+num[e]-target)<abs(m-target)){
    					m=num[k]+num[b]+num[e];
    				}
    				int i=b;
					do{
						++i;
					}while(i<b&&num[i]==num[b]);
					b=i;
    			}
    		}

    		int i=k;
    		do{
    			++i;
    		}while(i<n-2&&num[i]==num[k]);
    		k=i;
    	}	
    	return m;		
    }
};

int main(){
	Solution s;

	vector<int> num{-1,2,1,-4};
	cout<<s.threeSumClosest(num, 1)<<endl;

	return 0;
}