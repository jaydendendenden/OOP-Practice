#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    while(1)
    {
        string a,b;
        int alen,blen;
        char *s1,*s2;
        cout<<"請輸入兩個字串(都輸入0即離開)"<<endl;
        cin>>a>>b;
        alen=a.length();
        blen=b.length();
        if(a=="0"&&b=="0")
        {
            break;
        }
        s1=(char*)a.c_str();
        s2=(char*)b.c_str();
        for(blen;blen>0;blen--)
        {
            if((*s1)==(*s2))
            {
                s1=s1+1;
                s2=s2+1;
                alen--;
            }
            else
            {
                s2=s2+1;
            }
        }
        if(alen==0)
        {
            cout<<"TRUE"<<endl;
        }
        else
        {
            cout<<"FALSE"<<endl;
        }
    }

}
