/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include<queue>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            TreeNode* left=tmp->left;
            tmp->left=tmp->right;
            tmp->right=left;

            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }

            q.pop();
        }
        return root;
    }
};
