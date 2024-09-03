#include<iostream>
#include<vector>
#include"header.h"
using namespace std;
int ingredients::moneyforingredients=30;
crust::crust(int counts)
{
    switch(counts)
    {
    case 1:
        this->crusttype="ªÛ¤ß";
        break;
    case 2:
        this->crusttype="Á¡¯Ü";
        break;
    case 3:
        this->crusttype="ÃP«p";
        break;
    default:
        this->crusttype="¿ù»~";
        break;
    }
}
void crust::setcrusttype(int counts)
{
    switch(counts)
    {
    case 1:
        this->crusttype="ªÛ¤ß";
        break;
    case 2:
        this->crusttype="Á¡¯Ü";
        break;
    case 3:
        this->crusttype="ÃP«p";
        break;
    default:
        this->crusttype="¿ù»~";
        break;
    }
}
pizzasize::pizzasize(int counts)
{
    switch(counts)
    {
    case 1:
        this->sizes="¤p";
        this->money=300;
        break;
    case 2:
        this->sizes="¤¤";
        this->money=420;
        break;
    case 3:
        this->sizes="¤j";
        this->money=510;
        break;
    default:
        this->sizes="¿ù»~";
        this->money=0;
    }
}
void pizzasize::setpizzasize(int counts)
{
    switch(counts)
    {
    case 1:
        this->sizes="¤p";
        this->money=300;
        break;
    case 2:
        this->sizes="¤¤";
        this->money=420;
        break;
    case 3:
        this->sizes="¤j";
        this->money=510;
        break;
    default:
        this->sizes="¿ù»~";
        this->money=0;
    }
}
ingredients::ingredients(int counts)
{
    switch(counts)
    {
    case 1:
        this->type="»ñ±ù";
        break;
    case 2:
        this->type="¥É¦Ì";
        break;
    case 3:
        this->type="°_¥q";
        break;
    case 4:
        this->type="ÃÉ¦×±ø";
        break;
    case 5:
        this->type="µf­X";
        break;
    case 6:
        this->type="«C´Ô";
        break;
    case 7:
        this->type="Ã¾¦×";
        break;
    case 8:
        this->type="¤õ»L";
        break;
    case 9:
        this->type="¤û¦×";
        break;
    default:
        this->type="¿ù»~";
        break;
    }
}
void ingredients::setingredients(int counts)
{
    switch(counts)
    {
    case 1:
        this->type="»ñ±ù";
        break;
    case 2:
        this->type="¥É¦Ì";
        break;
    case 3:
        this->type="°_¥q";
        break;
    case 4:
        this->type="ÃÉ¦×±ø";
        break;
    case 5:
        this->type="µf­X";
        break;
    case 6:
        this->type="«C´Ô";
        break;
    case 7:
        this->type="Ã¾¦×";
        break;
    case 8:
        this->type="¤õ»L";
        break;
    case 9:
        this->type="¤û¦×";
        break;
    default:
        this->type="¿ù»~";
        break;
    }
}
pizza::pizza(crust a,pizzasize b)
{
    this->pizzacrust=a.crusttype;
    this->sizess=b.sizes;
    this->total=b.money;
}
void pizza::setcrust(crust a)
{
    this->pizzacrust=a.crusttype;
}
void pizza::setsizes(pizzasize b)
{
    this->sizess=b.sizes;
}
void pizza::setadd(ingredients c)
{
    this->add.push_back(c.type);
    this->total+=ingredients::moneyforingredients;
}
void pizza::printresult()
{
    cout<<"§AªºPizza:"<<endl;
    cout<<"»æ¥Ö: "<<this->pizzacrust<<endl;
    cout<<"¤j¤p: "<<this->sizess<<endl;
    cout<<"°t®Æ: ";
    for(int i=0;i<this->add.size();i++)
    {
        cout<<this->add[i];
        if(i+1<this->add.size())
        {
            cout<<" & ";
        }
    }
    cout<<endl<<endl;
    cout<<"§AªºPizza»ù®æ: $"<<this->total<<endl;
    cout<<"ÁÂÁÂ´fÅU"<<endl;
}
