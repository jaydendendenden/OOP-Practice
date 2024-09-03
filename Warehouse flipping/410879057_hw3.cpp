#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<string>
#include<cstring>
#include<vector>
#include <iomanip>
using namespace std;
string themap[1000][1000];
int row,column;
int manrow,mancolumn;
int boxrow,boxcolumn;
vector<int> manrow_c,mancolumn_c,boxrow_c,boxcolumn_c;
ifstream mission;
int flag=1;
int wincons=0;
int level=1;
int steps[5]={0};
int stepsflag[5]={0};
char press;
void printgrade();
int chooselevel();
void initializing();
void winthegame();
void printsteps(int a);
void printsteps();
void backoff(); //make suite
void turnup();
void turndown();
void turnleft();
void turnright();
void printmap();
void printrule();
void find2();
void creatmap1();
void creatmap2();
void creatmap3();
void creatmap4(); //for test
void creatmap5(); //for test
int main()
{
    printrule();
    while(1)
    {
        level = chooselevel();
        if(level == 0)
        {
            break;
        }
        if(level == 100)
        {
            printrule();
            continue;
        }
        switch(level)
        {
        case 1:
            creatmap1();
            flag=1;
            break;
        case 2:
            creatmap2();
            flag=1;
            break;
        case 3:
            creatmap3();
            flag=1;
            break;
        case 4:
            creatmap4();
            cout<<"this is just for test"<<endl;
            system("pause");
            flag=0; //we should set flag = 1 if we want to play map4 and set creatmap4
            break;
        case 5:
            creatmap5();
            cout<<"this is just for test"<<endl;
            system("pause");
            flag=0; //we should set flag = 1 if we want to play map5 , and set creatmap5
            break;
        }
        find2();
        cout<<"You can use W / A / S / D to move."<<endl;
        cout<<"Press L can leave."<<endl;
        cout<<"/ = wall"<<endl;
        cout<<"- = road"<<endl;
        cout<<"0 = player"<<endl;
        cout<<"1 = box"<<endl;
        cout<<"2 = destination"<<endl;
        while(flag)
        {
            press = getch();
            if(press=='l'||press=='L')
            {
                break;
            }
            else if(press=='s'||press=='S')
            {
                turndown();
            }
            else if(press=='w'||press=='W')
            {
                turnup();
            }
            else if(press=='a'||press=='A')
            {
                turnleft();
            }
            else if(press=='d'||press=='D')
            {
                turnright();
            }
            else if(press=='r'||press=='R')
            {
                backoff();
            }
        }
    }
}
void turnright()
{
    if(mancolumn>=column-2) //wall
    {
        return;
    }
    else
    {
        if(((mancolumn+1)==boxcolumn)&&(manrow==boxrow)) //near by box
        {
            if(boxcolumn>=column-2)
            {
                return;
            }
            else if(themap[boxrow][boxcolumn+1]=="/")
            {
                return;
            }
            else if(themap[boxrow][boxcolumn+1]=="2")
            {
                if(wincons>1)
                {
                    themap[boxrow][boxcolumn+1]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    wincons--;
                    printmap();
                    cout<<endl;
                    printsteps();
                }
                else
                {
                    themap[boxrow][boxcolumn+1]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    printmap();
                    cout<<endl;
                    printsteps(1);
                    system("pause");
                    winthegame();
                    initializing();
                }
                return;

            }
            else
            {
                themap[boxrow][boxcolumn+1]="1";
                themap[boxrow][boxcolumn]="0";
                themap[manrow][mancolumn]="-";
                boxcolumn++;
                mancolumn++;
                manrow_c.push_back(0);
                mancolumn_c.push_back(1);
                boxrow_c.push_back(0);
                boxcolumn_c.push_back(1);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
        else //not near by box
        {
            if(themap[manrow][mancolumn+1]=="/"||themap[manrow][mancolumn+1]=="2")
            {
                return;
            }
            else
            {
                themap[manrow][mancolumn+1]="0";
                themap[manrow][mancolumn]="-";
                mancolumn++;
                manrow_c.push_back(0);
                mancolumn_c.push_back(1);
                boxrow_c.push_back(0);
                boxcolumn_c.push_back(0);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
    }
}
void turnleft()
{
    if(mancolumn<=1) //wall
    {
        return;
    }
    else
    {
        if(((mancolumn-1)==boxcolumn)&&(manrow==boxrow)) //near by box
        {
            if(boxcolumn<=1)
            {
                return;
            }
            else if(themap[boxrow][boxcolumn-1]=="/")
            {
                return;
            }
            else if(themap[boxrow][boxcolumn-1]=="2")
            {
                if(wincons>1)
                {
                    themap[boxrow][boxcolumn-1]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    wincons--;
                    printmap();
                    cout<<endl;
                    printsteps();
                }
                else
                {
                    themap[boxrow][boxcolumn-1]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    printmap();
                    cout<<endl;
                    printsteps(1);
                    system("pause");
                    winthegame();
                    initializing();
                }
                return;

            }
            else
            {
                themap[boxrow][boxcolumn-1]="1";
                themap[boxrow][boxcolumn]="0";
                themap[manrow][mancolumn]="-";
                boxcolumn--;
                mancolumn--;
                manrow_c.push_back(0);
                mancolumn_c.push_back(-1);
                boxrow_c.push_back(0);
                boxcolumn_c.push_back(-1);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
        else //not near by box
        {
            if(themap[manrow][mancolumn-1]=="/"||themap[manrow][mancolumn-1]=="2")
            {
                return;
            }
            else
            {
                themap[manrow][mancolumn-1]="0";
                themap[manrow][mancolumn]="-";
                mancolumn--;
                manrow_c.push_back(0);
                mancolumn_c.push_back(-1);
                boxrow_c.push_back(0);
                boxcolumn_c.push_back(0);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
    }
}
void turndown()
{
    if(manrow>=row-2) //wall
    {
        return;
    }
    else
    {
        if(((manrow+1)==boxrow)&&(mancolumn==boxcolumn)) //near by box
        {
            if(boxrow>=row-2)
            {
                return;
            }
            else if(themap[boxrow+1][boxcolumn]=="/")
            {
                return;
            }
            else if(themap[boxrow+1][boxcolumn]=="2")
            {

                if(wincons>1)
                {
                    themap[boxrow+1][boxcolumn]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    wincons--;
                    printmap();
                    cout<<endl;
                    printsteps();
                }
                else
                {
                    themap[boxrow+1][boxcolumn]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    printmap();
                    cout<<endl;
                    printsteps(1);
                    system("pause");
                    winthegame();
                    initializing();
                }
                return;

            }
            else
            {
                themap[boxrow+1][boxcolumn]="1";
                themap[boxrow][boxcolumn]="0";
                themap[manrow][mancolumn]="-";
                boxrow++;
                manrow++;
                manrow_c.push_back(1);
                mancolumn_c.push_back(0);
                boxrow_c.push_back(1);
                boxcolumn_c.push_back(0);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
        else //not near by box
        {
            if(themap[manrow+1][mancolumn]=="/"||themap[manrow+1][mancolumn]=="2")
            {
                return;
            }
            else
            {
                themap[manrow+1][mancolumn]="0";
                themap[manrow][mancolumn]="-";
                manrow++;
                manrow_c.push_back(1);
                mancolumn_c.push_back(0);
                boxrow_c.push_back(0);
                boxcolumn_c.push_back(0);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
    }
}
void turnup()
{
    if(manrow<=1) //wall
    {
        return;
    }
    else
    {
        if(((manrow-1)==boxrow)&&(mancolumn==boxcolumn)) //near by box
        {
            if(boxrow<=1)
            {
                return;
            }
            else if(themap[boxrow-1][boxcolumn]=="/")
            {
                return;
            }
            else if(themap[boxrow-1][boxcolumn]=="2")
            {
                if(wincons>1)
                {
                    themap[boxrow-1][boxcolumn]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    wincons--;
                    printmap();
                    cout<<endl;
                    printsteps();
                }
                else
                {
                    themap[boxrow-1][boxcolumn]="2";
                    themap[boxrow][boxcolumn]="0";
                    themap[manrow][mancolumn]="-";
                    printmap();
                    cout<<endl;
                    printsteps(1);
                    system("pause");
                    winthegame();
                    initializing();
                }
                return;

            }
            else
            {
                themap[boxrow-1][boxcolumn]="1";
                themap[boxrow][boxcolumn]="0";
                themap[manrow][mancolumn]="-";
                boxrow--;
                manrow--;
                manrow_c.push_back(-1);
                mancolumn_c.push_back(0);
                boxrow_c.push_back(-1);
                boxcolumn_c.push_back(0);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
        else //not near by box
        {
            if(themap[manrow-1][mancolumn]=="/"||themap[manrow-1][mancolumn]=="2")
            {
                return;
            }
            else
            {
                themap[manrow-1][mancolumn]="0";
                themap[manrow][mancolumn]="-";
                manrow--;
                manrow_c.push_back(-1);
                mancolumn_c.push_back(0);
                boxrow_c.push_back(0);
                boxcolumn_c.push_back(0);
                printmap();
                cout<<endl;
                printsteps();
            }
        }
    }
}
void printmap()
{
    system("CLS");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<themap[i][j];
        }
        cout<<endl;
    }
}
void printrule()
{
    system("CLS");
    system("color D");
    cout<<"Welcome to this game!"<<endl;
    cout<<"Your goal is to push the box into the destination."<<endl;
    cout<<"Your position is 0 , box is 1 and destination is 2."<<endl;
    cout<<"You can press 'w' to move UP , press 's' to move DOWN, press 'a' to move LEFT and press 'd' to move RIGHT."<<endl;
    cout<<"Press 'r' can return the previous step."<<endl;
    system("pause");
	system("CLS");
	system("color C");
}
void creatmap1()
{
    mission.open("mission1.txt");
    mission>>row>>column;
    char temp;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mission>>temp;
            themap[i][j]=temp;
            if(temp=='0')
            {
                manrow=i;
                mancolumn=j;
            }
            if(temp=='1')
            {
                boxrow=i;
                boxcolumn=j;
            }
        }
    }
    mission.close();
    printmap();
}
void creatmap2()
{
    mission.open("mission2.txt");
    mission>>row>>column;
    char temp;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mission>>temp;
            themap[i][j]=temp;
            if(temp=='0')
            {
                manrow=i;
                mancolumn=j;
            }
            if(temp=='1')
            {
                boxrow=i;
                boxcolumn=j;
            }
        }
    }
    mission.close();
    printmap();
}
void creatmap3()
{
    mission.open("mission3.txt");
    mission>>row>>column;
    char temp;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mission>>temp;
            themap[i][j]=temp;
            if(temp=='0')
            {
                manrow=i;
                mancolumn=j;
            }
            if(temp=='1')
            {
                boxrow=i;
                boxcolumn=j;
            }
        }
    }
    mission.close();
    printmap();
}
void creatmap4()
{
    /*mission.open("mission4.txt");
    mission>>row>>column;
    char temp;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mission>>temp;
            themap[i][j]=temp;
            if(temp=='0')
            {
                manrow=i;
                mancolumn=j;
            }
            if(temp=='1')
            {
                boxrow=i;
                boxcolumn=j;
            }
        }
    }
    mission.close();
    printmap();*/
}
void creatmap5()
{
    /*mission.open("mission5.txt");
    mission>>row>>column;
    char temp;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            mission>>temp;
            themap[i][j]=temp;
            if(temp=='0')
            {
                manrow=i;
                mancolumn=j;
            }
            if(temp=='1')
            {
                boxrow=i;
                boxcolumn=j;
            }
        }
    }
    mission.close();
    printmap();*/
}
void winthegame()
{
    system("CLS");
    cout<<"Congradulation!! You have won the mission "<<level<<endl;
    stepsflag[level-1]=1;
    printsteps(1);
    steps[level-1]=manrow_c.size()+1;
    cout<<endl;
    printgrade();
}
void initializing()
{
    vector<int>().swap(manrow_c);
    vector<int>().swap(mancolumn_c);
    vector<int>().swap(boxrow_c);
    vector<int>().swap(boxcolumn_c);
    flag=0;
    wincons=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            themap[i][j]="";
        }
    }
}
void backoff()
{
    if(mancolumn_c.size()==0)
    {
        return;
    }
    else
    {
        int manrowtemp=manrow_c[manrow_c.size()-1];
        int mancolumntemp=mancolumn_c[mancolumn_c.size()-1];
        int boxrowtemp=boxrow_c[boxrow_c.size()-1];
        int boxcolumntemp=boxcolumn_c[boxcolumn_c.size()-1];
        manrow_c.pop_back();
        mancolumn_c.pop_back();
        boxrow_c.pop_back();
        boxcolumn_c.pop_back();
        if(manrowtemp!=0)
        {
            if(boxrowtemp!=0)
            {
                themap[manrow+((-1)*manrowtemp)][mancolumn]="0";
                themap[boxrow+((-1)*boxrowtemp)][boxcolumn]="1";
                themap[boxrow][boxcolumn]="-";
                manrow=manrow+(-1)*manrowtemp;
                boxrow=boxrow+(-1)*boxrowtemp;
            }
            else
            {
                themap[manrow+((-1)*manrowtemp)][mancolumn]="0";
                themap[manrow][mancolumn]="-";
                manrow=manrow+(-1)*manrowtemp;
            }
        }
        if(mancolumntemp!=0)
        {
            if(boxcolumntemp!=0)
            {
                themap[manrow][mancolumn+((-1)*mancolumntemp)]="0";
                themap[boxrow][boxcolumn+((-1)*mancolumntemp)]="1";
                themap[boxrow][boxcolumn]="-";
                mancolumn=mancolumn+(-1)*mancolumntemp;
                boxcolumn=boxcolumn+(-1)*boxcolumntemp;
            }
            else
            {
                themap[manrow][mancolumn+((-1)*mancolumntemp)]="0";
                themap[manrow][mancolumn]="-";
                mancolumn=mancolumn+(-1)*mancolumntemp;
            }
        }
        printmap();
        cout<<endl;
        printsteps();
    }
}
void printsteps(int a)
{
    int v=manrow_c.size();
    cout<<"You have totally spend "<<v+a<<" steps.";
}
int chooselevel()
{
    system("CLS");
    cout<<"What level do you want to play?"<<endl;
    cout<<"We have 1~5 level can choose!"<<endl;
    cout<<"(PRESS 0 can leave the game and PRESS 100 can see the rule again.)"<<endl;
    int temp;
    while(1)
    {
        cin>>temp;
        if((temp<=5&&temp>=0)||temp==100)
        {
            return temp;
        }
        else
        {
            cout<<"please enter 0~5 or 100: ";
        }
    }
}
void printsteps()
{
    int v=manrow_c.size();
    cout<<"You have totally spend "<<v<<" steps.";
}
void printgrade()
{
    system("color B");
    cout <<"LEVEL" <<setw(6) << "|" <<"GRADE"<<setw(9)<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        cout <<"LEVEL" <<i+1<<setw(5)<<"|";
        if(stepsflag[i]==1)
        {
            cout<<"Total "<<steps[i]<<" steps"<<endl;
        }
        else
        {
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"Try to use less steps!"<<endl;
    system("pause");
    system("color C");
}
void find2()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(themap[i][j]=="2")
            {
                wincons++;
            }
        }
    }
}
