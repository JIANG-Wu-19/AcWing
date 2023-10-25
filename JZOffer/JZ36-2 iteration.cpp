/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        stack<Node*> s;
        Node* head,* pre;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root->left;
            }
            if(!s.empty()){
                root=s.top();
                s.pop();
                if(!pre){
                    head=root;
                }else{
                    pre->right=root;
                }
                root->left=pre;
                pre=root;
                root=root->right;
            }
        }
        head->left=pre;
        pre->right=head;
        return head;
    }
};
