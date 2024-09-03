#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<ctime>
#include<bits/stdc++.h>
#include "hw2.h"
using namespace std;
int club::clubcount=0;
int diamond::diamondcount=0;
int heart::heartcount=0;
int spade::spadecount=0;
int player::pool=0;
club::club()
{
    this->item[0].wall=" ";
    this->item[1].wall=" ********-********  ";
    this->item[2].wall="*A                * ";
    this->item[3].wall="*                 * ";
    this->item[4].wall="*        *        * ";
    this->item[5].wall="*       ***       * ";
    this->item[6].wall="*     *  *  *     * ";
    this->item[7].wall="*    *** * ***    * ";
    this->item[8].wall="*     *  *  *     * ";
    this->item[9].wall="*       ***       * ";
    this->item[10].wall="*      *****      * ";
    this->item[11].wall="*                 * ";
    this->item[12].wall="*                A* ";
    this->item[13].wall=" ********-********  ";
    this->item[0].ptr=NULL;
    this->item[1].ptr=NULL;
    this->item[2].ptr=NULL;
    this->item[3].ptr=NULL;
    this->item[4].ptr=NULL;
    this->item[5].ptr=NULL;
    this->item[6].ptr=NULL;
    this->item[7].ptr=NULL;
    this->item[8].ptr=NULL;
    this->item[9].ptr=NULL;
    this->item[10].ptr=NULL;
    this->item[11].ptr=NULL;
    this->item[12].ptr=NULL;
    this->item[13].ptr=NULL;
    clubcount++;
}
diamond::diamond()
{
    this->item[0].wall=" ";
    this->item[1].wall=" ********-********  ";
    this->item[2].wall="*A                * ";
    this->item[3].wall="*                 * ";
    this->item[4].wall="*        *        * ";
    this->item[5].wall="*       ***       * ";
    this->item[6].wall="*      *****      * ";
    this->item[7].wall="*     *******     * ";
    this->item[8].wall="*      *****      * ";
    this->item[9].wall="*       ***       * ";
    this->item[10].wall="*        *        * ";
    this->item[11].wall="*                 * ";
    this->item[12].wall="*                A* ";
    this->item[13].wall=" ********-********  ";
    this->item[0].ptr=NULL;
    this->item[1].ptr=NULL;
    this->item[2].ptr=NULL;
    this->item[3].ptr=NULL;
    this->item[4].ptr=NULL;
    this->item[5].ptr=NULL;
    this->item[6].ptr=NULL;
    this->item[7].ptr=NULL;
    this->item[8].ptr=NULL;
    this->item[9].ptr=NULL;
    this->item[10].ptr=NULL;
    this->item[11].ptr=NULL;
    this->item[12].ptr=NULL;
    this->item[13].ptr=NULL;
    diamondcount++;
}
heart::heart()
{
    this->item[0].wall=" ";
    this->item[1].wall=" ********-********  ";
    this->item[2].wall="*A                * ";
    this->item[3].wall="*                 * ";
    this->item[4].wall="*    *       *    * ";
    this->item[5].wall="*   ***     ***   * ";
    this->item[6].wall="*  *************  * ";
    this->item[7].wall="*    *********    * ";
    this->item[8].wall="*     *******     * ";
    this->item[9].wall="*       ***       * ";
    this->item[10].wall="*        *        * ";
    this->item[11].wall="*                 * ";
    this->item[12].wall="*                A* ";
    this->item[13].wall=" ********-********  ";
    this->item[0].ptr=NULL;
    this->item[1].ptr=NULL;
    this->item[2].ptr=NULL;
    this->item[3].ptr=NULL;
    this->item[4].ptr=NULL;
    this->item[5].ptr=NULL;
    this->item[6].ptr=NULL;
    this->item[7].ptr=NULL;
    this->item[8].ptr=NULL;
    this->item[9].ptr=NULL;
    this->item[10].ptr=NULL;
    this->item[11].ptr=NULL;
    this->item[12].ptr=NULL;
    this->item[13].ptr=NULL;
    heartcount++;
}
spade::spade()
{
    this->item[0].wall=" ";
    this->item[1].wall=" ********-********  ";
    this->item[2].wall="*A                * ";
    this->item[3].wall="*                 * ";
    this->item[4].wall="*        *        * ";
    this->item[5].wall="*       ***       * ";
    this->item[6].wall="*     *******     * ";
    this->item[7].wall="*   ***********   * ";
    this->item[8].wall="*    *** * ***    * ";
    this->item[9].wall="*       ***       * ";
    this->item[10].wall="*     *******     * ";
    this->item[11].wall="*                 * ";
    this->item[12].wall="*                A* ";
    this->item[13].wall=" ********-********  ";
    this->item[0].ptr=NULL;
    this->item[1].ptr=NULL;
    this->item[2].ptr=NULL;
    this->item[3].ptr=NULL;
    this->item[4].ptr=NULL;
    this->item[5].ptr=NULL;
    this->item[6].ptr=NULL;
    this->item[7].ptr=NULL;
    this->item[8].ptr=NULL;
    this->item[9].ptr=NULL;
    this->item[10].ptr=NULL;
    this->item[11].ptr=NULL;
    this->item[12].ptr=NULL;
    this->item[13].ptr=NULL;
    spadecount++;
}
void club::setnumber(int number)
{
    if(number==1)
    {
        return;
    }
    else if(number==10)
    {
        this->item[2].wall="*10               * ";
        this->item[12].wall="*               10* ";
    }
    else if(number==11)
    {
        this->item[2].wall="*J                * ";
        this->item[12].wall="*                J* ";
    }
    else if(number==12)
    {
        this->item[2].wall="*Q                * ";
        this->item[12].wall="*                Q* ";
    }
    else if(number==13)
    {
        this->item[2].wall="*K                * ";
        this->item[12].wall="*                K* ";
    }
    else if(number==2)
    {
        this->item[2].wall="*2                * ";
        this->item[12].wall="*                2* ";
    }
    else if(number==3)
    {
        this->item[2].wall="*3                * ";
        this->item[12].wall="*                3* ";
    }
    else if(number==4)
    {
        this->item[2].wall="*4                * ";
        this->item[12].wall="*                4* ";
    }
    else if(number==5)
    {
        this->item[2].wall="*5                * ";
        this->item[12].wall="*                5* ";
    }
    else if(number==6)
    {
        this->item[2].wall="*6                * ";
        this->item[12].wall="*                6* ";
    }
    else if(number==7)
    {
        this->item[2].wall="*7                * ";
        this->item[12].wall="*                7* ";
    }
    else if(number==8)
    {
        this->item[2].wall="*8                * ";
        this->item[12].wall="*                8* ";
    }
    else
    {
        this->item[2].wall="*9                * ";
        this->item[12].wall="*                9* ";
    }
}
void diamond::setnumber(int number)
{
    if(number==1)
    {
        return;
    }
    else if(number==10)
    {
        this->item[2].wall="*10               * ";
        this->item[12].wall="*               10* ";
    }
    else if(number==11)
    {
        this->item[2].wall="*J                * ";
        this->item[12].wall="*                J* ";
    }
    else if(number==12)
    {
        this->item[2].wall="*Q                * ";
        this->item[12].wall="*                Q* ";
    }
    else if(number==13)
    {
        this->item[2].wall="*K                * ";
        this->item[12].wall="*                K* ";
    }
    else if(number==2)
    {
        this->item[2].wall="*2                * ";
        this->item[12].wall="*                2* ";
    }
    else if(number==3)
    {
        this->item[2].wall="*3                * ";
        this->item[12].wall="*                3* ";
    }
    else if(number==4)
    {
        this->item[2].wall="*4                * ";
        this->item[12].wall="*                4* ";
    }
    else if(number==5)
    {
        this->item[2].wall="*5                * ";
        this->item[12].wall="*                5* ";
    }
    else if(number==6)
    {
        this->item[2].wall="*6                * ";
        this->item[12].wall="*                6* ";
    }
    else if(number==7)
    {
        this->item[2].wall="*7                * ";
        this->item[12].wall="*                7* ";
    }
    else if(number==8)
    {
        this->item[2].wall="*8                * ";
        this->item[12].wall="*                8* ";
    }
    else
    {
        this->item[2].wall="*9                * ";
        this->item[12].wall="*                9* ";
    }
}
void heart::setnumber(int number)
{
    if(number==1)
    {
        return;
    }
    else if(number==10)
    {
        this->item[2].wall="*10               * ";
        this->item[12].wall="*               10* ";
    }
    else if(number==11)
    {
        this->item[2].wall="*J                * ";
        this->item[12].wall="*                J* ";
    }
    else if(number==12)
    {
        this->item[2].wall="*Q                * ";
        this->item[12].wall="*                Q* ";
    }
    else if(number==13)
    {
        this->item[2].wall="*K                * ";
        this->item[12].wall="*                K* ";
    }
    else if(number==2)
    {
        this->item[2].wall="*2                * ";
        this->item[12].wall="*                2* ";
    }
    else if(number==3)
    {
        this->item[2].wall="*3                * ";
        this->item[12].wall="*                3* ";
    }
    else if(number==4)
    {
        this->item[2].wall="*4                * ";
        this->item[12].wall="*                4* ";
    }
    else if(number==5)
    {
        this->item[2].wall="*5                * ";
        this->item[12].wall="*                5* ";
    }
    else if(number==6)
    {
        this->item[2].wall="*6                * ";
        this->item[12].wall="*                6* ";
    }
    else if(number==7)
    {
        this->item[2].wall="*7                * ";
        this->item[12].wall="*                7* ";
    }
    else if(number==8)
    {
        this->item[2].wall="*8                * ";
        this->item[12].wall="*                8* ";
    }
    else
    {
        this->item[2].wall="*9                * ";
        this->item[12].wall="*                9* ";
    }
}
void spade::setnumber(int number)
{
    if(number==1)
    {
        return;
    }
    else if(number==10)
    {
        this->item[2].wall="*10               * ";
        this->item[12].wall="*               10* ";
    }
    else if(number==11)
    {
        this->item[2].wall="*J                * ";
        this->item[12].wall="*                J* ";
    }
    else if(number==12)
    {
        this->item[2].wall="*Q                * ";
        this->item[12].wall="*                Q* ";
    }
    else if(number==13)
    {
        this->item[2].wall="*K                * ";
        this->item[12].wall="*                K* ";
    }
    else if(number==2)
    {
        this->item[2].wall="*2                * ";
        this->item[12].wall="*                2* ";
    }
    else if(number==3)
    {
        this->item[2].wall="*3                * ";
        this->item[12].wall="*                3* ";
    }
    else if(number==4)
    {
        this->item[2].wall="*4                * ";
        this->item[12].wall="*                4* ";
    }
    else if(number==5)
    {
        this->item[2].wall="*5                * ";
        this->item[12].wall="*                5* ";
    }
    else if(number==6)
    {
        this->item[2].wall="*6                * ";
        this->item[12].wall="*                6* ";
    }
    else if(number==7)
    {
        this->item[2].wall="*7                * ";
        this->item[12].wall="*                7* ";
    }
    else if(number==8)
    {
        this->item[2].wall="*8                * ";
        this->item[12].wall="*                8* ";
    }
    else
    {
        this->item[2].wall="*9                * ";
        this->item[12].wall="*                9* ";
    }
}
void club::render()
{
    for(int i=0;i<14;i++)
    {
        card *temp=&item[i];
        while(temp!=NULL)
        {
            cout<<temp->wall;
            temp=temp->ptr;
        }
        cout<<endl;
    }
}
void diamond::render()
{
    for(int i=0;i<14;i++)
    {
        card *temp=&item[i];
        while(temp!=NULL)
        {
            cout<<temp->wall;
            temp=temp->ptr;
        }
        cout<<endl;
    }
}
void heart::render()
{
    for(int i=0;i<14;i++)
    {
        card *temp=&item[i];
        while(temp!=NULL)
        {
            cout<<temp->wall;
            temp=temp->ptr;
        }
        cout<<endl;
    }
}
void spade::render()
{
    for(int i=0;i<14;i++)
    {
        card *temp=&item[i];
        while(temp!=NULL)
        {
            cout<<temp->wall;
            temp=temp->ptr;
        }
        cout<<endl;
    }
}
cardmachine::cardmachine()
{
    for(int i=0;i<52;i++) //set cardarray
    {
        this->cardarray[i]=i;
    }
    this->stackptr=51; //set stack
    srand(time(NULL));
    random_shuffle(this->cardarray,this->cardarray+52);
    this->number=cardarray[stackptr]%13+1;
    this->color=cardarray[stackptr]/13+1;
}
int cardmachine::checkcard(int* arr,int ptr,int number)
{
    while(ptr>-1)
    {
        if(arr[ptr]==number)
        {
            return 0;
        }
        else
        {
            ptr--;
        }
    }
    return 1;
}
void cardmachine::rewash()
{
   for(int i=0;i<52;i++) //set cardarray
    {
        this->cardarray[i]=i;
    }
    this->stackptr=51; //set stack
    srand(time(NULL));
    random_shuffle(this->cardarray,this->cardarray+52);
}
void cardmachine::pop()
{
    if(stackptr==-1)
    {
        cout<<"No card! Rewash!"<<endl;
        rewash();
    }
    else
    {
        this->number=this->cardarray[stackptr]%13+1;
        this->color=this->cardarray[stackptr]/13+1;
        this->stackptr--;
    }
}
player::player()
{
    for(int i=0;i<14;i++)
    {
        this->item[i].wall="";
        this->item[i].ptr=NULL;
    }
    for(int i=0;i<5;i++)
    {
        this->cardyouget[i]=-1;
    }
    this->dollar=10000;
    this->betcount=0;
    this->pool=0;
    this->darkcardnumber=-1;
    this->darkcardcolor=-1;
    this->cardptr=0;
    this->insurance=0;
    this->doublebet=0;
    this->surrender=0;
    this->boom=0;
    this->bankrupt=0;
    this->speciallist=0;
}
void player::render()
{
    for(int i=0;i<14;i++)
    {
        card *temp=&item[i];
        while(temp!=NULL)
        {
            cout<<temp->wall;
            temp=temp->ptr;
        }
        cout<<endl;
    }
}
void player::renewthecardyouget()
{
    for(int i=0;i<5;i++)
    {
        this->cardyouget[i]=-1;
    }
}
void player::checkinsurance(int bankerpoint,player &banker)
{
    if(this->insurance==1)
    {
        if(bankerpoint==21)
        {
            this->dollar+=this->betcount;
            banker.dollar-=this->betcount;
        }
        else
        {
            this->dollar=this->dollar-(this->betcount)/2;
            banker.dollar=banker.dollar+(this->betcount)/2;
        }
    }
}
int player::if11point()
{
    if(this->cardyouget[0]%13-1==0)
    {
        if((this->cardyouget[1]%13-1)>=10&&(this->cardyouget[1]-1)%13<=12)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if((this->cardyouget[1]%13-1)>=10&&(this->cardyouget[1]-1)%13<=12)
    {
        if(this->cardyouget[1]%13==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if((this->cardyouget[0]%13)+(this->cardyouget[1]%13)==11)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void player::setdefault()
{
    for(int i=0;i<14;i++)
    {
        this->item[i].wall="";
        this->item[i].ptr=NULL;
    }
    for(int i=0;i<5;i++)
    {
        this->cardyouget[i]=-1;
    }
    this->betcount=0;
    this->pool=0;
    this->darkcardnumber=-1;
    this->darkcardcolor=-1;
    this->cardptr=0;
    this->insurance=0;
    this->doublebet=0;
    this->surrender=0;
    this->speciallist=0;
    this->boom=0;
    this->bankrupt=0;
    player::pool=0;
    for(int i=0;i<5;i++)
    {
        this->cardyouget[i]=-1;
    }
}
