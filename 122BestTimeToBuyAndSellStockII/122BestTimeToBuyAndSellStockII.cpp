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
https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

E[i, j] = max(E[i, j-1]+diff(j-1, j), E[i, j-1], diff(i, j)),   if diff(i, j)>=0
        = max(E[i, j-1]+diff(j-1, j), E[i, j-1]), and update i, otherwise
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
    	if(n<=1) return 0;

        vector<int> E(n, 0);
        int i = 0;
        E[0] = 0;
        for(int j=1; j<n; ++j){
        	if(prices[j]-prices[i]>=0){
        		E[j] = max(E[j-1], prices[j]-prices[i]);
        	}else{
        		E[j] = E[j-1];
        		i = j;
        	}
        	if(prices[j]-prices[j-1]>=0){
        		E[j] = max(E[j-1]+prices[j]-prices[j-1], E[j]);
        	}
        }

        return E[n-1];
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