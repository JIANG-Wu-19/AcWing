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
    int res,cnt;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->right);
        if(!cnt) return;
        if(!(--cnt)) res=root->val;
        dfs(root->left);
    }
    
    int findTargetNode(TreeNode* root, int cnt) {
        this->cnt=cnt;
        dfs(root);
        return res;
    }
};
