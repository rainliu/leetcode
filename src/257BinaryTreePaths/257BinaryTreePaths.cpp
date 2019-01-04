#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void binaryTreePathsHelper(TreeNode *root, vector<int> &result,
                             vector<string> &results) {
    if (root->left == nullptr && root->right == nullptr) {
      ostringstream oss;
      oss << result[0];
      for (int i = 1; i < result.size(); i++) {
        oss << "->" << result[i];
      }
      results.push_back(oss.str());
      return;
    }
    if (root->left != nullptr) {
      result.push_back(root->left->val);
      binaryTreePathsHelper(root->left, result, results);
      result.pop_back();
    }
    if (root->right != nullptr) {
      result.push_back(root->right->val);
      binaryTreePathsHelper(root->right, result, results);
      result.pop_back();
    }
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> results;
    if (root != nullptr) {
      vector<int> result = {root->val};
      binaryTreePathsHelper(root, result, results);
    }
    return results;
  }
};

int main() { retrurn 0; }