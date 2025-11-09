
#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n<=1) return n;
    return fibo(n-1) +fibo(n-2);
}

void fiboRec(int n)
{
    int a1=0;
    int a2=1;
    cout<<a1<<" "<<a2<<" ";
    for(int i=2;i<n;i++)
    {
        int a3=a1+a2;
        a1=a2;
        a2=a3;
        cout<<a2<<" ";
    }
}

int main()
{
    for(int i=0;i<10;i++)
    {
        cout<<fibo(i)<<endl;
    }

    cout<<endl;
    fiboRec(10);
    return 0;
}