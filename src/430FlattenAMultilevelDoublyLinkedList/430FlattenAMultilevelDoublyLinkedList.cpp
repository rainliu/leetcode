/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        auto [root, tail] = flattenHelper(head);
        return root;
    }
    pair<Node*, Node*> flattenHelper(Node* root){
        if(root==nullptr) return {nullptr, nullptr};
        if(root->child==nullptr&&root->next==nullptr){
            return {root, root};
        }
        auto [child_head, child_tail] = flattenHelper(root->child);
        auto [next_head, next_tail] = flattenHelper(root->next);
        root->child = nullptr;
        if(child_head!=nullptr){
            root->next = child_head;
            child_head->prev = root;
            child_tail->next = next_head;
            if(next_tail==nullptr){
                next_tail = child_tail;
            }else{
                next_head->prev = child_tail;
            }
        }else{
            root->next = next_head;    
            if(next_tail==nullptr){
                next_tail = root;
            }else{
                next_head->prev = root;
            }
        }
        return {root, next_tail};
    }
};
