// For Process 1
#include<bits/stdc++.h>
using namespace std;
void process1()
{
    flag[0]=true;
    turn =1;

    // for process 1
    //entry section
    while(flag[1]==true && turn==1);
    //critical section
    
    // exit section
    flag[0]=false;
}
void process2()
{
    flag[1]=true;
    turn =0;

    // for process 2
    //entry section
    while(flag[0]==true && turn ==0);
    // critical section

    // exit section
    flag[1]=false;
}
int main()
{
    bool flag[2];
    memset(flag,false,sizeof(flag));
    ll turn ;

    return 0;
}
