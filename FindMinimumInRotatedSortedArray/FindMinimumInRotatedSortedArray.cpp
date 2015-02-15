#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
    	int l = 0;
    	int h = num.size()-1;
    	int m;

    	while(l<h){
    		m = l+(h-l)/2;
    		if(num[m]<num[h] && num[h]<num[l]){
    			h = m;
    		}else if(num[m]>num[l] && num[l]>num[h]){
    			l = m;
    		}else{
    			if(num[m]==num[l] && num[l]>num[h]){
    				return num[h];
    			}else{
    				return num[l];
    			}
    		}
    	}


    	return num[l];    
    }
};


int main(){
	Solution s;

	{	
		vector<int> num = {4, 5, 6, 7, 0, 1, 2};
		cout << s.findMin(num) << endl;
	}

	{	
		vector<int> num = {4, 5, 6, 0, 1, 2};
		cout << s.findMin(num) << endl;
	}

	{	
		vector<int> num = {4, 5, 0, 1, 2, 3};
		cout << s.findMin(num) << endl;
	}


	{	
		vector<int> num = {0};
		cout << s.findMin(num) << endl;
	}
	
	return 0;
} 