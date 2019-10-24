class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); if(n==0) return -1;
        vector<int> diff(n, 0);
        int sum = 0, start = -1;
        for(int i=0; i<n; ++i){
            diff[i] = gas[i]-cost[i];
            sum += diff[i];
            if(diff[i]>=0&&start==-1){
                start = i;
            }
        }
        
        if(sum<0) return -1;
        while(start<n){
            sum = 0;
            for(int i=start; i<n; ++i){
                sum+=diff[i];
                if(sum<0){
                    start = i+1;
                    break;
                }
            }
            if(sum>=0){
                return start;
            }
        }
        return start>=n ? -1 : start;
    }
};

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
https://oj.leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int n = gas.size();
    	if(n==0) return -1;
    	if(n==1) return gas[0]>=cost[0]?0:-1;

    	vector<int> diff(n, 0);
    	int sum = 0;
    	for(int k=0; k<n; ++k){
    		diff[k] = gas[k]-cost[k];
    		sum+=diff[k];
    	}
    	if(sum<0) return -1;

    	int i=0;
    	while(i<n){	    	
	    	int j=i;
	    	sum = 0;
	    	do{		    		
	    		sum+=diff[j];
	    		j=(j+1)%n;
	    		if(sum<0){
	    			i=j;
	    			break;
	    		}	    		
	    	}while(j!=i);
	    	if(sum>=0) return i;
	    }	    

        return -1;
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int n = gas.size();
    	if(n==0) return -1;
    	if(n==1) return 0;

    	int left;
    	for(int k=0; k<n; ++k){
    		left=gas[k];
    		int i=k;
    		while(left-cost[i]>=0){
    			left-=cost[i];
    			i=(i+1)%n; if(i==k) return k;
    			left+=gas[i];
    		}
    	}
        return -1;
    }
};

int main(){
	return 0;
}
