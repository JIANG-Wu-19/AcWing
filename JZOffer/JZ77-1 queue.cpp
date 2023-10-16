/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
        // write code here
        vector<vector<int>> res;
        if(!pRoot) return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        int depth=0;
        while(!q.empty()){
            vector<int> tmp;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* t=q.front();
                q.pop();
                if(!t) continue;
                q.push(t->left);
                q.push(t->right);
                if(!(depth%2)){
                    tmp.push_back(t->val);
                }else{
                    tmp.insert(tmp.begin(), t->val);
                }
            }
            depth++;
            if(!tmp.empty()){
                res.push_back(tmp);
            }
        }
        return res;
    }
};