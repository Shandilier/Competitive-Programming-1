#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct Trie
{
    Trie *children[26];
    bool end;
};

Trie *newNode()
{
    Trie *node =new Trie();
    for(ll i=0;i<=25;i++)
    {
        node->children[i]=NULL;
    }
    node->end=false;
    return node;
}

void *insert(Trie *root,string s)
{
    struct Trie *p=root;
    for(int i=0;i<s.length();i++)
    {
        if(!p->children[s[i]-'a'])
        {
            p->children[s[i]-'a']=newNode();
        }
        p=p->children[s[i]-'a'];
        if(i==s.length()-1)
            p->end=true;
    }
}

void findAllPrefix(Trie *currNode,string prefix)
{
    // cout<<prefix<<endl;
    if(currNode->end)
        cout<<prefix<<" ";
    for(char c='a';c<='z';c++)
    {
        if(currNode->children[c-'a'])
            findAllPrefix(currNode->children[c-'a'],prefix+c);
    }
}

int main()
{
    ll n;
    cin>>n;
    string s;
    Trie *root=newNode();
    for(ll i=0;i<n;i++)
    {
        cin>>s;
        insert(root,s);
    }
    ll k;
    string prefix="";
    cin>>s;
    Trie *prevNode=root;
    for(ll i=0;i<s.length();i++)
    {
        prefix+=(char)s[i];
        Trie *currNode = prevNode->children[s[i]-'a'];
        if(!currNode)
            break;
        cout<<s[i]<<" -> ";
        findAllPrefix(currNode,prefix);
        cout<<endl;
        prevNode = currNode;
    }   
}