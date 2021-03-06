/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    vector<NestedInteger>::iterator it;
    vector<NestedInteger>::iterator it_end;
    unique_ptr<NestedIterator> itt;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it = nestedList.begin();
        it_end = nestedList.end();
        forward();
    }
    
    void forward(){
        while(it!=it_end){
            if(!it->isInteger()){
                itt = unique_ptr<NestedIterator>{new NestedIterator(it->getList())};
                if(!itt->hasNext()){
                    ++it;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }

    int next() {
        int val = 0;
        if(!hasNext()) return val;
        if(it->isInteger()){
            val = it->getInteger();
            ++it;
            forward();
        }else{
            val = itt->next();
            if(!itt->hasNext()){
                ++it;
                forward();
            }
        }
        return val;
    }

    bool hasNext() {
        return it!=it_end;    
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than
  // a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a
  // nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
  stack<NestedInteger> s;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (int i = int(nestedList.size()) - 1; i >= 0; i--) {
      s.push(nestedList[i]);
    }
  }

  int next() {
    auto p = s.top();
    s.pop();
    return p.getInteger();
  }

  bool hasNext() {
    while (!s.empty()) {
      auto p = s.top();
      if (p.isInteger()) {
        return true;
      }
      s.pop();
      for (int i = int(p.getList().size()) - 1; i >= 0; i--) {
        s.push(p.getList()[i]);
      }
    }
    return false;
  }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() { return 0; }
