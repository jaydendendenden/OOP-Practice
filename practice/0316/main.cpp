#include<iostream>
#include"implementation.cpp"
using namespace std;
int main()
{
    cout<<"��l�ɶ���00:00:00 AM"<<endl;
    while(1)
    {
        int test;
        cout<<"1.�]�w�ɶ�"<<endl<<"2.�]�w���"<<endl;
        cin>>test;
        if(test==1)
        {
            cout<<"�г]�w�ɶ� ��J�ɡB���ά�"<<endl;
            int hour,minute,second;
            cin>>hour>>minute>>second;
            if(hour>23)
            {
                cout<<"���~!�]�w���ɶ����~!"<<endl;
            }
            else if(minute>59&&hour<24)
            {
                cout<<"���~!�]�w���ɶ����~!"<<endl;
            }
            else if(second>59&&minute<60&&hour<24)
            {
                cout<<"���~!�]�w���ɶ����~!"<<endl;
            }
            else
            {
                TIME temp(hour,minute,second);
                cout<<"�]�w���ɶ���:";
                temp.showtime();
                cout<<endl;
            }
        }
        else if(test==2)
        {
            cout<<"�п�J�g�L�����"<<endl;
            int second;
            cin>>second;
            cout<<endl;
            TIME temp(second);
            cout<<"�g�L����Ƭ�:";
            temp.showtime();
            cout<<endl;
        }
        else
        {
            break;
        }
    }
}
