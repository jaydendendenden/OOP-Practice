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
        cout<<"歡迎來到披薩店、按1開始、按0退出: ";
        while(1)
        {
            cin>>temp;
            if(temp<=1&&temp>=0)
            {
                break;
            }
            else
            {
                cout<<"你要輸入1或0: ";
            }
        }
        if(temp==0)
        {
            break;
        }
        system("cls");
        cout<<"選擇披薩餅皮: "<<endl;
        cout<<"1. 芝心"<<endl<<"2. 薄脆"<<endl<<"3. 鬆厚"<<endl;
        while(1)
        {
            cin>>temp;
            if(temp>=1&&temp<=3)
            {
                break;
            }
            else
            {
                cout<<"你要輸入1~3: ";
            }
        }
        cout<<endl;
        crust a(temp);
        cout<<"選擇Pizza大小: "<<endl;
        cout<<"1. 小"<<endl<<"2. 中"<<endl<<"3. 大"<<endl;
        while(1)
        {
            cin>>temp;
            if(temp>=1&&temp<=3)
            {
                break;
            }
            else
            {
                cout<<"你要輸入1~3: ";
            }
        }
        cout<<endl;
        pizzasize b(temp);
        pizza mypizza(a,b);
        while(1)
        {
            cout<<"選擇Pizza配料: "<<endl;
            cout<<"1. 鳳梨"<<endl<<"2. 玉米"<<endl<<"3. 起司"<<endl<<"4. 蟹肉條"<<endl<<"5. 番茄"<<endl<<"6. 青椒"<<endl<<"7. 臘肉"<<endl<<"8. 火腿"<<endl<<"9. 牛肉"<<endl<<"0. 結帳"<<endl;
            while(1)
            {
                cin>>temp;
                if(temp>=0&&temp<=9)
                {
                    break;
                }
                else
                {
                    cout<<"你要輸入0~9: ";
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
