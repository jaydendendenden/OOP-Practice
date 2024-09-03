#include<iostream>
#include"header0413.h"
using namespace std;
Stack::Stack()
{
    for(int i=0;i<10;i++)
    {
        Stackarray[i]=0;
    }
    Stackptr=-1;
    int test1;
    cout<<"how many number do you want to input?"<<endl;
    cin>>test1;
    cout<<"input the number"<<endl;
    while(test1)
    {
        int test;
        cin>>test;
        Stackptr++;
        Stackarray[Stackptr]=test;
        test1--;
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
        cout<<"the pop number is: "<<Stackarray[Stackptr]<<endl;
        Stackptr--;
    }
}
void Stack::Push()
{
    if(Stackptr>=10)
    {
        cout<<"error"<<endl;
    }

    else
    {
        cout<<"please enter number"<<endl;
        int number;
        cin>>number;
        Stackptr++;
        Stackarray[Stackptr]=number;
        cout<<"push the number: "<<number<<endl;
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
            cout<<Stackarray[temp]<<endl;
            temp--;
        }
    }
}
