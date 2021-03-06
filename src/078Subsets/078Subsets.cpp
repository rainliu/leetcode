class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        
        for(int i=0; i<(1<<nums.size()); ++i){
            vector<int> result;
            for(int j=0; j<nums.size();++j){
                if((i>>j)&0x1) {
                    result.push_back(nums[j]);
                }
            }
            results.push_back(result);
        }
        
        return results;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<bool> a;
        backtracking(a, 0, nums, results);        
        return results;
    }
    
    void backtracking(vector<bool>& a, int k, vector<int>& nums, vector<vector<int>>& results){
        if(is_solution(a, k, nums)){
            process_solution(a, k, nums, results);
        }else{
            auto cands = contruct_candidates(a, k, nums);
            ++k;
            for(const auto& cand: cands){
                a.push_back(cand);
                backtracking(a, k, nums, results);
                a.pop_back();
            }
        }
    }
    
    bool is_solution(vector<bool>& a, int k, vector<int>& nums) {
        return k==nums.size();
    }
    
    void process_solution(vector<bool>& a, int k, vector<int>& nums, vector<vector<int>>& results){
        vector<int> result;
        for(int i=0; i<a.size(); ++i){
            if(a[i]){
                result.push_back(nums[i]);
            }
        }
        results.push_back(result);
    }
    
    vector<bool> contruct_candidates(vector<bool>& a, int k, vector<int>& nums){
        return vector<bool>{true, false};
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
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());

        int N = 1<<S.size();
        vector<vector<int> > result(N);

    	for(int i=0; i<N; i++){
    		int j=i;
    		int k=0;
    		while(j){
    			if(j&0x01){
	    			result[i].push_back(S[k]);
	    		}
    			j>>=1;
    			k++;
    		}
    	}

    	return result;
    }
};

int main(){
	Solution s;

	vector<int> S ={2,3,1};
	auto result = s.subsets(S);
	for(auto &p : result){
		for(auto &q : p){
			cout<<q<<" ";
		}
		cout<<endl;
	}
	return 0;
}
