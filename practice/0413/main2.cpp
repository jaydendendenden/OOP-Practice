#include<iostream>
#include"implementataion2.cpp"
using namespace std;
int main()
{
    cout<<"我的程式當撲克牌數量多的時候比較慢，因為檢驗是否有重複卡片那邊花比較多的時間，程式是可以跑的，請助教等一下"<<endl;
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
