/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
   int val;
   struct TreeLinkNode *left, *right, *next;
};
 
void connectHelper(struct TreeLinkNode *root){
    if (root->left==0 || root->right==0) {
        return;
    }
    root->left->next = root->right;
    if (root->next ==0){
        root->right->next = 0;
    }else{
        root->right->next = root->next->left;
    }
    connectHelper(root->left);
    connectHelper(root->right);
}
void connect(struct TreeLinkNode *root) {
    if (root==0){
        return;
    }
    root->next = 0; 
    connectHelper(root);
}

void main(){
    
}