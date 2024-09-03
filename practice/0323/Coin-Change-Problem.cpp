#include<iostream>
using namespace std;
int onedollar(int d)
{
    return 1;
}
int fivedollar(int c)
{
    int total=0,cc=c/5;
    for(int i=0;i<=cc;i++)
    {
        total=total+onedollar(c-5*i);
    }
    return total;
}
int tendollar(int b)
{
    int total=0,bb=b/10;
    for(int i=0;i<=bb;i++)
    {
        total=total+fivedollar(b-10*i);
    }
    return total;
}
int fiftydollar(int a)
{
    int total=0,aa=a/50;
    for(int i=0;i<=aa;i++)
    {
        total=total+tendollar(a-50*i);
    }
    return total;
}
int main()
{
    while(1)
    {
        int temp;
        cout<<"請輸入多少錢 0<輸入值<=500"<<endl;
        cin>>temp;
        if(temp==0)
        {
            break;
        }
        int test;
        test=fiftydollar(temp);
        cout<<test<<endl;
    }
    int temp;
}
