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
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<TreeNode *> generateTrees(int n) {  
        return generateTree(1, n);
    }

    vector<TreeNode *> generateTree(int lo, int hi){
        vector<TreeNode *> v;
        if(lo<=hi){
            for(int i=lo; i<=hi; ++i){
                vector<TreeNode *> left  = generateTree(lo, i-1);
                vector<TreeNode *> right = generateTree(i+1, hi);

                for(int n=0; n<left.size(); n++){
                    for(int m=0; m<right.size(); m++){
                        TreeNode *root = new TreeNode(i);        
                        root->left = left[n];
                        root->right =right[m];
                        v.push_back(root);
                    }
                }
            }
        }else{
            v.push_back(nullptr);
        }
        return v;
    }

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