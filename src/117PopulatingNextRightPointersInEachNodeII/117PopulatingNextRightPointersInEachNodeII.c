/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
   int val;
   struct TreeLinkNode *left, *right, *next;
};
 
void connectHelper(struct TreeLinkNode *root){
    if (root->left==0 && root->right==0) {
        return;
    }
    if (root->left!=0){
        if (root->right!=0){
            root->left->next = root->right;
        }else{
            struct TreeLinkNode * p=root->next;
            while (p!=0 && p->left==0 && p->right==0){
                p = p->next;
            }
            if (p==0) {
                root->left->next = 0;
            }else{
                root->left->next = p->left!=0 ? p->left : p->right;
            }
        }
    }
    if (root->right!=0){
        struct TreeLinkNode * p=root->next;
        while (p!=0 && p->left==0 && p->right==0){
            p = p->next;
        }
        if (p==0) {
            root->right->next = 0;
        }else{
            root->right->next = p->left!=0 ? p->left : p->right;
        }
    }
    if (root->right!=0){ 
        connectHelper(root->right);
    }
     if (root->left!=0){
        connectHelper(root->left);
    }
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