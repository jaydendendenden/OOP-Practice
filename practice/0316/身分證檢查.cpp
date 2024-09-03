#include<iostream>
#include<cstring>
using namespace std;
bool checkid(string id)
{
    bool test=true;
    if(id.length()!=10)
    {
        test=false;
        return test;
    }
    else if(int(char(id[0]))<65||int(char(id[0]))>90)
    {
        test=false;
        return test;
    }
    else if(int(char(id[1]))!=49&&int(char(id[1]))!=50)
    {
        test=false;
        return test;
    }
    else
    {
        for(int i=2;i<=9;i++)
        {
            if(int(char(id[i]))<48||int(char(id[i]))>57)
            {
                test=false;
                return test;
            }
        }
    }
    return test;
}
int main()
{
    string temp;
    cout<<"please enter your id"<<endl;
    cin>>temp;
    cout<<endl;
    if(checkid(temp))
    {
        cout<<"correct";
    }
    else
    {
        cout<<"incorrect";
    }
}
