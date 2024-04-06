#include<bits/stdc++.h>

using namespace std;

string str;
int i=0;

struct TreeNode
{
    char data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(char c): data(c),leftchild(NULL),rightchild(NULL){};
};

void InOrder(TreeNode *root)
{
    if(root==NULL){
        return;
    }
    InOrder(root->leftchild);
    cout<<root->data<<" ";
    InOrder(root->rightchild);
}

TreeNode* build()
{
    char c=str[i++];
    if(c=='#')
        return NULL;
    TreeNode *root=new TreeNode(c);
    root->leftchild=build();
    root->rightchild=build();
    return root;
}

int main()
{
    while(cin>>str){
        i=0;
        TreeNode *root=build();
        InOrder(root);
        cout<<endl;
    }
}
