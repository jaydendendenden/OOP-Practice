#include<iostream>
#include<vector>
#include"implementation2.cpp"
using namespace std;
int temp;
int main()
{
    while(1)
    {
        system("cls");
        cout<<"�w��Ө���ĩ��B��1�}�l�B��0�h�X: ";
        while(1)
        {
            cin>>temp;
            if(temp<=1&&temp>=0)
            {
                break;
            }
            else
            {
                cout<<"�A�n��J1��0: ";
            }
        }
        if(temp==0)
        {
            break;
        }
        system("cls");
        cout<<"��ܩ��Ļ��: "<<endl;
        cout<<"1. �ۤ�"<<endl<<"2. ����"<<endl<<"3. �P�p"<<endl;
        while(1)
        {
            cin>>temp;
            if(temp>=1&&temp<=3)
            {
                break;
            }
            else
            {
                cout<<"�A�n��J1~3: ";
            }
        }
        cout<<endl;
        crust a(temp);
        cout<<"���Pizza�j�p: "<<endl;
        cout<<"1. �p"<<endl<<"2. ��"<<endl<<"3. �j"<<endl;
        while(1)
        {
            cin>>temp;
            if(temp>=1&&temp<=3)
            {
                break;
            }
            else
            {
                cout<<"�A�n��J1~3: ";
            }
        }
        cout<<endl;
        pizzasize b(temp);
        pizza mypizza(a,b);
        while(1)
        {
            cout<<"���Pizza�t��: "<<endl;
            cout<<"1. ���"<<endl<<"2. �ɦ�"<<endl<<"3. �_�q"<<endl<<"4. �ɦױ�"<<endl<<"5. �f�X"<<endl<<"6. �C��"<<endl<<"7. þ��"<<endl<<"8. ���L"<<endl<<"9. ����"<<endl<<"0. ���b"<<endl;
            while(1)
            {
                cin>>temp;
                if(temp>=0&&temp<=9)
                {
                    break;
                }
                else
                {
                    cout<<"�A�n��J0~9: ";
                }
            }
            cout<<endl;
            if(temp==0)
            {
                break;
            }
            ingredients c(temp);
            mypizza.setadd(c);
        }
        mypizza.printresult();
        system("pause");
    }
}
