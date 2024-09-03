#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int main()
{
    ifstream testfile;
    ofstream finalfile;
    finalfile.open("Answer.txt");
    string line;
    testfile.open("text.txt");
    vector<string> v;
    vector<int> co;
    vector<int> head;
    while(!testfile.eof())
    {
        testfile>>line;
        if(!testfile.fail())
        {
            int flag=0;
            for(int i=0;i<v.size();i++)
            {
                if(line==v[i])
                {
                    co[i]++;
                    flag=1;
                }
            }
            if(flag==0&&line!="."&&line!=",")
            {
                v.push_back(line);
                co.push_back(1);
                head.push_back(int(line[0]));
            }
        }
    }
    for(int i=1;i<v.size();i++)
    {
        for(int j=i;j>0;j--)
        {
            if(head[j]<head[j-1])
            {
                swap(head[j],head[j-1]);
                swap(co[j],co[j-1]);
                swap(v[j],v[j-1]);
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"有 "<<co[i]<<" 個"<<endl;
        finalfile<<v[i]<<"有 "<<co[i]<<" 個"<<endl;
    }
    testfile.close();
    finalfile.close();
}
