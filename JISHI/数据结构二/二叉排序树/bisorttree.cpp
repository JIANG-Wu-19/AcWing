#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(int x):data(x),leftchild(NULL),rightchild(NULL){}
};

TreeNode* Insert(TreeNode *root,int x)
{
    if(root==NULL){
        root=new TreeNode(x);
    }
    else if(x<root->data){
        root->leftchild=Insert(root->leftchild,x);
    }
    else{
        root->rightchild=Insert(root->rightchild,x);
    }
    return root;
}

void PreOrder(TreeNode *root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->leftchild);
    PreOrder(root->rightchild);
}

void InOrder(TreeNode *root)
{
    if(root==NULL){
        return;
    }
    InOrder(root->leftchild);
    cout<<root->data<<" ";
    InOrder(root->rightchild);
}

void PostOrder(TreeNode *root)
{
    if(root==NULL){
        return;
    }
    PostOrder(root->leftchild);
    PostOrder(root->rightchild);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    while(cin>>n){
        TreeNode *root=NULL;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            root=Insert(root,x);
        }
        PreOrder(root);
        cout<<endl;
        InOrder(root);
        cout<<endl;
        PostOrder(root);
        cout<<endl;
    }
}
