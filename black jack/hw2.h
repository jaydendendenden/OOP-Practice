#include<iostream>
using namespace std;
class card
{
public:
    string wall;
    card *ptr;
};
class club
{
public:
    static int clubcount;
    card item[14];
    club();
    void setnumber(int number);
    void render();
};
class diamond
{
public:
    static int diamondcount;
    card item[14];
    diamond();
    void setnumber(int number);
    void render();
};
class heart
{
public:
    static int heartcount;
    card item[14];
    heart();
    void setnumber(int number);
    void render();
};
class spade
{
public:
    static int spadecount;
    card item[14];
    spade();
    void setnumber(int number);
    void render();
};
class cardmachine
{
public:
    int cardarray[52];
    int stackptr;
    int number,color;
    cardmachine();
    int checkcard(int* arr,int ptr,int number);
    void rewash();
    void pop();
    int randomnumber();
    int randomcolor();
};
class player
{
public:
    card item[14];
    int cardyouget[5];
    int cardptr;
    int dollar;
    int doublebet;
    int surrender;
    static int pool;
    int betcount;
    int darkcardnumber;
    int darkcardcolor;
    int insurance;
    int boom;
    int speciallist;
    int bankrupt;
    string playername;
    player();
    void render();
    void renewthecardyouget();
    void checkinsurance(int bankerpoint,player &banker);
    int if11point();
    void setdefault();
};

