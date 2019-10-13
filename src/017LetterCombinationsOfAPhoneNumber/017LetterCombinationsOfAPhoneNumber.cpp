class Solution {
    vector<vector<string>> m{
        {}, 
        {}, 
        {"a","b","c"},
        {"d","e","f"},
        {"g","h","i"},
        {"j","k","l"},
        {"m","n","o"},
        {"p","q","r","s"},
        {"t","u","v"},
        {"w","x","y","z"},
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()){
            vector<string> a;
            backtracking(a, 0, digits, result);
        }
        return result;
    }
    
    void backtracking(vector<string>& a, int k, string& digits, vector<string>& result){
        if(is_solution(a, k, digits)){
            process_solution(a, k, digits, result);
        }else{
            auto cands = construct_candidates(a, k, digits);
            ++k;
            for(const auto& cand : cands){
                a.push_back(cand);
                backtracking(a, k, digits, result);
                a.pop_back();
            }
        }
    }
    
    bool is_solution(vector<string>& a, int k, string& digits){
        return k==digits.size();
    }
    
    void process_solution(vector<string>& a, int k, string& digits, vector<string>& result){
        ostringstream oss;
        for(const auto& c: a){
            oss<<c;
        }
        result.push_back(oss.str());
    }
    
    vector<string> construct_candidates(vector<string>& a, int k, string& digits) {
        return m[digits[k]-'0'];
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
https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

vector<string> d2c{
     		"", //0
     		"", //1
     		"abc", //2
     		"def", //3
     		"ghi", //4
     		"jkl", //5
     		"mno", //6
     		"pqrs",//7
     		"tuv", //8
     		"wxyz",//9
     	};
vector<int> totals{0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string> combinations;
    	if(digits.size()==0) return combinations;

    	vector<char> ds(digits.size());
    	for(int i=0; i<digits.size(); i++){
     		ds[i]=digits[i]-'0';	
     	}

     	DFS(combinations, "", ds, 0, digits.size());

     	return combinations;
    }

    void DFS(vector<string> &combinations, string s, vector<char> &ds, int level, int depth){
    	for(int i=0; i<totals[ds[level]]; ++i){
    		if(level+1<depth){
    			DFS(combinations, s+d2c[ds[level]][i], ds, level+1, depth);
    		}else{
    			combinations.push_back(s+d2c[ds[level]][i]);
    		}
    	}
    }
};

int main(){
	Solution s;

	auto output = s.letterCombinations("23");
	for(const auto &p : output){
		cout<<"\""<<p<<"\" ";
	}
	cout<<endl;
}
