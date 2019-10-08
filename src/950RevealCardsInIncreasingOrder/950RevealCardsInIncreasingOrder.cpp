class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        for(int i=0; i<n; ++i){
            q.push(i);
        }
        sort(deck.begin(), deck.end());
        vector<int> result(n,0);
        for(auto card: deck) {
            int i = q.front(); q.pop();
            result[i] = card;
            if(!q.empty()){
                int i = q.front(); q.pop();
                q.push(i);
            }
        }
        return result;
    }
};
