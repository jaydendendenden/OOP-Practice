#include<iostream>
#include"0504implementation.cpp"
using namespace std;
int main()
{
    cout<<"請輸入四個數字分別代表a,b,c,d"<<endl;
    int a,b,c,d;
    int inorout;
    while(1)
    {
        cin>>a>>b>>c>>d;
        if(b==0||d==0)
        {
            cout<<"分母不得為0! 再輸入一次!"<<endl;
        }
        else
        {
            break;
        }
    }
    fraction one(a,b);
    fraction two(c,d);
    fraction add=one+two;
    fraction sub=one-two;
    fraction mul=one*two;
    fraction div=one/two;
    cout<<"分數加法: ";
    add.printfraction();
    cout<<endl;
    cout<<"分數減法: ";
    sub.printfraction();
    cout<<endl;
    cout<<"分數乘法: ";
    mul.printfraction();
    cout<<endl;
    cout<<"分數除法: ";
    div.printfraction();
    cout<<endl;
    while(1)
    {
        cout<<"輸入1以繼續, 0則離開"<<endl;
        while(1)
        {
            cin>>inorout;
            if(inorout>=0&&inorout<=1)
            {
                break;
            }
            else
            {
                cout<<"請輸入1或0"<<endl;
            }
        }
        if(inorout==0)
        {
            break;
        }
        cout<<"再輸入一次要運算的數字吧!"<<endl;
        while(1)
        {
            cin>>a>>b>>c>>d;
            if(b==0||d==0)
            {
                cout<<"分母不得為0! 再輸入一次!"<<endl;
            }
            else
            {
                break;
            }
        }
        one.setfraction(a,b);
        two.setfraction(c,d);
        add=one+two;
        sub=one-two;
        mul=one*two;
        div=one/two;
        cout<<"分數加法: ";
        add.printfraction();
        cout<<endl;
        cout<<"分數減法: ";
        sub.printfraction();
        cout<<endl;
        cout<<"分數乘法: ";
        mul.printfraction();
        cout<<endl;
        cout<<"分數除法: ";
        div.printfraction();
        cout<<endl;
    }
}
