#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *left,*right;
};
Node *newNode(int data)
{
    Node *node = new Node();
    node->left=NULL;
    node->right=NULL;
    node->data=data;
    return node;
}
Node *insert(Node *root,int data)
{
    if(root==NULL)
        return newNode(data);
    if(root->data>data)
        root->left=insert(root->left,data);
    else if(root->data<data)
        root->right=insert(root->right,data);
}
void minPath(Node *root,int &minm,int count)
{
    if(!root)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        minm=min(minm,count);
        return;
    }
    minPath(root->left,minm,count+1);
    minPath(root->right,minm,count+1);
}
void calc(Node *root ,int minm,vector<int>v)
{
    if(!root)
        return;
    if(root->left==NULL && root->right==NULL && minm==0)
    {
        v.push_back(root->data);
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
        return;
    }
    v.push_back(root->data);
    calc(root->left,minm-1,v);
    calc(root->right,minm-1,v);
}
int main()
{
    int n;
    cin>>n;
    int x;
    Node *root=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    int minm=INT_MAX;
    minPath(root,minm,0);
    // cout<<minm<<endl;
    vector<int>v;
    calc(root,minm,v);
}