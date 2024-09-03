#include<iostream>
using namespace std;
class fraction
{
private:
    int numerator;
    int denominator;
public:
    fraction(int,int);
    void setfraction(int,int);
    friend fraction operator+(fraction &a,fraction &b);
    friend fraction operator-(fraction &a,fraction &b);
    friend fraction operator*(fraction &a,fraction &b);
    friend fraction operator/(fraction &a,fraction &b);
    void printfraction();
    int gcd(int a,int b);
};
