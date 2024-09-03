#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    while(1)
    {
        cout<<"please input string"<<endl;
        string input,temp;
        int test;
        getline(cin,input);
        if(input=="0")
        {
            break;
        }
        else
        {
            test=input.rfind(" ");
            input.replace(0, test+1, "");
            cout<<"output: "<<input.length()<<endl;
        }
    }
}
