class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int count = 0;
        while(root!=nullptr || !s.empty()){
            if(root!=nullptr){
                s.push(root);
                root = root->left;
            }else{
                root = s.top(); s.pop();
                ++count;
                if(count==k) return root->val;
                root = root->right;
            }
        }
        return 0;
    }
};

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
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr || k<=0) return 0;
        int left = count(root->left);
        if(k == left+1) return root->val;
        else if(k>left+1){
            return kthSmallest(root->right, k-left-1);
        }else{
            return kthSmallest(root->left, k);
        }
    }
    
    int count(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+count(root->left)+count(root->right);
    }
};

#include <iostream>
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
  int kthSmallestHelper(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int leftCount = kthSmallestHelper(root->left);
    int rightCount = kthSmallestHelper(root->right);
    int count = leftCount + rightCount + 1;
    return count;
  }

public:
  int kthSmallest(TreeNode *root, int k) {
    while (root != nullptr) {
      int leftCount = kthSmallestHelper(root->left);
      if (k <= leftCount) {
        root = root->left;
      } else if (k == leftCount + 1) {
        return root->val;
      } else {
        root = root->right;
        k -= leftCount + 1;
      }
    }
    return 0;
  }
};

int main() { return 0; }
