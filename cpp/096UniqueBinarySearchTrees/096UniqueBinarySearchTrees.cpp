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
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

T(0) = 0;
T(1) = 1;
T(2) = 2;
T(n) = sum_k{0}^{n-1}[T(n-1-k)+T(k)]=2*sum_k{0}^{n-1}T(k);
*/

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> T(n+1, 0);
        T[0] = 1;
        T[1] = 1;
        for(int i=2; i<=n; ++i){
            T[i] = 0;
            for(int k=0; k<i; ++k){
                T[i]+=T[i-1-k]*T[k];
            }            
        }
        return T[n];
    }
};

int main(){
    Solution s;

    cout<<s.numTrees(2)<<endl;
    cout<<s.numTrees(3)<<endl;
    cout<<s.numTrees(4)<<endl;

    return 0;
}