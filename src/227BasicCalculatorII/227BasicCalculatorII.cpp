#include <iostream>
#include <stack>
#include <stdlib.h> /* atoi */
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    unordered_map<char, int> m;
    m['+'] = 0;
    m['-'] = 0;
    m['*'] = 1;
    m['/'] = 1;
    stack<int> val;
    stack<char> ops;
    int n = s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
      switch (s[j]) {
      case '+':
      case '-':
      case '*':
      case '/':
        val.push(atoi(s.substr(i, j - i).c_str()));
        i = j + 1;
        break;
      default:
        if (j == n - 1) {
          val.push(atoi(s.substr(i, j - i + 1).c_str()));
        }
      }
      if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' ||
          j == n - 1) {
        while (!ops.empty()) {
          char op = ops.top();
          if (m[op] >= m[s[j]]) {
            ops.pop();
            int b = val.top();
            val.pop();
            int a = val.top();
            val.pop();
            int c = (op == '*' ? a * b
                               : op == '/' ? a / b : op == '+' ? a + b : a - b);
            val.push(c);
            // cout << a << " " << b << " " << c << endl;
          } else {
            break;
          }
        }
        if (j != n - 1) {
          ops.push(s[j]);
        }
      }
      j++;
    }
    return val.top();
  }
};

int main() {
  Solution s;
  cout << s.calculate("33+22*2/10-20/10*3") << endl;
  cout << s.calculate("1-1+1") << endl;
  return 0;
}