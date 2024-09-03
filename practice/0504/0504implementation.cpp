#include<iostream>
#include"0504head.h"
using namespace std;
int fraction::gcd(int a,int b)
{
    int temp;
    while( b!=0 )
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
fraction::fraction(int numerator=0,int denominator=0)
{
    this->numerator=numerator;
    this->denominator=denominator;
}
fraction operator+(fraction &a,fraction &b)
{
    int newnumerator=(a.numerator*b.denominator)+(b.numerator*a.denominator);
    int newdenominator=(a.denominator*b.denominator);
    int temp=a.gcd(newnumerator,newdenominator);
    fraction *test=new fraction(newnumerator/temp,newdenominator/temp);
    return *test;
}
fraction operator-(fraction &a,fraction &b)
{
    int flag=0;
    int newnumerator=(a.numerator*b.denominator)-(b.numerator*a.denominator);
    if(newnumerator<0)
    {
        newnumerator=abs(newnumerator);
        flag=1;
    }
    int newdenominator=(a.denominator*b.denominator);
    int temp=a.gcd(newnumerator,newdenominator);
    if(flag==1)
    {
        newnumerator=newnumerator-2*newnumerator;
    }
    fraction *test=new fraction(newnumerator/temp,newdenominator/temp);
    return *test;
}
fraction operator*(fraction &a,fraction &b)
{
    int newnumerator=a.numerator*b.numerator;
    int newdenominator=a.denominator*b.denominator;
    int temp=a.gcd(newnumerator,newdenominator);
    fraction *test=new fraction(newnumerator/temp,newdenominator/temp);
    return *test;
}
fraction operator/(fraction &a,fraction &b)
{
    int newnumerator=a.numerator*b.denominator;
    int newdenominator=a.denominator*b.numerator;
    int temp=a.gcd(newnumerator,newdenominator);
    fraction *test=new fraction(newnumerator/temp,newdenominator/temp);
    return *test;
}
void fraction::printfraction()
{
    if(this->numerator==0)
    {
        cout<<this->numerator;
    }
    else if(this->denominator==1)
    {
        cout<<this->numerator;
    }
    else
    {
        cout<<this->numerator<<"/"<<this->denominator;
    }
}
void fraction::setfraction(int numerator=0,int denominator=0)
{
    this->numerator=numerator;
    this->denominator=denominator;
}
