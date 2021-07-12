#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct Node
{
    Node *children[27];
    bool end;
};
Node *getNode()
{
    Node *node = new Node();
    for(char c = 'a';c<='z';c++)
    {
        node->children[c-'a']=NULL;
    }
    node->end = false;
    return node;
}
// bool search(string s, Node *root)
// {
//     for(ll i=0;i<s.length();i++)
//     {
//         if(!root->children[s[i]-'a'])
//             return false;
//         root = root->children[s[i]-'a'];
//         if(i==s.length()-1 && root->end==true)
//             return true;
//     }
//     return false;
// }
void insert(Node *root,string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(root->children[s[i]-'a']!=NULL)
        {
            root=root->children[s[i]-'a'];
        }
        else
        {
            root->children[s[i]-'a']=getNode();
            root=root->children[s[i]-'a'];
        }
        if(i==s.length()-1)
            root->end=true;
    }
}
void search(Node *node,string prefix,int i,string s)
{
    cout<<prefix<<" ";
    if(node->end)
        return;
    for(char c='a';c<='z';c++)
    {
        if(node->children[c-'a'])
        {
            search(node->children[c-'a'],prefix+c,i+1,s);
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    string arr[n];
    Node *root= getNode();
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        insert(root,arr[i]);
    }
    string s;
    cin>>s;
    string prefix="";
    Node *prevNode=NULL;
    Node *currNode =root;
    for(int i=0;i<s.length();i++)
    {
        char c = s[i];
        prefix+=c;
        if(i==0)
            prevNode=root;
        currNode = prevNode->children[c-'a'];
        if(currNode==NULL)
            break;
        cout<<prefix<<" -> ";
        search(currNode,prefix,i,s);
        cout<<endl;
        prevNode=currNode;
    }
    return 0;
}