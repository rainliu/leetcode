class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = int(nums.size())-1;
        int mi = binarySearch(nums, target, lo, hi);
        if(mi==-1) return vector<int>{-1,-1};
        int right = mi;
        int left = mi;
        while((mi=binarySearch(nums, target, mi+1, hi))>=0){
            right = mi;
        }
        mi = left;
        while((mi=binarySearch(nums, target, lo, mi-1))>=0){
            left = mi;
        }
        return vector<int>{left, right};
    }
    
    int binarySearch(vector<int>& nums, int target, int lo, int hi){
        if(lo>hi) return -1;
        while(lo<=hi){
            int mi = lo + (hi-lo)/2;
            if(nums[mi]==target) return mi;
            else if(nums[mi]>target) hi = mi-1;
            else lo = mi+1;
        }
        return -1;
    }
};

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> nomatch{-1,-1};
    	if(n==0) return nomatch;

    	int lo = 0;
    	int hi = n-1;
    	int mi;
    	bool find=false;
    	while(lo<=hi){
    		mi = lo+(hi-lo)/2;
    		if(A[mi]<target) lo=mi+1;
    		else if(A[mi]>target) hi=mi-1;
    		else {find=true;break;}
    	}
    	if(find){
    		int m, mb, me;

    		m = mi;
    		do{
    			mb = m;
    			m  = searchrange(A, -1, mb, target);
    		}while(m!=-1);
    		
    		m = mi;
    		do{
    			me = m;
    			m  = searchrange(A, me, n, target);
    		}while(m!=-1);
    		vector<int> match{mb,me};
    		return match;
    	}else{
    		return nomatch;
    	}
    }

    int searchrange(int A[], int s, int n, int target) {
    	int mi, lo=s+1, hi=n-1;
    	bool find=false;
    	while(lo<=hi){
    		mi = lo+(hi-lo)/2;
    		if(A[mi]<target) lo=mi+1;
    		else if(A[mi]>target) hi=mi-1;
    		else {find=true;break;}
    	}
    	if(find){
    		return mi;
    	}else{
    		return -1;
    	}
    }
};

int main(){
	Solution s;
	
	{
		int A[] = {5, 7, 7, 8, 8, 10};
		auto output = s.searchRange(A, 6, 8);
		for(const auto&p : output){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	{
		int A[] = {8, 8, 8, 8, 8, 8};
		auto output = s.searchRange(A, 6, 8);
		for(const auto&p : output){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	return 0;
}
