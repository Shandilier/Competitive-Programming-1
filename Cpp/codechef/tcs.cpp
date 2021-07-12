#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int count=0;
    string s;
    int val=0;
    while(1)
    {
        cin>>s;
        val++;
        if(s=="Q" || s=="q")
            break;
        if(s.length()!=10)
            continue;
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if((c-'0')>9)   
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;
        count++;
    }
    if(val==6)
    {
        cout<<count<<endl;
    }
    else
    {
        cout<<"INPUT LIMIT IS 5"<<endl;
    }
    return 0;
}