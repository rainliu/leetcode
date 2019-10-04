class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size(); if (n==0) return vector<int>{};
        vector<int> result(n, 0);        
        stack<int> s;
        for (int i=n-1; i>=0; --i) {
            while(!s.empty() && T[i] >= T[s.top()]) s.pop();
            if (!s.empty()) result[i] = s.top()-i;
            else result[i] = 0;
            s.push(i);
        }
        return result;
    }
};
