#include <iostream>
using namespace std;

class RandomizedSet {
private:
  unordered_map<int, int> m;
  vector<int> nums;

public:
  /** Initialize your data structure here. */
  RandomizedSet() {
    // srand(time(NULL));
  }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (m.find(val) == m.end()) {
      nums.push_back(val);
      m[val] = int(nums.size()) - 1;
      return true;
    } else {
      return false;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (m.find(val) != m.end()) {
      int idx = m[val];
      swap(m[nums[int(nums.size()) - 1]], m[val]);
      swap(nums[int(nums.size()) - 1], nums[idx]);
      nums.pop_back();
      m.erase(val);
      return true;
    } else {
      return false;
    }
  }

  /** Get a random element from the set. */
  int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

class RandomizedSet2 {
    vector<int> values;
    unordered_map<int, int> value2index;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(0);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (value2index.find(val) == value2index.end()){
            values.push_back(val);
            value2index.insert({val, values.size()-1});
            return true;
        }else{
            return false;
        }     
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (value2index.find(val) != value2index.end()){
            int index = value2index[val];
            if (index != values.size()-1){
                swap(values[values.size()-1], values[index]);
                value2index[values[index]] = index;
            }
            values.pop_back();
            value2index.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = values.size();
        if (n>0){
            return values[rand()%n];
        }else{
            return -1;
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() { return 0; }
