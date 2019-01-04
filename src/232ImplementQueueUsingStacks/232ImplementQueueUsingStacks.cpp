#include <iostream>
using namespace std;

class MyQueue {
private:
  stack<int> s[2];

public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    if (s[0].empty()) {
      s[0].push(x);
    } else {
      while (!s[0].empty()) {
        s[1].push(s[0].top());
        s[0].pop();
      }
      s[0].push(x);
      while (!s[1].empty()) {
        s[0].push(s[1].top());
        s[1].pop();
      }
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int v = s[0].top();
    s[0].pop();
    return v;
  }

  /** Get the front element. */
  int peek() { return s[0].top(); }

  /** Returns whether the queue is empty. */
  bool empty() { return s[0].empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {}