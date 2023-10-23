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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> q_node;
        queue<int> q_val;
        q_node.push(root);
        q_val.push(root->val);;
        while(!q_node.empty()){
            TreeNode* cur=q_node.front();
            int tmp=q_val.front();
            q_node.pop(),q_val.pop();
            if(!cur->left&&!cur->right){
                if(tmp==targetSum){
                    return true;
                }
                continue;
            }
            if(cur->left){
                q_node.push(cur->left);
                q_val.push(cur->left->val+tmp);
            }
            if(cur->right){
                q_node.push(cur->right);
                q_val.push(cur->right->val+tmp);
            }
        }
        return false;
    }
};
