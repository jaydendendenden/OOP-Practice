#include<iostream>
#include"0504implementation.cpp"
using namespace std;
int main()
{
    cout<<"�п�J�|�ӼƦr���O�N��a,b,c,d"<<endl;
    int a,b,c,d;
    int inorout;
    while(1)
    {
        cin>>a>>b>>c>>d;
        if(b==0||d==0)
        {
            cout<<"�������o��0! �A��J�@��!"<<endl;
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
    cout<<"���ƥ[�k: ";
    add.printfraction();
    cout<<endl;
    cout<<"���ƴ�k: ";
    sub.printfraction();
    cout<<endl;
    cout<<"���ƭ��k: ";
    mul.printfraction();
    cout<<endl;
    cout<<"���ư��k: ";
    div.printfraction();
    cout<<endl;
    while(1)
    {
        cout<<"��J1�H�~��, 0�h���}"<<endl;
        while(1)
        {
            cin>>inorout;
            if(inorout>=0&&inorout<=1)
            {
                break;
            }
            else
            {
                cout<<"�п�J1��0"<<endl;
            }
        }
        if(inorout==0)
        {
            break;
        }
        cout<<"�A��J�@���n�B�⪺�Ʀr�a!"<<endl;
        while(1)
        {
            cin>>a>>b>>c>>d;
            if(b==0||d==0)
            {
                cout<<"�������o��0! �A��J�@��!"<<endl;
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
        cout<<"���ƥ[�k: ";
        add.printfraction();
        cout<<endl;
        cout<<"���ƴ�k: ";
        sub.printfraction();
        cout<<endl;
        cout<<"���ƭ��k: ";
        mul.printfraction();
        cout<<endl;
        cout<<"���ư��k: ";
        div.printfraction();
        cout<<endl;
    }
}
