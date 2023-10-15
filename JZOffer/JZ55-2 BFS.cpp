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
    int n=0;
    int calculateDepth(TreeNode* root) {
        if(!root) return 0;
        vector<TreeNode*> q;
        q.push_back(root);
        int res=0;
        while(!q.empty()){
            vector<TreeNode*> tmp;
            for(TreeNode* node:q){
                if(node->left) tmp.push_back(node->left);
                if(node->right) tmp.push_back(node->right);
            }
            q=tmp;
            res++;
        }
        return res;
    }
};
