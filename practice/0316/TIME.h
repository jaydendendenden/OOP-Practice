#include<iostream>
using namespace std;
class TIME
{
private:
    string hour;
    string minute;
    string second;
    string part;
public:
    void settime(int hour,int minute,int second);
    void settime(int second);
    void showtime();
    TIME(int hour,int minute,int second);
    TIME(int second);
};
