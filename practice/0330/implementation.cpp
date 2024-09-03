#include<iostream>
#include"0330.h"
using namespace std;
int matrix::n=0;
void matrix::input(matrix* a, matrix* b)
{
    int times = (a->n)*(a->n);
    for(int i=0;i<times;i++)
    {
        int temp;
        cin>>temp;
        a->arr1[i]=temp;
    }
    for(int i=0;i<times;i++)
    {
        int temp;
        cin>>temp;
        b->arr1[i]=temp;
    }
}
void matrix::add(matrix* a,matrix* b)
{
    int times=n,tt=0;
    while(times)
    {
        for(int i=tt;i<n+tt;i++)
        {
            cout<<a->arr1[i]+b->arr1[i]<<" ";
        }
        cout<<endl;
        times--;
        tt=tt+n;
    }
    cout<<endl;
}
void matrix::sub(matrix* a,matrix* b)
{
    int times=n,tt=0;
    while(times)
    {
        for(int i=tt;i<n+tt;i++)
        {
            cout<<a->arr1[i]-b->arr1[i]<<" ";
        }
        cout<<endl;
        times--;
        tt=tt+n;
    }
    cout<<endl;
}
void matrix::multiple(matrix* a,matrix* b)
{
    int aa[n][n]={0};
    int bb[n][n]={0};
    int cc[n][n]={0};
    int times=0;
    for(int j=0;j<n;j++)
    {
        for(int i=0+times;i<n+times;i++)
        {
            aa[j][i%n]=a->arr1[i];
            bb[j][i%n]=b->arr1[i];
        }
        times=times+n;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                cc[i][j]=cc[i][j]+aa[i][k]*bb[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<cc[i][j]<<" ";
        }
        cout<<endl;
    }

}
void matrix::divide(matrix* a,matrix* b)
{
    int times=n,flag=1,tt=0;
    for(int i = 0;i<times*times;i++)
    {
        if(b->arr1[i]%a->arr1[i]!=0)
        {
            flag=0;
        }
    }
    if(flag)
    {
        while(times)
        {
            for(int i=tt;i<n+tt;i++)
            {
                cout<<b->arr1[i]/a->arr1[i]<<" ";
            }
            cout<<endl;
            times--;
            tt=tt+n;
        }
        cout<<endl;
    }
    else
    {
        while(times)
        {
            for(int i=tt;i<n+tt;i++)
            {
                cout<<"0"<<" ";
            }
            cout<<endl;
            times--;
            tt=tt+n;
        }
        cout<<endl;
    }
}

