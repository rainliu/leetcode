class Solution {
public:
    int calculate(string s) {
        auto tokens = tokenize(s);
        
        vector<string> st;

        int i = 0;
        while(i<tokens.size()) {
            if(tokens[i]=="*"||tokens[i]=="/"){
                auto a = st.back(); st.pop_back();
                auto b = tokens[i++];
                auto c = tokens[i++];
                int d;
                if(b=="*"){
                    d = stoi(a)*stoi(c);
                }else{
                    d = stoi(a)/stoi(c);
                }
                st.push_back(to_string(d));
            }else{
                st.push_back(tokens[i++]);
            }
        }
        
        if(st.empty()) return 0;        
        reverse(st.begin(), st.end());
        while(st.size()>1) {
            auto a = st.back(); st.pop_back();
            auto b = st.back(); st.pop_back();
            auto c = st.back(); st.pop_back();
            int d;
            if(b=="+"){
                d = stoi(a)+stoi(c);
            }else{
                d = stoi(a)-stoi(c);
            }
            st.push_back(to_string(d));
        }
        
        auto a = st.back(); st.pop_back();
        
        return stoi(a);
    }
    
    vector<string> tokenize(string& s){
        vector<string> tokens;
        int i=0;
        int j=0;        
        while(j<s.size()){
            if(s[j]>='0'&&s[j]<='9'){
                ++j;
            }else{
                if(j>i) tokens.push_back(s.substr(i, j-i));
                if(s[j]!=' ') tokens.push_back(s.substr(j, 1));
                ++j;
                i=j;
            }
        }
        if(j>i) tokens.push_back(s.substr(i, j-i));
        
        return tokens;
    }
};

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
