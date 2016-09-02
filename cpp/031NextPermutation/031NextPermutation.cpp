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
https://oj.leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into 
the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order
 (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	int n = num.size();
    	if(n<=1) return;

    	if(is_sorted(num.rbegin(), num.rend())){
    		reverse(num.begin(), num.end());
    	}else{
    		int i, j, k;
    		for(i=n-2; i>=0; --i){
    			if(num[i]<num[i+1]){
    				break;
    			}
    		}
    		
    		//find k which is minimal value > i 
    		k = i+1;
    		for(j=i+2; j<n; ++j){
    			if(num[j]>num[i]&&num[j]<num[k]){
    				k = j;
    			}
    		}

    		int tmp = num[k];
    		num[k] = num[i];
    		num[i] = tmp;

    		sort(num.begin()+i+1, num.end());
    	}
    }
};

int main(){
	Solution s;
	{
		vector<int> t1{1,2,3};
		s.nextPermutation(t1);
		for(const auto &p : t1){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	{
		vector<int> t2{3,2,1};
		s.nextPermutation(t2);
		for(const auto &p : t2){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	{
		vector<int> t3{1,1,5};
		s.nextPermutation(t3);
		for(const auto &p : t3){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	{
		vector<int> t1{1,3,2};
		s.nextPermutation(t1);
		for(const auto &p : t1){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	{
		vector<int> t1{2,3,1};
		s.nextPermutation(t1);
		for(const auto &p : t1){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}