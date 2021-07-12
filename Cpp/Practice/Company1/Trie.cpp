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
bool search(string s, Node *root)
{
    for(ll i=0;i<s.length();i++)
    {
        if(!root->children[s[i]-'a'])
            return false;
        root = root->children[s[i]-'a'];
        if(i==s.length()-1 && root->end==true)
            return true;
    }
    return false;
}
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
    for(ll i=0;i<5;i++)
    {
        cin>>s;
        if(search(s,root))
            cout<<"Found"<<endl;
        else
            cout<<"Not found"<<endl;
    }
    return 0;
}