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
https://oj.leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	vector<vector<int>> v;
    	int n = num.size();    
    	if(n<4) return v;

    	sort(num.begin(), num.end());

    	int k=0;
    	while(k<n-3){
    		auto u = threeSum(num, k+1, n, target-num[k]);
    		for(const auto &p:u){
    			v.push_back(vector<int>{num[k], p[0], p[1], p[2]});
    		}

    		int i=k;
    		do{
    			++i;
    		}while(i<n-2&&num[i]==num[k]);
    		k=i;
    	}

    	return v;
    }

    vector<vector<int> > threeSum(vector<int> &num, int m, int n, int target) {
    	vector<vector<int>> v3;
    	
    	int k=m;
    	while(k<n-2){
    		
    		int b = k+1;
    		int e = n-1;
    		while(b<e){
    			if(num[b]+num[e]==target-num[k]){
    				v3.push_back(vector<int>{num[k],num[b],num[e]});
    				int i=b;
					do{
						++i;
					}while(i<b&&num[i]==num[b]);
					b=i;

					i=e;
					do{
						--i;
					}while(b<i&&num[i]==num[e]);
					e=i;
    			}else if(num[b]+num[e]>target-num[k]){
    				int i=e;
					do{
						--i;
					}while(b<i&&num[i]==num[e]);
					e=i;
    			}else{
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
    	return v3;		
    }
};

int main(){
	Solution s;

	vector<int> num {1, 0, -1, 0, -2, 2};
	int target = 0;
	auto output = s.fourSum(num, target);
	for(const auto &p:output){
		cout<<p[0]<<","<<p[1]<<","<<p[2]<<","<<p[3]<<endl;
	}

	return 0;
}