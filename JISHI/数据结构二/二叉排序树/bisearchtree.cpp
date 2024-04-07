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

bool judge(TreeNode *root1,TreeNode *root2)
{
    if(root1==NULL&&root2==NULL){
        return true;
    }
    else if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL)){
        return false;
    }
    else if(root1->data!=root2->data){
        return false;
    }
    return judge(root1->leftchild,root2->leftchild)&&judge(root1->rightchild,root2->rightchild);
}

int main()
{
    int n;
    while(cin>>n){
        string str;
        TreeNode *root=NULL;
        cin>>str;
        for(int i=0;i<str.size();i++){
            root=Insert(root,str[i]-'0');
        }
        for(int i=0;i<n;i++){
            TreeNode *root1=NULL;
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                root1=Insert(root1,s[j]-'0');
            }
            if(judge(root,root1)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}
