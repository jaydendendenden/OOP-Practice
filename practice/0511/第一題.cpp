#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
int compare(string a , string b , int c)
{
    int test=1;
    for(int i=0;i<c;i++)
    {
        if(a[i]!=b[i])
        {
            test=0;
        }
    }
    return test;
}
int main() {

    string input;
    string line1;
    ifstream myFile;
    myFile.open("Basic.txt");
    cout<<"please enter name: (enter 0 leave)"<<endl;
    cin>>input;
    int temp=input.length();
    while(!myFile.eof())
    {
        getline(myFile,line1);
        if(compare(line1,input,temp)==1)
        {
            cout<<line1;
            ofstream newFile;
            newFile.open("data.txt");
            newFile <<line1;
            newFile.close();
        }
    }
    myFile.close();
    return 0;

}
