#include<iostream>
#include"implementataion2.cpp"
using namespace std;
int main()
{
    cout<<"�ڪ��{�����J�P�ƶq�h���ɭԤ���C�A�]������O�_�����ƥd����������h���ɶ��A�{���O�i�H�]���A�ЧU�е��@�U"<<endl;
    Stack teststack;
    teststack.output();
    while(1)
    {
        cout<<"1.rewash"<<endl<<"2.get one card"<<endl;
        int aa;
        cin>>aa;
        if(aa==1)
        {
            teststack.wash();
            teststack.output();
        }
        else if(aa==2)
        {
            teststack.Pop();
        }
        else
        {
            cout<<"error";
        }
    }
}
