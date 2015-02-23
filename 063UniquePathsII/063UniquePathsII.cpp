#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
https://oj.leetcode.com/problems/unique-paths-ii/

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> E;
        vector<int> e(n, 0);
        for(int i=0; i<m; ++i){
            E.push_back(e);
        }    

        E[0][0] = obstacleGrid[0][0]==0?1:0;
        for(int i=1; i<m; ++i){
            if(obstacleGrid[i-1][0]==0&&obstacleGrid[i][0]==0){
                E[i][0]+=E[i-1][0];
            }
        }
        for(int j=1; j<n; ++j){
            if(obstacleGrid[0][j-1]==0&&obstacleGrid[0][j]==0){
                E[0][j]+=E[0][j-1];
            }   
        }

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j]==0){
                    if(obstacleGrid[i-1][j]==0){
                        E[i][j]+=E[i-1][j];
                    }
                    if(obstacleGrid[i][j-1]==0){
                        E[i][j]+=E[i][j-1];
                    }
                }
            }
        }

        return E[m-1][n-1];
    }
};

int main(){
    Solution s;
    vector<vector<int> > obstacleGrid{
        {0, 1},
    };

    cout<<s.uniquePathsWithObstacles(obstacleGrid)<<endl;

	return 0;
}