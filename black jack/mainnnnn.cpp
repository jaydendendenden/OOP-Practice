#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<ctime>
#include"implementation.cpp"
using namespace std;
void connectforplayerandcard(card* one,card *two)
{
    for(int i=0;i<14;i++)
    {
        card *ptr1=&one[i];
        while(ptr1->ptr!=NULL)
        {
            ptr1=ptr1->ptr;
        }
        ptr1->ptr=&two[i];
    }
}
int decidebankerfirsttime(int playernumber)
{
    if(playernumber==2)
    {
        srand(time(NULL));
        int temp;
        temp = rand()%2;
        if(temp==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(playernumber==3)
    {
        srand(time(NULL));
        int temp;
        temp = rand()%3;
        if(temp==0)
        {
            return 0;
        }
        else if(temp==1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        srand(time(NULL));
        int temp;
        temp = rand()%4;
        if(temp==0)
        {
            return 0;
        }
        else if(temp==1)
        {
            return 1;
        }
        else if(temp==2)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}
int checkallsurrender(player *playerlist,int playernumber)
{
    int temp=0;
    for(int i=0;i<playernumber;i++)
    {
        if(playerlist[i].surrender==1)
        {
            temp++;
        }
    }
    if(temp+1==playernumber)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void renewthegame(player *playerlist,int playernumber)
{
    for(int i=0;i<playernumber;i++)
    {
        playerlist[i].setdefault();
    }
}
int decidebankerforsurrender(player *playerlist,int playernumber,int thisroundbanker)
{
    int temp=0,temp1=100000;
    for(int i=0;i<playernumber;i++)
    {
        if(i!=thisroundbanker)
        {
            if(playerlist[i].betcount<temp1)
            {
                temp1=playerlist[i].betcount;
                temp=i;
            }
        }
    }
    if(temp==0)
    {
        int test;
        while(1)
        {
            test=decidebankerfirsttime(playernumber);
            if(test!=thisroundbanker)
            {
                break;
            }
        }
        return test;
    }
    else
    {
        return temp;
    }
}
void printresult(player *playerlist,int playernumber)
{
    for(int i=0;i<playernumber;i++)
    {
        cout<<"Player "<<playerlist[i].playername<<"'s dollar remains "<<playerlist[i].dollar<<endl;
    }
}
int checkcard21(player player1)//have problem
{
    int point=0,ace=0;
    for(int i=0;i<player1.cardptr;i++)
    {
        if(((player1.cardyouget[i]-1)%13)==0)
        {
            ace++;
        }
        if(((player1.cardyouget[i]-1)%13)>=10&((player1.cardyouget[i]-1)%13)<=12)
        {
            point+=10;
        }
        else
        {
            point+=((player1.cardyouget[i]-1)%13+1);
        }
    }
    if(point<=11&&ace>0)
    {
        point+=10;
    }
    return point;
}
int testspecial(player &player1)
{
    if(player1.cardyouget[0]==5&&player1.cardyouget[1]==6&&player1.cardyouget[2]==7)
    {
        cout<<"Player "<<player1.playername<<" get 678 card,so if it win,it can gain 3 times reward!"<<endl;
        player::pool=player::pool-3*player1.betcount;
        player1.dollar=player1.dollar+4*player1.betcount;
        player1.betcount=player1.betcount*3;
        player1.speciallist=1;
        return 1;
    }
    if(player1.cardptr==5&&checkcard21(player1)<=21)
    {
        cout<<"Player "<<player1.playername<<" get 5 card,so if it win,it can gain 3 times reward!"<<endl;
        player::pool-=3*player1.betcount;
        player1.dollar+=4*player1.betcount;
        player1.betcount=player1.betcount*3;
        player1.speciallist=1;
        return 1;
    }
    return 0;
}
int ifalllose(player* playerlist,int playernumber,int banker)
{
    int alllose=1;
    for(int i=0;i<playernumber;i++)
    {
        if(i!=banker)
        {
            if(playerlist[i].boom==0)
            {
                alllose=0;
            }
        }
    }
    return alllose;
}
int decidebanker(player *playerlist,int playernumber)
{
    int temp,temp1=-100000,coin=0;
    for(int i=0;i<playernumber;i++)
    {
        if(playerlist[i].betcount>temp1)
        {
            temp1=playerlist[i].betcount;
            temp=i;
        }
        if(playerlist[i].betcount==temp1)
        {
            coin++;
        }
    }
    if(coin==playernumber-1)
    {
        int test,test1=1000000;
        for(int i=0;i<playernumber;i++)
        {
            if(playerlist[i].dollar<test1)
            {
                test1=playerlist[i].dollar;
                test=i;
            }
        }
        return test;
    }
    else
    {
        return temp;
    }
}
int removebankrupt(player *playerlist,int playernumber)
{
    int temp=playernumber,temp1=0;
    for(int i=0;i<playernumber;i++)
    {
        if(playerlist[i].bankrupt==1)
        {
            playernumber--;
        }
    }
    player *playerlist1= new player[playernumber];
    for(int i=0;i<temp;i++)
    {
        if(playerlist[i].bankrupt==0)
        {
            playerlist1[temp1]=playerlist[i];
            temp1++;
        }
    }
    for(int i=0;i<playernumber;i++)
    {
        playerlist[i]=playerlist1[i];
    }
    return playernumber;

}
void finalresult(player *playerlist,int playernumber)
{
    int count1=0;
    for(int i=0;i<playernumber;i++)
    {
        int temp,temp1=-100000;
        for(int j=0;j<playernumber;j++)
        {
            if(playerlist[j].dollar>temp1)
            {
                temp1=playerlist[j].dollar;
                temp=j;
            }
        }
        count1++;
        cout<<"Number "<<count1<<" is "<<playerlist[temp].playername<<endl;
        playerlist[temp].dollar=-1000000;
    }
}
int main()
{
    int times,playernumber;
    cout<<"This game is black jack. Have fun!"<<endl;
    cout<<"Everyone have 10000 initially."<<endl;
    cout<<"Antes is 1000,and a bet is 500."<<endl<<endl;
    cout<<"How many times do you want to play?(at most 3): ";
    while(1)
    {
        cin>>times;
        if(times<=3&&times>=1)
        {
            break;
        }
        else
        {
            cout<<"You should enter 1~3"<<endl;
        }
    }
    cout<<"How many players will join the game?(at most 4): ";
    while(1)
    {
        cin>>playernumber;
        if(playernumber>=2&&playernumber<=4)
        {
            break;
        }
        else
        {
            cout<<"You should enter 2~4";
        }
    }
    player *playerlist = new player[playernumber]; //creat player
    for(int i=0;i<playernumber;i++) //set name
    {
        string name;
        cout<<"please enter player "<<i+1<<"'s name: ";
        cin>>name;
        playerlist[i].playername=name;
    }
    cardmachine machine; //creat machine
    cout<<endl;
    int banker=decidebankerfirsttime(playernumber); //decide banker
    int mine = playernumber;
    while(times>-1) //game start
    {
        system("cls");
        if(times==0)
        {
            finalresult(playerlist,mine);
            break;
        }
        if(playernumber<=1)
        {
            finalresult(playerlist,mine);
            break;
        }
        cout<<"This round banker is:"<<playerlist[banker].playername<<endl;
        for(int i=0;i<playernumber;i++) //bet
            {
                if(i!=banker)
                {
                    cout<<"please enter how much money do you want to bet,"<<playerlist[i].playername<<": ";
                    while(1)
                    {
                        int temp;
                        cin>>temp;
                        if(playerlist[i].dollar<1000)
                        {
                            cout<<"You have less than 1000, You can just all in."<<endl;
                            playerlist[i].betcount=playerlist[i].dollar;
                            break;
                        }
                        else if((temp)<1000||temp%500!=0||temp>playerlist[i].dollar)
                        {
                            cout<<"Notice that Antes is 100 and a bet is 50.And you should notice your remaining dollars. please enter again: ";
                        }
                        else
                        {
                            playerlist[i].betcount=temp;
                            break;
                        }
                    }
                }
                player::pool=player::pool+playerlist[i].betcount;
                playerlist[i].dollar=playerlist[i].dollar-abs(playerlist[i].betcount);
            }
        for(int i=0;i<playernumber;i++) //give card from machine
            {
                if(i!=banker)
                {
                    machine.pop();
                    playerlist[i].cardyouget[playerlist[i].cardptr]=machine.number;
                    playerlist[i].cardptr++;
                    cout<<"Player "<<playerlist[i].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[i])<<"point.)"<<endl;
                    if(machine.color==1)
                    {
                        club *poker1=new club();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                    else if(machine.color==2)
                    {
                        diamond *poker1=new diamond();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                    else if(machine.color==3)
                    {
                        heart *poker1=new heart();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                    else
                    {
                        spade *poker1=new spade();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                }
            }
        machine.pop();//banker get card
        playerlist[banker].cardyouget[playerlist[banker].cardptr]=machine.number;
        playerlist[banker].cardptr++;
        cout<<"Banker "<<playerlist[banker].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[banker])<<"point.)"<<endl;
        if(machine.color==1)
        {
            club *poker1=new club();
            poker1->setnumber(machine.number);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        else if(machine.color==2)
        {
            diamond *poker1=new diamond();
            poker1->setnumber(machine.number);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        else if(machine.color==3)
        {
            heart *poker1=new heart();
            poker1->setnumber(machine.number);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        else
        {
            spade *poker1=new spade();
            poker1->setnumber(machine.number);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        while(1)//lock
        {
            cout<<"Please press 0 to get second card: ";
            int temp;
            cin>>temp;
            if(temp==0)
            {
                break;
            }
        }
        for(int i=0;i<playernumber;i++) //give second card from bander
            {
                if(i!=banker)
                {
                    machine.pop();
                    playerlist[i].cardyouget[playerlist[i].cardptr]=machine.number;
                    playerlist[i].cardptr++;
                    cout<<"Player "<<playerlist[i].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[i])<<"point.)"<<endl;
                    if(machine.color==1)
                    {
                        club *poker1=new club();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                    else if(machine.color==2)
                    {
                        diamond *poker1=new diamond();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                    else if(machine.color==3)
                    {
                        heart *poker1=new heart();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                    else
                    {
                        spade *poker1=new spade();
                        poker1->setnumber(machine.number);
                        connectforplayerandcard(playerlist[i].item,poker1->item);
                        playerlist[i].render();
                        cout<<endl;
                    }
                }
            }
        machine.pop();
        playerlist[banker].darkcardnumber=machine.number;
        playerlist[banker].darkcardcolor=machine.color;
        playerlist[banker].cardyouget[playerlist[banker].cardptr]=machine.number;
        playerlist[banker].cardptr++;
        cout<<"Banker "<<playerlist[banker].playername<<"'s card is/are:"<<endl;
        playerlist[banker].render();
        for(int i=0;i<playernumber;i++) //check surrender
        {
            if(i!=banker)
            {
                cout<<"Does player "<<playerlist[i].playername<<" want to surrender?"<<endl<<"If yes press 1,or press 0:";
            }
            while(1&&i!=banker)//lock
            {
                int temp;
                cin>>temp;
                if(temp<2&&temp>-1)
                {
                    playerlist[i].surrender=temp;
                    break;
                }
                else
                {
                    cout<<"You should press 1 or 0:";
                }
            }
        }
        for(int i=0;i<playernumber;i++) //count surrrender money
        {
            if(i!=banker)
            {
                if(playerlist[i].surrender==1)
                {
                    playerlist[i].dollar=playerlist[i].dollar+(playerlist[i].betcount/2);
                    player::pool=player::pool-(playerlist[i].betcount/2);
                    playerlist[i].betcount=(playerlist[i].betcount/2)-playerlist[i].betcount;
                }

            }
        }
        if(checkallsurrender(playerlist,playernumber)) //check all surrender
        {
            times--;
            playerlist[banker].dollar+=player::pool;
            printresult(playerlist,playernumber);
            banker=decidebankerforsurrender(playerlist,playernumber,banker);
            renewthegame(playerlist,playernumber);
            machine.rewash();
            cout<<endl<<endl;
            continue;
        }
        for(int i=0;i<playernumber;i++) //ask for doublebet
        {
            if(i!=banker&&playerlist[i].surrender==0)
            {
                if(playerlist[i].if11point()==1)
                {
                    cout<<"Does player "<<playerlist[i].playername<<" want to doublebet?"<<endl<<"If yes press 1,or press 0:";
                    int temp1;
                    while(1&&i!=banker)//lock
                    {
                        int temp;
                        cin>>temp;
                        if(temp<2&&temp>-1)
                        {
                            playerlist[i].doublebet=temp;
                            break;
                        }
                        else
                        {
                            cout<<"You should press 1 or 0:";
                        }
                    }
                }
            }
        }
        for(int i=0;i<playernumber;i++) //execute doublebet
        {
            if(i!=banker&&playerlist[i].surrender==0&&playerlist[i].doublebet==1)
            {
                player::pool=player::pool+abs(playerlist[i].betcount);
                playerlist[i].dollar=playerlist[i].dollar-playerlist[i].betcount;
                playerlist[i].betcount=2*playerlist[i].betcount;

            }
        }
        if((playerlist[banker].cardyouget[0]%13)==1) //ask for Insurance
        {
            for(int i=0;i<playernumber;i++)
            {
                if(i!=banker&&playerlist[i].surrender==0)
                {
                    cout<<"Dose player "<<playerlist[i].playername<<" want to buy Insurance?"<<endl<<"If yes press 1,or press 0:";
                    int temp1;
                    while(1&&i!=banker)//lock
                    {
                        int temp;
                        cin>>temp;
                        if(temp<2&&temp>-1)
                        {
                            playerlist[i].insurance=temp;
                            break;
                        }
                        else
                        {
                            cout<<"You should press 1 or 0:";
                        }
                    }
                }
            }
        }
        for(int i=0;i<playernumber;i++) //execute insurance
        {
            if(i!=banker&&playerlist[i].surrender==0)
            {
                playerlist[i].checkinsurance(checkcard21(playerlist[banker]),playerlist[banker]);
            }
        }
        for(int i=0;i<playernumber;i++) //ask for add card
        {
            if(i!=banker&&playerlist[i].surrender==0)
            {
                while(checkcard21(playerlist[i])<=21)
                {
                    if(testspecial(playerlist[i]))
                    {
                        break;
                    }
                    int wanttogetcard;
                    cout<<"If player "<<playerlist[i].playername<<" want to get card? Yes press 1,or press 0:";
                    while(1) //lock
                    {
                        cin>>wanttogetcard;
                        if(wanttogetcard>=0&&wanttogetcard<=1)
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Please press 1 or 0:";
                        }
                    }
                    if(wanttogetcard==1) //get card
                    {
                        machine.pop();
                        playerlist[i].cardyouget[playerlist[i].cardptr]=machine.number;
                        playerlist[i].cardptr++;
                        cout<<"Player "<<playerlist[i].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[i])<<"point.)"<<endl;
                        if(machine.color==1)
                        {
                            club *poker1=new club();
                            poker1->setnumber(machine.number);
                            connectforplayerandcard(playerlist[i].item,poker1->item);
                            playerlist[i].render();
                            cout<<endl;
                        }
                        else if(machine.color==2)
                        {
                            diamond *poker1=new diamond();
                            poker1->setnumber(machine.number);
                            connectforplayerandcard(playerlist[i].item,poker1->item);
                            playerlist[i].render();
                            cout<<endl;
                        }
                        else if(machine.color==3)
                        {
                            heart *poker1=new heart();
                            poker1->setnumber(machine.number);
                            connectforplayerandcard(playerlist[i].item,poker1->item);
                            playerlist[i].render();
                            cout<<endl;
                        }
                        else
                        {
                            spade *poker1=new spade();
                            poker1->setnumber(machine.number);
                            connectforplayerandcard(playerlist[i].item,poker1->item);
                            playerlist[i].render();
                            cout<<endl;
                        }
                    }
                    if(wanttogetcard==0)
                    {
                        break;
                    }
                    if(playerlist[i].doublebet==1)
                    {
                        break;
                    }
                    if(checkcard21(playerlist[i])>21) //boom
                    {
                          cout<<"Sorry "<<playerlist[i].playername<<". You have lost this round."<<endl;
                          playerlist[i].betcount=abs(playerlist[i].betcount)-2*abs(playerlist[i].betcount);
                          playerlist[i].boom=1;
                          break;
                    }
                }
            }
        }
        if(ifalllose(playerlist,playernumber,banker)==1) //all lose the game
        {
            times--;
            playerlist[banker].dollar+=player::pool;
            printresult(playerlist,playernumber);
            renewthegame(playerlist,playernumber);
            machine.rewash();
            cout<<endl<<endl;
            continue;
        }
        cout<<"Banker "<<playerlist[banker].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[banker])<<"point.)"<<endl;
        if(playerlist[banker].darkcardcolor==1)
        {
            club *poker1=new club();
            poker1->setnumber(playerlist[banker].darkcardnumber);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        else if(playerlist[banker].darkcardcolor==2)
        {
            diamond *poker1=new diamond();
            poker1->setnumber(playerlist[banker].darkcardnumber);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        else if(playerlist[banker].darkcardcolor==3)
        {
            heart *poker1=new heart();
            poker1->setnumber(playerlist[banker].darkcardnumber);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        else
        {
            spade *poker1=new spade();
            poker1->setnumber(playerlist[banker].darkcardnumber);
            connectforplayerandcard(playerlist[banker].item,poker1->item);
            playerlist[banker].render();
            cout<<endl;
        }
        while(checkcard21(playerlist[banker])<17) //banker's point less than 17
        {
            cout<<"Banker "<<playerlist[banker].playername<<" need to add card because bankes's point must higher than 17.press 0 to get card:";
            int addcardbanker;
            while(1) //lock
            {
                cin>>addcardbanker;
                if(addcardbanker==0)
                {
                    break;
                }
                else
                {
                    cout<<"You need to press 0 to get card:";
                }
            }
            machine.pop();
            playerlist[banker].cardyouget[playerlist[banker].cardptr]=machine.number;
            playerlist[banker].cardptr++;
            cout<<"Banker "<<playerlist[banker].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[banker])<<"point.)"<<endl;
            if(machine.color==1)
            {
                club *poker1=new club();
                poker1->setnumber(machine.number);
                connectforplayerandcard(playerlist[banker].item,poker1->item);
                playerlist[banker].render();
                cout<<endl;
            }
            else if(machine.color==2)
            {
                diamond *poker1=new diamond();
                poker1->setnumber(machine.number);
                connectforplayerandcard(playerlist[banker].item,poker1->item);
                playerlist[banker].render();
                cout<<endl;
            }
            else if(machine.color==3)
            {
                heart *poker1=new heart();
                poker1->setnumber(machine.number);
                connectforplayerandcard(playerlist[banker].item,poker1->item);
                playerlist[banker].render();
                cout<<endl;
            }
            else
            {
                spade *poker1=new spade();
                poker1->setnumber(machine.number);
                connectforplayerandcard(playerlist[banker].item,poker1->item);
                playerlist[banker].render();
                cout<<endl;
            }
        }
        while(checkcard21(playerlist[banker])<=21)
        {
            if(testspecial(playerlist[banker]))
            {
                    break;
            }
            int wanttogetcard2;
            cout<<"If player "<<playerlist[banker].playername<<" want to get card? Yes press 1,or press 0:";
            while(1) //lock
            {
                cin>>wanttogetcard2;
                if(wanttogetcard2>=0&&wanttogetcard2<=1)
                {
                    break;
                }
                else
                {
                    cout<<"Please press 1 or 0:";
                }
            }
            if(wanttogetcard2) //get card
            {
                machine.pop();
                playerlist[banker].cardyouget[playerlist[banker].cardptr]=machine.number;
                playerlist[banker].cardptr++;
                cout<<"Banker "<<playerlist[banker].playername<<"'s card is/are:"<<"("<<checkcard21(playerlist[banker])<<"point.)"<<endl;
                if(machine.color==1)
                {
                    club *poker1=new club();
                    poker1->setnumber(machine.number);
                    connectforplayerandcard(playerlist[banker].item,poker1->item);
                    playerlist[banker].render();
                    cout<<endl;
                }
                else if(machine.color==2)
                {
                    diamond *poker1=new diamond();
                    poker1->setnumber(machine.number);
                    connectforplayerandcard(playerlist[banker].item,poker1->item);
                    playerlist[banker].render();
                    cout<<endl;
                }
                else if(machine.color==3)
                {
                    heart *poker1=new heart();
                    poker1->setnumber(machine.number);
                    connectforplayerandcard(playerlist[banker].item,poker1->item);
                    playerlist[banker].render();
                    cout<<endl;
                }
                else
                {
                    spade *poker1=new spade();
                    poker1->setnumber(machine.number);
                    connectforplayerandcard(playerlist[banker].item,poker1->item);
                    playerlist[banker].render();
                    cout<<endl;
                }
            }
            else if(wanttogetcard2==0)
            {
                break;
            }
        }
        if(checkcard21(playerlist[banker])>21) //banker boom
        {
            cout<<"Sorry, banker "<<playerlist[banker].playername<<" has lost,someones can get money back!"<<endl;
            for(int i=0;i<playernumber;i++)
            {
                if(i!=banker&&playerlist[i].surrender==0)
                {
                    if(playerlist[i].boom==1)
                    {
                        playerlist[i].dollar+=abs(playerlist[i].betcount);
                        player::pool=player::pool-abs(playerlist[i].betcount);
                        playerlist[i].betcount=0;
                    }
                    else if(playerlist[i].boom==0&&playerlist[i].speciallist==0)
                    {
                        playerlist[i].dollar=playerlist[i].dollar+(2*abs(playerlist[i].betcount));
                        player::pool=player::pool-(abs(playerlist[i].betcount)*2);
                        playerlist[i].betcount=abs(playerlist[i].betcount);
                    }
                }
            }
            times--;
            playerlist[banker].dollar+=player::pool; //total
            printresult(playerlist,playernumber);
            for(int i=0;i<playernumber;i++) //check bankrupt
            {
                if(playerlist[i].dollar<=0)
                {
                    playerlist[i].bankrupt=1;
                }
            }
            playernumber=removebankrupt(playerlist,playernumber);
            banker=decidebanker(playerlist,playernumber);
            renewthegame(playerlist,playernumber);
            machine.rewash();
            cout<<endl<<endl;
            continue;
        }
        if(checkcard21(playerlist[banker])<=21&&playerlist[banker].speciallist==1) //banker is specail
        {
            for(int i=0;i<playernumber;i++)
            {
                if(i!=banker&&playerlist[i].surrender==0)
                {
                    if(playerlist[i].speciallist==1)
                    {
                        if(checkcard21(playerlist[banker])>=checkcard21(playerlist[i]))
                        {
                            playerlist[i].betcount=abs(playerlist[i].betcount)-4*abs(playerlist[i].betcount);
                            playerlist[i].dollar=playerlist[i].dollar-4*(abs(playerlist[i].betcount));
                            player::pool=player::pool+abs(playerlist[i].betcount)*4;

                        }
                    }
                    else if(playerlist[i].speciallist==0)
                    {
                        playerlist[i].betcount=playerlist[i].betcount-(2*playerlist[i].betcount);
                    }
                }
            }
        }
        if(checkcard21(playerlist[banker])<=21&&playerlist[banker].speciallist==0) //banker is normal
        {
            for(int i=0;i<playernumber;i++)
            {
                if(i!=banker&&playerlist[i].surrender==0&&playerlist[i].speciallist==0&&playerlist[i].boom==0)
                {
                    if(checkcard21(playerlist[banker])>=checkcard21(playerlist[i]))
                    {
                        playerlist[i].betcount=playerlist[i].betcount-2*playerlist[i].betcount;
                    }
                    if(checkcard21(playerlist[banker])<checkcard21(playerlist[i]))
                    {
                        player::pool=player::pool-2*abs(playerlist[i].betcount);
                        playerlist[i].dollar=playerlist[i].dollar+abs(playerlist[i].betcount)*2;
                    }
                }
            }
        }
        for(int i=0;i<playernumber;i++) //check bankrupt
        {
            if(playerlist[i].dollar<=0)
            {
                playerlist[i].bankrupt=1;
            }
        }
        times--;
        playerlist[banker].dollar=player::pool+playerlist[banker].dollar;
        printresult(playerlist,playernumber);
        playernumber=removebankrupt(playerlist,playernumber);
        banker=decidebanker(playerlist,playernumber);
        renewthegame(playerlist,playernumber);
        machine.rewash();
        cout<<endl<<endl;
    }
}
