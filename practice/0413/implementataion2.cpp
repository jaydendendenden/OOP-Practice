#include<iostream>
#include<stdlib.h>
#include<ctime>
#include"header0413.h"
using namespace std;
int Stack::randomcard()
{
    int temp;
    srand(time(NULL));
    temp=rand()%52;
    return temp;
}
int Stack::checkarr(int* arr,int ptr,int number)
{
    while(ptr>-1)
    {
        if(arr[ptr]==number)
        {
            return 0;
        }
        else
        {
            ptr--;
        }
    }
    return 1;
}
void Stack::wash()
{
    int test1=cardcounts;
    for(int i=0;i<52;i++)
    {
        Stackarray[i]=0;
    }
    Stackptr=-1;
    while(test1)
    {
        int temp = randomcard();
        if(checkarr(Stackarray,Stackptr,temp))
        {
            Push(temp);
            test1--;
        }
    }
}
Stack::Stack()
{
    for(int i=0;i<52;i++)
    {
        Stackarray[i]=0;
    }
    Stackptr=-1;
    int test1;
    cout<<"how many number do you want to input?"<<endl;
    cin>>test1;
    cardcounts=test1;
    while(test1)
    {
        int temp = randomcard();
        if(checkarr(Stackarray,Stackptr,temp))
        {
            Push(temp);
            test1--;
        }
    }
}
void Stack::Pop()
{
    if(Stackptr<0)
    {
        cout<<"error"<<endl;
    }
    else
    {
        if(Stackarray[Stackptr]<13)
            {
                cout<<"C"<<Stackarray[Stackptr]+1<<endl;
                Stackptr--;
            }
            else if(Stackarray[Stackptr]<26)
            {
                cout<<"D"<<Stackarray[Stackptr]%13+1<<endl;
                Stackptr--;
            }
            else if(Stackarray[Stackptr]<39)
            {
                cout<<"H"<<Stackarray[Stackptr]%13+1<<endl;
                Stackptr--;
            }
            else
            {
                cout<<"B"<<Stackarray[Stackptr]%13+1<<endl;
                Stackptr--;
            }
    }
}
void Stack::Push(int a)
{
    if(Stackptr>52)
    {
        cout<<"error"<<endl;
    }

    else
    {
        Stackptr++;
        Stackarray[Stackptr]=a;
    }
}
void Stack::Empty()
{
    Stackptr==-1;
    cout<<"empty the stack"<<endl;
}
void Stack::Top()
{
    if(Stackptr==-1)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"top number: "<<Stackarray[Stackptr]<<endl;
    }
}
void Stack::output()
{
    if(Stackptr==-1)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        int temp=Stackptr;
        while(temp>=0)
        {
            if(Stackarray[temp]<13)
            {
                cout<<"C"<<Stackarray[temp]+1<<endl;
                temp--;
            }
            else if(Stackarray[temp]<26)
            {
                cout<<"D"<<Stackarray[temp]%13+1<<endl;
                temp--;
            }
            else if(Stackarray[temp]<39)
            {
                cout<<"H"<<Stackarray[temp]%13+1<<endl;
                temp--;
            }
            else
            {
                cout<<"B"<<Stackarray[temp]%13+1<<endl;
                temp--;
            }
        }
    }
}
