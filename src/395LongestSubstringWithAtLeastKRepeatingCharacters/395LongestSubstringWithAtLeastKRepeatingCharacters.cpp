class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, int(s.size())-1);
    }
    int longestSubstring(string& s, int k, int lo, int hi) {
        if(lo>hi) return 0;
        unordered_map<char, pair<int,int>> m;
        int i;
        for(i=lo; i<=hi; ++i) {
            auto it = m.find(s[i]);
            if(it==m.end()){
                m[s[i]] = {1, i};    
            }else{
                ++(it->second.first);
            }
        }
        i = hi+1;
        for(const auto& [ch, p] : m){
            if(p.first<k){
                i = p.second;
                break;
            }
        }
        if(i>hi) return hi-lo+1;
        int l = longestSubstring(s, k, lo, i-1);
        int r = longestSubstring(s, k, i+1, hi);
        return max(l, r);
    }
};

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    unordered_map<char, pair<int, int>> m;
    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = make_pair(i, 1);
      } else {
        auto p = m[s[i]];
        p.second++;
        m[s[i]] = p;
      }
    }
    int j = s.size();
    for (auto &p : m) {
      if (p.second.second < k) {
        j = p.second.first;
        break;
      }
    }
    // cout<<j<<" ";
    if (j == s.size())
      return j;
    int left = j < k ? 0 : longestSubstring(s.substr(0, j), k);
    int right =
        (int(s.size()) - j - 1) < k
            ? 0
            : longestSubstring(s.substr(j + 1, int(s.size()) - j - 1), k);
    return max(left, right);
  }
};

int main() { return 0; }
