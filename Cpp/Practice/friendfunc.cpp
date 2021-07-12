#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class B;
class A {
    private:
    int a=10;
    friend void calc(A,B);
    public:
    void setData(int a)
    {
        this->a = a;
    }
};
class B {
    private:
    int b=30;
    friend void calc(A,B);
    public:
    void setData(int b)
    {
        this.b = b;
    }
};
void calc(A obj1,B obj2)
{
    cout<<obj1.a<<" "<<obj2.b<<endl;
}
int main()
{
    A obj1;
    B obj2;
    obj1.setData(10);
    obj2.setData(20);
    calc(obj1,obj2);
    return 0;
}
