/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(root, sum, result, results);
        return results;
    }
    
    void dfs(TreeNode* root, int sum, vector<int>& result, vector<vector<int>>& results){
        if(root==nullptr) return;
        result.push_back(root->val);
        sum -= root->val;
        if(root->left==nullptr&&root->right==nullptr&&sum==0){
            results.push_back(result);
        }else{
            if(root->left!=nullptr){
                dfs(root->left, sum, result, results);
            }
            if(root->right!=nullptr){
                dfs(root->right, sum, result, results);
            }
        }
        result.pop_back();
    }
};

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
      vector<vector<int>> paths;
      if(root==nullptr) return paths;

      edgeTo[root] = nullptr;
      hasPathSum(root, sum, paths);
      return paths;
    }

    void hasPathSum(TreeNode *root, int sum, vector<vector<int>> &paths) {
        if(root==nullptr) return;

        sum-=root->val;
        if(sum==0&&root->left==nullptr&&root->right==nullptr){
          vector<int> v;
          do{
            v.insert(v.begin(), root->val);
            root=edgeTo[root];
          }while(root!=nullptr);
          paths.push_back(v);
        }else{
          if(root->left!=nullptr)  edgeTo[root->left]  = root;
          if(root->right!=nullptr) edgeTo[root->right] = root;
          hasPathSum(root->left, sum, paths);
          hasPathSum(root->right, sum, paths);
        }
    }
private:
  unordered_map<TreeNode*, TreeNode*> edgeTo;
};

int main(){
	return 0;
}
