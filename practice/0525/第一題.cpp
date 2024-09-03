#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
string result[1000];
int result1=0;
void setset(string *arr1,int *arr2,string temp,int counts)
{
    for(int i=0;i<counts;i++)
    {
        if(arr1[i]==temp)
        {
            arr2[i]=1;
        }
    }
}
void ini(int *arr2,int counts)
{
    for(int i=0;i<counts;i++)
    {
        arr2[i]=0;
    }
}
void ini(string *arr2,int counts)
{
    for(int i=0;i<counts;i++)
    {
        arr2[i]="";
    }
}
int checkon(int *arr2,int counts)
{
    for(int i=0;i<counts;i++)
    {
        if(arr2[i]==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    while(1)
    {
        vector<string> manlist[1000];
        cout<<"The dead people: ";
        string input;
        int counts=0;
        while(cin>>input)
        {
            manlist[0].push_back(input);
            counts++;
            if(cin.get()=='\n')
            {
                break;
            }

        }
        string *arr1 = new string[counts];
        int *arr2 = new int[counts];
        cout<<"The suspect: ";
        int temp=1;
        while(1)
        {
            cin>>input;
            if(input=="0")
            {
                break;
            }
            manlist[temp].push_back(input);
            if(cin.get()=='\n')
            {
                temp++;
                continue;
            }
        }
        vector<string>:: iterator iter = manlist[0].begin();
        for(int ix = 0; iter != manlist[0].end(); ++iter, ++ix)
        {
            arr1[ix] = *iter;
            arr2[ix] = 0;
        }
        for(int i=1;i<temp;i++)
        {
            vector<string>:: iterator iter = manlist[i].begin()+1;
            for(int ix = 0; iter != manlist[i].end(); ++iter, ++ix)
            {
                setset(arr1,arr2,*iter,counts);
            }
            if(checkon(arr2,counts)==1)
            {
                result[result1]=*manlist[i].begin();
                cout<<result[result1]<<endl;
                result1++;
            }
            ini(arr2,counts);
        }
        cout<<"------------------------------"<<endl;
        cout<<"Output: ";
        for(int i=0;i<=result1;i++)
        {
            cout<<result[i]<<" ";
        }
        ini(result,result1);

        result1=0;
        cout<<endl;
        system("pause");
        system("cls");
    }
}
