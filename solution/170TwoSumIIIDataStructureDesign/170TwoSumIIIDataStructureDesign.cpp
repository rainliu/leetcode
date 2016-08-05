#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:
    void add(int number) {
        if(ordered_nums.find(number)!=ordered_nums.end()){
            ordered_nums[number]++;
        }else{
            ordered_nums[number] = 1;            
        }
    }

    bool find(int value) {
        for(auto p = ordered_nums.begin(); p!=ordered_nums.end(); ++p){
            if(ordered_nums.find(value-p->first)!=ordered_nums.end()){
                if(value-p->first == p->first){
                    if(ordered_nums[value-p->first]>1)
                        return true;
                }else{
                    return true;
                }
            }
        }   
        return false;
    }
private:
    unordered_map<int, int> ordered_nums;
};

class TwoSum3 {
public:
    void add(int number) {
        int size = nums.size();
        if(size>0){
            for(int i=0; i<size; i++){
                int sum = nums[i]+number;
                sums[sum] = sum; 
            }
        }
        nums.push_back(number);
    }

    bool find(int value) {
        return sums.find(value)!=sums.end();   
    }

private:
    vector<int> nums;
    unordered_map<int, int> sums;
};

class TwoSum2 {
public:
    void add(int number) {
        nums.push_back(number);
    }

    bool find(int value) {
        return twoSum(nums, value);   
    }

    bool twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> diff_map;
        
        for(int i=0; i<numbers.size(); i++){
            diff_map[target-numbers[i]] = i; 
        }

        for(int i=0; i<numbers.size(); i++){
            if(diff_map.find(numbers[i])!=diff_map.end()){
                return true;
            }
        }
    
        return false;
    }
private:
    vector<int> nums;
};

int main(){
	TwoSum s;

    s.add(1); s.add(3); s.add(5);
    cout<<s.find(4)<<endl;
    cout<<s.find(7)<<endl;
	return 0;
} 