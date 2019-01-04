#include <algorithm>
#include <iostream>
#include <queue>
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
public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    vector<vector<int>> results;
    if (root == nullptr) {
      return results;
    }
    vector<vector<int>> negative, positive;
    vector<int> zero;
    queue<pair<TreeNode *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int no = p.second;
      if (no < 0) {
        if (negative.size() < abs(no)) {
          negative.push_back(vector<int>{p.first->val});
        } else {
          negative[abs(no) - 1].push_back(p.first->val);
        }
      } else if (no == 0) {
        zero.push_back(p.first->val);
      } else {
        if (positive.size() < no) {
          positive.push_back(vector<int>{p.first->val});
        } else {
          positive[no - 1].push_back(p.first->val);
        }
      }
      if (p.first->left != nullptr) {
        q.push(make_pair(p.first->left, no - 1));
      }
      if (p.first->right != nullptr) {
        q.push(make_pair(p.first->right, no + 1));
      }
    }

    for (int i = int(negative.size()) - 1; i >= 0; i--) {
      results.push_back(negative[i]);
    }
    results.push_back(zero);
    for (int i = 0; i < positive.size(); i++) {
      results.push_back(positive[i]);
    }
    return results;
  }
};

int main() { return 0; }