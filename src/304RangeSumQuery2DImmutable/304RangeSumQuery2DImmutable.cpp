class NumMatrix {
    vector<vector<int>> sum2d;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); if(m==0) return;
        int n = matrix[0].size(); if(n==0) return;
        sum2d.resize(m, vector<int>(n, 0));
        int sum = 0;
        for(int i=0; i<n; ++i){
            sum += matrix[0][i];
            sum2d[0][i] = sum;
        }
        for(int j=1; j<m; ++j){
            int sum = 0;
            for(int i=0; i<n; ++i){
                sum += matrix[j][i];
                sum2d[j][i] = sum+sum2d[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sum2d[row2][col2];
        if(row1-1>=0){
            sum -=sum2d[row1-1][col2];
        }
        if(col1-1>=0){
            sum -=sum2d[row2][col1-1];
        }
        if(row1-1>=0&&col1-1>=0){
            sum +=sum2d[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
