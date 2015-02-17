#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
    	vector<string> result;

    	if(n<=0){
    		if(lower==upper){
    			result.push_back(to_string(lower));
    		}else{
    			result.push_back(to_string(lower)+"->"+to_string(upper));
    		}
    	}else{
	    	if(A[0]-lower>1){
	    		result.push_back(to_string(lower)+"->"+to_string(A[0]-1));
	    	}else if(A[0]-lower==1){
	    		result.push_back(to_string(lower));
	    	}
	    	for(int i=0; i<n-1; i++){
	    		if(A[i+1]-A[i]>2){
	    			result.push_back(to_string(A[i]+1)+"->"+to_string(A[i+1]-1));
	    		}else if(A[i+1]-A[i]==2){
	    			result.push_back(to_string(A[i]+1));
	    		}
	    	}
	    	if(upper-A[n-1]>1){
	    		result.push_back(to_string(A[n-1]+1)+"->"+to_string(upper));
	    	}else if(upper-A[n-1]==1){
	    		result.push_back(to_string(upper));
	    	}
	    }

    	return result;
    }
};


int main(){
	Solution s;

	{
		int A[] = {0, 1, 3, 50, 75};
		auto result = s.findMissingRanges(A, 5, 0, 99);
		for(const auto& p : result){
			cout<<p<<endl;
		}
	}

	{
		int A[] = {1, 3, 50, 97};
		auto result = s.findMissingRanges(A, 4, 0, 99);
		for(const auto& p : result){
			cout<<p<<endl;
		}
	}

	{
		int A[] = {1};
		auto result = s.findMissingRanges(A, 1, 0, 99);
		for(const auto& p : result){
			cout<<p<<endl;
		}
	}
	return 0;
} 