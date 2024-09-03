#include<iostream>
#include"implementation.cpp"
using namespace std;
int main()
{
    cout<<"初始時間為00:00:00 AM"<<endl;
    while(1)
    {
        int test;
        cout<<"1.設定時間"<<endl<<"2.設定秒數"<<endl;
        cin>>test;
        if(test==1)
        {
            cout<<"請設定時間 輸入時、分及秒"<<endl;
            int hour,minute,second;
            cin>>hour>>minute>>second;
            if(hour>23)
            {
                cout<<"錯誤!設定的時間有誤!"<<endl;
            }
            else if(minute>59&&hour<24)
            {
                cout<<"錯誤!設定的時間有誤!"<<endl;
            }
            else if(second>59&&minute<60&&hour<24)
            {
                cout<<"錯誤!設定的時間有誤!"<<endl;
            }
            else
            {
                TIME temp(hour,minute,second);
                cout<<"設定的時間為:";
                temp.showtime();
                cout<<endl;
            }
        }
        else if(test==2)
        {
            cout<<"請輸入經過的秒數"<<endl;
            int second;
            cin>>second;
            cout<<endl;
            TIME temp(second);
            cout<<"經過的秒數為:";
            temp.showtime();
            cout<<endl;
        }
        else
        {
            break;
        }
    }
}
