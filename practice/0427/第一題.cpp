#include<iostream>
#include<cmath>
using namespace std;
float checkhour(string hour)
{
    if(hour=="01")
    {
        return 1;
    }
    else if(hour=="02")
    {
        return 2;
    }
    else if(hour=="03")
    {
        return 3;
    }
    else if(hour=="04")
    {
        return 4;
    }
    else if(hour=="05")
    {
        return 5;
    }
    else if(hour=="06")
    {
        return 6;
    }
    else if(hour=="07")
    {
        return 7;
    }
    else if(hour=="08")
    {
        return 8;
    }
    else if(hour=="09")
    {
        return 9;
    }
    else if(hour=="10")
    {
        return 10;
    }
    else if(hour=="11")
    {
        return 11;
    }
    else if(hour=="12")
    {
        return 12;
    }
    else if(hour=="13")
    {
        return 1;
    }
    else if(hour=="14")
    {
        return 2;
    }
    else if(hour=="15")
    {
        return 3;
    }
    else if(hour=="16")
    {
        return 4;
    }
    else if(hour=="17")
    {
        return 5;
    }
    else if(hour=="18")
    {
        return 6;
    }
    else if(hour=="19")
    {
        return 7;
    }
    else if(hour=="20")
    {
        return 8;
    }
    else if(hour=="21")
    {
        return 9;
    }
    else if(hour=="22")
    {
        return 10;
    }
    else if(hour=="23")
    {
        return 11;
    }
    else if(hour=="00"||hour=="24")
    {
        return 12;
    }
    else
    {
        return 100;
    }
}
int main()
{
    while(1)
    {
        cout<<"please enter hour and minute:"<<endl;
        string hour;
        float minute;
        while(1)
        {
            cin>>hour>>minute;
            if(checkhour(hour)>=50)
            {
                cout<<"You shoule enter correct hour!"<<endl;
            }
            else if(minute<0||minute>=60)
            {
                cout<<"You shoule enter correct minute!"<<endl;
            }
            else
            {
                break;
            }
        }
        float hour1 = checkhour(hour);
        float an = round(abs((30*hour1)-((11*minute)/2)));
        if(an>180)
        {
            an = 360-an;
        }
        cout<<"The answer is: "<<an<<endl;
    }
}
