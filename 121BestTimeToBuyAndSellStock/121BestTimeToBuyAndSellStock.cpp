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
https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

E[i, j] = max(E[i, j-1], diff(i, j)), if diff(i, j)>=0
        = 0,   and update i,		  otherwise
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int n = prices.size();
    	if(n<=1) return 0;

        vector<int> E(n, 0);
        int i = 0, m = 0;
        E[0] = 0;
        for(int j=1; j<n; ++j){
        	if(prices[j]-prices[i]>=0){
        		E[j] = max(E[j-1], prices[j]-prices[i]);
        	}else{
        		E[j] = 0;
        		i = j;
        	}
        	if(E[j]>m){
        		m = E[j];
        	}
        }

        return m;
    }
};

int main(){
	Solution s;

	{
		vector<int> prices1{6, 1, 3, 2, 4, 7};
		cout<<s.maxProfit(prices1)<<endl;

		vector<int> prices2{3, 4, 5, 7, 1, 6};
		cout<<s.maxProfit(prices2)<<endl;
	}

	return 0;
}