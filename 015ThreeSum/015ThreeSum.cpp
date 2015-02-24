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
https://oj.leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int>> v3;
    	sort(num.begin(), num.end());
    	
    	int n=num.size();
    	int k=0;
    	while(k<n-2){
    		
    		int b = k+1;
    		int e = n-1;
    		while(b<e){
    			if(num[b]+num[e]==-num[k]){
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
    			}else if(num[b]+num[e]>-num[k]){
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

class Solution2 {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int>> v3;
    	int n = num.size();
        if(n<3) return v3;

        sort(num.begin(), num.end());

        vector<int> v2(2);
    	for(int i=0; i<n-2; ++i){
    		if(twoSum(v2, num, i+1, n-1, -num[i])){
    			vector<int> v;
    			v.push_back(num[i]);
    			v.push_back(v2[0]);
    			v.push_back(v2[1]);
    			v3.push_back(v);
    		}
    	}

    	return v3;
    }

    bool twoSum(vector<int> &v, vector<int> &numbers, int low, int high, int target) {
    	unordered_map<int, int> m;

        for(int i=low; i<=high; ++i){
        	if(m.find(numbers[i])!=m.end()){
        		m[numbers[i]] ++;
        	}else{
        		m[numbers[i]] = 1;
        	}
        }

        for(int i=low; i<=high; ++i){
        	if(target-numbers[i]==numbers[i]){
        		if(m[numbers[i]]>1){
        			v[0] = numbers[i];
        			v[1] = target-numbers[i];
        			return true;
        		}
        	}else if(m.find(target-numbers[i])!=m.end()){
        		v[0] = numbers[i]<target-numbers[i]?numbers[i]:target-numbers[i];
        		v[1] = numbers[i]<target-numbers[i]?target-numbers[i]:numbers[i];
        		return true;
        	}
        }

        return false;
    }
};

int main(){
	Solution s;

	return 0;
}