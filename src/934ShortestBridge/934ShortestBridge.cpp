class Solution {
    static constexpr int offset_x[4]={-1,1,0,0};
    static constexpr int offset_y[4]={0,0,-1,1};
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(); if(m==0) return 0;
        int n = A[0].size(); if(n==0) return 0;
        vector<vector<int>> CC(m, vector<int>(n, 0));
        int cc=1;
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                if(CC[j][i]==0 && A[j][i]==1){
                    dfs(A, CC, i, j, n, m, cc);
                    ++cc;
                }
            }
        }
        //cout<<cc<<endl;
        queue<pair<int,int>> q;
        for(int j=0; j<m; ++j){
            for(int i=0; i<n; ++i){
                //cout<<CC[j][i]<<" ";
                if(CC[j][i]==1){
                    for(int d=0; d<4; ++d){
                        int x = i+offset_x[d];
                        int y = j+offset_y[d];
                        if(x>=0&&x<n&&y>=0&&y<m&&CC[y][x]==0){
                            q.push({y*n+x, 1});
                            CC[y][x] = 3;
                        }
                    }
                }
            }
            cout<<endl;
        }
        //cout<<q.size()<<endl;
        while(!q.empty()){
            auto p = q.front();
            int i = p.first%n;
            int j = p.first/n;
            int l = p.second;
            q.pop();
            for(int d=0; d<4; ++d){
                int x = i+offset_x[d];
                int y = j+offset_y[d];
                if(x>=0&&x<n&&y>=0&&y<m){
                    if(CC[y][x]==0){
                        q.push({y*n+x, l+1});
                        CC[y][x] = 3;
                    }else if(CC[y][x]==2){
                        return l;
                    }
                }
            }
        }
        return 0;
    }
    
    void dfs(vector<vector<int>>& A, vector<vector<int>>& CC, int i, int j, int n, int m, int cc) {
        //cout<<i<<","<<j<<":"<<cc<<endl;
        CC[j][i] = cc;
        for(int d=0; d<4; ++d){
            int x = i+offset_x[d];
            int y = j+offset_y[d];
            if(x>=0&&x<n&&y>=0&&y<m&&CC[y][x]==0&&A[y][x]==1){
                dfs(A, CC, x, y, n, m, cc);
            }
        }
    }
};
