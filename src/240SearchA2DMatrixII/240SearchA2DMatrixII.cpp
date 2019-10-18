class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); if(m==0) return false;
        int n = matrix[0].size(); if(n==0) return false;
        int row = m-1;
        int col = 0;
        while(col<n&&row>=0){
            if(matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) --row;
            else ++col;
        }
            
        return false;
    }
};

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0)
      return false;
    int m = matrix[0].size();
    if (m == 0)
      return false;
    int i = 0;
    int j = n - 1;
    while (j >= 0 && i < m) {
      if (matrix[j][i] == target)
        return true;
      else if (matrix[j][i] < target) {
        i++;
      } else if (matrix[j][i] > target) {
        j--;
      }
    }
    return false;
  }
};

int main() { return 0; }
