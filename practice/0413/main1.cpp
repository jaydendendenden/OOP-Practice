#include<iostream>
#include"implementataion1.cpp"
using namespace std;
int main()
{
    Stack teststack;
    while(1)
    {
        cout<<"1.push"<<endl<<"2.pop"<<endl<<"3.empty"<<endl<<"4.top"<<endl;
        int temp;
        cin>>temp;
        if(temp<1||temp>4)
        {
            cout<<"error"<<endl;
        }
        else
        {
            if(temp==1)
            {
                teststack.Push();
                teststack.output();
                cout<<endl;
            }
            else if(temp==2)
            {
                teststack.Pop();
                teststack.output();
                cout<<endl;
            }
            else if(temp==3)
            {
                teststack.Empty();
                cout<<endl;
            }
            else
            {
                teststack.Top();
                teststack.output();
                cout<<endl;
            }
        }
    }
}
