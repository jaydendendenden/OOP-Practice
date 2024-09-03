#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    while(1)
    {
        string input;
        int length;
        int stackbig=0,rightbig=0,stackmid=0,rightmid=0,rightsmall=0,stacksmall=0;
        cout<<"please enter string"<<endl;
        cin>>input;
        if(input=="0")
        {
            break;
        }
        cout<<endl;
        length=input.length();
        char* temp=(char*)input.c_str();
        for(int i=0;i<length;i++)
        {
            if(*(temp+i)=='(')
            {
                stacksmall++;
            }
            else if(*(temp+i)=='[')
            {
                stackmid++;
            }
            else if(*(temp+i)=='{')
            {
                stackbig++;
            }
            else if(*(temp+i)==')')
            {
                if(stacksmall<=0)
                {
                    rightsmall++;
                }
                else
                {
                    stacksmall--;
                }
            }
            else if(*(temp+i)==']')
            {
                if(stackmid<=0)
                {
                    rightmid++;
                }
                else
                {
                    stackmid--;
                }
            }
            else if(*(temp+i)=='}')
            {
                if(stackbig<=0)
                {
                    rightbig++;
                }
                else
                {
                    stackbig--;
                }
            }
            else
            {

            }
        }
        cout<<"small:"<<rightsmall+stacksmall<<"  "<<"mid:"<<rightmid+stackmid<<"  "<<"big:"<<rightbig+stackbig<<endl;
    }
}
