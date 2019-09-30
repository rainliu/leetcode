/*
check order matters!!!!
first check if out of bottom border (y >= m) then y = m - 1; x += 2; change walk direction.
         OR if out of right border (x >= n) then x = n - 1; y += 2; change walk direction.
then check if out of top border (y < 0) then y = 0; change walk direction.
         OR if out of left border (x < 0) then x = 0; change walk direction.
Otherwise, just go along with the current direction.
*/
class Solution {
    static constexpr int offset_x[2] = {1,-1}; 
    static constexpr int offset_y[2] = {-1,1};
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(); if(m==0) {return result;}
        int n = matrix[0].size(); if(n==0) {return result;}
        int x = 0;
        int y = 0;
        int k = m*n;
        int d = 0;
        while (k-->0) {
            result.push_back(matrix[y][x]);
            x += offset_x[d];
            y += offset_y[d];
            if(x>=n) {x=n-1; y+=2; d=1-d;}
            else if(y>=m) {y=m-1; x+=2; d=1-d;}
            else if (y<0) {y=0; d=1-d;}
            else if(x<0) {x=0; d=1-d;}
        }
        
        return result;
    }
};
