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
        this->crusttype="�ۤ�";
        break;
    case 2:
        this->crusttype="����";
        break;
    case 3:
        this->crusttype="�P�p";
        break;
    default:
        this->crusttype="���~";
        break;
    }
}
void crust::setcrusttype(int counts)
{
    switch(counts)
    {
    case 1:
        this->crusttype="�ۤ�";
        break;
    case 2:
        this->crusttype="����";
        break;
    case 3:
        this->crusttype="�P�p";
        break;
    default:
        this->crusttype="���~";
        break;
    }
}
pizzasize::pizzasize(int counts)
{
    switch(counts)
    {
    case 1:
        this->sizes="�p";
        this->money=300;
        break;
    case 2:
        this->sizes="��";
        this->money=420;
        break;
    case 3:
        this->sizes="�j";
        this->money=510;
        break;
    default:
        this->sizes="���~";
        this->money=0;
    }
}
void pizzasize::setpizzasize(int counts)
{
    switch(counts)
    {
    case 1:
        this->sizes="�p";
        this->money=300;
        break;
    case 2:
        this->sizes="��";
        this->money=420;
        break;
    case 3:
        this->sizes="�j";
        this->money=510;
        break;
    default:
        this->sizes="���~";
        this->money=0;
    }
}
ingredients::ingredients(int counts)
{
    switch(counts)
    {
    case 1:
        this->type="���";
        break;
    case 2:
        this->type="�ɦ�";
        break;
    case 3:
        this->type="�_�q";
        break;
    case 4:
        this->type="�ɦױ�";
        break;
    case 5:
        this->type="�f�X";
        break;
    case 6:
        this->type="�C��";
        break;
    case 7:
        this->type="þ��";
        break;
    case 8:
        this->type="���L";
        break;
    case 9:
        this->type="����";
        break;
    default:
        this->type="���~";
        break;
    }
}
void ingredients::setingredients(int counts)
{
    switch(counts)
    {
    case 1:
        this->type="���";
        break;
    case 2:
        this->type="�ɦ�";
        break;
    case 3:
        this->type="�_�q";
        break;
    case 4:
        this->type="�ɦױ�";
        break;
    case 5:
        this->type="�f�X";
        break;
    case 6:
        this->type="�C��";
        break;
    case 7:
        this->type="þ��";
        break;
    case 8:
        this->type="���L";
        break;
    case 9:
        this->type="����";
        break;
    default:
        this->type="���~";
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
    cout<<"�A��Pizza:"<<endl;
    cout<<"���: "<<this->pizzacrust<<endl;
    cout<<"�j�p: "<<this->sizess<<endl;
    cout<<"�t��: ";
    for(int i=0;i<this->add.size();i++)
    {
        cout<<this->add[i];
        if(i+1<this->add.size())
        {
            cout<<" & ";
        }
    }
    cout<<endl<<endl;
    cout<<"�A��Pizza����: $"<<this->total<<endl;
    cout<<"���´f�U"<<endl;
}
