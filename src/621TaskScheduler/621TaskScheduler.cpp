class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(const auto& task : tasks){
            ++m[task];
        }
        auto cmp = [](const auto& a, const auto& b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> q(cmp);
        for(const auto& p : m){
            q.push(p);
        }
        int result = 0;
        while(!q.empty()){
            queue<pair<char, int>> t;
            int local = min(int(q.size()), n+1);                        
            for(int i=0; i<local; ++i){
                auto p = q.top(); q.pop();
                if(--p.second > 0){
                    t.push(p);
                }
            }
            while(!t.empty()){
                q.push(t.front());
                t.pop();
            }
            
            if(q.empty()){
                result += local;
            }else{
                result += n+1;
            }
        }        
        return result;
    }
};

#include <iostream>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> m;
    for (auto c : tasks) {
      ++m[c];
    }
    priority_queue<int> q;
    for (auto &p : m) {
      q.push(p.second);
    }
    int cycle = n + 1, intervals = 0;
    while (!q.empty()) {
      vector<int> tmp;
      int times = 0;
      for (int i = 0; i < cycle; ++i) {
        tmp.push_back(q.top());
        q.pop();
        times++;
        if (q.empty())
          break;
      }
      for (auto cnt : tmp) {
        if (--cnt) {
          q.push(cnt);
        }
      }
      intervals += !q.empty() ? cycle : times;
    }

    return intervals;
  }
};

int main() { return 0; }
