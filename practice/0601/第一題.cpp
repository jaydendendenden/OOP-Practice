#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    ofstream newFile;
    newFile.open("output.txt");
    while(1)
    {
        cout<<"Input string , input 0 can leave: ";
        string test;
        cin>>test;
        if(test=="0")
        {
            newFile.close();
            break;
        }
        else
        {
            char *arr = new char[test.length()];
            for(int i=0;i<test.length();i++)
            {
                arr[i]=test[test.length()-i-1];
            }
            for(int i=0;i<test.length();i++)
            {
                cout<<arr[i];
                newFile<<arr[i];
            }
            cout<<endl;
            newFile<<endl;
        }
    }
}
