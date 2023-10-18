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
 unordered_map<int, int> index;

TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
	if (pre_l > pre_r) {
		return nullptr;
	}

	int pre_root = pre_l;
	int in_root = index[preorder[pre_root]];

	TreeNode* root = new TreeNode();
	root->val = preorder[pre_root];
	int LeftSubTree = in_root - in_l;
	root->left = Build(preorder, inorder, pre_l + 1, pre_l + LeftSubTree, in_l, in_root - 1);
	root->right = Build(preorder, inorder, pre_l + LeftSubTree + 1, pre_r, in_root + 1, in_r);

	return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int n = preorder.size();
	for (int i = 0; i < n; i++) {
		index[inorder[i]] = i;
	}
	return Build(preorder, inorder, 0, n - 1, 0, n - 1);
}

};
