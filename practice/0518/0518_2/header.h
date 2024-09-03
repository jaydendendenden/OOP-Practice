#include<iostream>
#include<vector>
using namespace std;
class crust
{
private:
    string crusttype;
public:
    crust(int counts);
    void setcrusttype(int counts);
    friend class pizza;
};
class pizzasize
{
private:
    string sizes;
    int money;
public:
    pizzasize(int counts);
    void setpizzasize(int counts);
    friend class pizza;
};
class ingredients
{
private:
    string type;
    static int moneyforingredients;
public:
    ingredients(int counts);
    void setingredients(int counts);
    friend class pizza;
};
class pizza
{
private:
    string pizzacrust;
    string sizess;
    vector<string> add;
    int total;
public:
    pizza(crust a,pizzasize b);
    void setcrust(crust a);
    void setsizes(pizzasize b);
    void setadd(ingredients c);
    void printresult();
};

