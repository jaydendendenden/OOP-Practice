#include<iostream>
#include"implementation.cpp"
using namespace std;
int main()
{
    matrix* a=new matrix;
    matrix* b=new matrix;
    int temp1;
    cout<<"please enter 2~4"<<endl;
    cin>>temp1;
    a->n=temp1;
    b->n=temp1;
    a->input(a,b);
    while(1)
    {
        cout<<"1.Addition"<<endl<<"2.Subtraction"<<endl<<"3.Multiplication"<<endl<<"4.Division"<<endl<<"5.Exit"<<endl;
        int temp3;
        cin>>temp3;
        if(temp3==1)
        {
            a->add(a,b);
        }
        else if(temp3==2)
        {
            a->sub(a,b);
        }
        else if(temp3==3)
        {
            a->multiple(a,b);
        }
        else if(temp3==4)
        {
            a->divide(a,b);
        }
        else if(temp3==5)
        {
            break;
        }
        else
        {
            cout<<"please enter 1~5"<<endl;
        }
    }
}
