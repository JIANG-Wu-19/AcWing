#include<bits/stdc++.h>

using namespace std;

string pre,in;

struct TreeNode
{
    char data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(char c): data(c),leftchild(NULL),rightchild(NULL){};
};

TreeNode* build(string pre,string in)
{
    if(pre.size()==0){
        return NULL;
    }
    char c=pre[0];
    TreeNode *root=new TreeNode(c);
    int pos=in.find(c);
    root->leftchild=build(pre.substr(1,pos),in.substr(0,pos));
    root->rightchild=build(pre.substr(pos+1),in.substr(pos+1));
    return root;
}

void PostOrder(TreeNode* root)
{
    if(root==NULL){
        return;
    }
    PostOrder(root->leftchild);
    PostOrder(root->rightchild);
    cout<<root->data;
}

int main()
{
    while(cin>>pre>>in){
        TreeNode *root=build(pre,in);
        PostOrder(root);
        cout<<endl;
    }
}
