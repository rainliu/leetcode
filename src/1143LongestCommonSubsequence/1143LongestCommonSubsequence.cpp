class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // D[i,j] = max(text1[i]==text2[j]+D[i-1,j-1], D[i-1,j], D[i, j-1])
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> D(n, vector<int>(m, 0));
        D[0][0] = (text1[0]==text2[0]);
        for(int i=1; i<n; ++i){
            D[i][0] = max((text1[i]==text2[0]? 1:0), D[i-1][0]);
        }
        for(int j=1; j<m; ++j){
            D[0][j] = max((text1[0]==text2[j]? 1:0), D[0][j-1]);
        }
        for(int i=1; i<n; ++i){
            for(int j=1; j<m; ++j){
                D[i][j] = max(max( (text1[i]==text2[j])+D[i-1][j-1], D[i-1][j]), D[i][j-1]);
            }
        }
        return D[n-1][m-1];
    }
};
