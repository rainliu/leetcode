#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
    	int l = 0;
    	int h = num.size()-1;
    	int m;

    	while(l<h){
            while(l<h){
                if(num[l+1]==num[l]){
                    l++;
                }else if(num[h]==num[l] || num[h-1]==num[h]){
                    h--;
                }else{
                    break;
                }
            }
            if(l==h){
                return num[l];
            }

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
		vector<int> num = {4, 4, 5, 5, 6, 6, 7, 0, 1, 4};
		cout << s.findMin(num) << endl;
	}

	{	
		vector<int> num = {4, 5, 6, 0, 0, 1, 2, 4};
		cout << s.findMin(num) << endl;
	}

	{	
		vector<int> num = {4, 4, 5, 0, 1, 2, 2, 3, 4};
		cout << s.findMin(num) << endl;
	}


	{	
		vector<int> num = {3,1,1};
		cout << s.findMin(num) << endl;
	}
	
	return 0;
} 