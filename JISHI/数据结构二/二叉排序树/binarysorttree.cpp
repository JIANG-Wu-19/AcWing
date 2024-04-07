#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode(int x): data(x),leftchild(NULL),rightchild(NULL){}
};

TreeNode* Insert(TreeNode* root,int x,int father)
{
    if(root==NULL){
        root=new TreeNode(x);
        cout<<father<<endl;
    }
    else if(x<root->data){
        root->leftchild=Insert(root->leftchild,x,root->data);
    }
    else{
        root->rightchild=Insert(root->rightchild,x,root->data);
    }
    return root;
}

int main()
{
    int n;
    while(cin>>n){
        TreeNode *root=NULL;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            root=Insert(root,x,-1);
        }
    }
    return 0;
}
