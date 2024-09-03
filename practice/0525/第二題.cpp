#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<math.h>
using namespace std;
string input;
vector<int> arr;
void bubblesort(int *arr,int counts)
{

}
int operate(string goal)
{
    vector<int> v;
    for(int i=0;i<goal.length();i++)
    {
        if(int(goal[i])>=48&&int(goal[i])<=57)
        {
            v.push_back(int(goal[i])-48);
        }
    }
    if(v.size()==0)
    {
        return -1;
    }
    else
    {
        int test=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            test+=v[i]*pow(10,v.size()-i-1);
        }
        return test;
    }
}
int main()
{
    ifstream temp;
    int ss,counts=0;
    temp.open("text.txt");
    while(!temp.eof())
    {
        temp>>input;
        if(!temp.fail())
        {
            ss=operate(input);
            if(ss!=-1)
            {
                arr.push_back(ss);
            }
        }
    }
    for(int i=arr.size()-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    ofstream newfile;
    newfile.open("output.txt");
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
        newfile<<arr[i]<<" ";
    }
    temp.close();
    newfile.close();
}
