#include <iostream>
#include <queue>
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
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<pair<TreeNode *, int>> q;
    if (root != nullptr) {
      q.push(make_pair(root, 0));
    }
    int last = -1;
    while (!q.empty()) {
      auto pp = q.front();
      q.pop();
      if (pp.second != last) {
        result.push_back(pp.first->val);
        last = pp.second;
      }
      if (pp.first->right != nullptr) {
        q.push(make_pair(pp.first->right, pp.second + 1));
      }
      if (pp.first->left != nullptr) {
        q.push(make_pair(pp.first->left, pp.second + 1));
      }
    }
    return result;
  }
};

int main() {}