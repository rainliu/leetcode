#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
  queue<int> q[2];
  int cur;

public:
  /** Initialize your data structure here. */
  MyStack() { cur = 0; }

  /** Push element x onto stack. */
  void push(int x) {
    q[1 - cur].push(x);
    while (!q[cur].empty()) {
      q[1 - cur].push(q[cur].front());
      q[cur].pop();
    }
    cur = 1 - cur;
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int v = q[cur].front();
    q[cur].pop();
    return v;
  }

  /** Get the top element. */
  int top() { return q[cur].front(); }

  /** Returns whether the stack is empty. */
  bool empty() { return q[cur].empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */