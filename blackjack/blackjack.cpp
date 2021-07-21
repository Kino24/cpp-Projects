#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int player=0,blackJackDealer=0,initialBotValue=0,cards=1;
    string choice;
    cout<<" type 'hit' to draw another card, and type 'stay' to pass"<<endl;
    for(int i=0; i<2; i++)
    {
        player += rand()%11+1;
        blackJackDealer += rand()%11+1;
        if(i==0)
            initialBotValue=blackJackDealer;
    }
    cout<<"Player: "<<player<<endl
        <<"Dealer Initial Value: "<<initialBotValue<<endl;
    while(choice!="stay")
    {
        cout<<"Enter Choice: ";
        cin>>choice; cout<<endl;
        if(choice=="hit")
        {
            cards++;
            player +=rand()%11+1;
            if(rand()%2+1==2||blackJackDealer<17)
                blackJackDealer+=rand()%11+1;
            if(player>=21)
                break;
            cout<<"Player: "<<player<<endl
                <<"Dealer Initial Value: "<<initialBotValue<<endl;
        }
        if(cards==5)
            break;
    }
    if(cards==1)
    {
        if(rand()%2+1==2||blackJackDealer<15)
                blackJackDealer+=rand()%10+1;
    }
    cout<<"Player: "<<player<<endl
        <<"Dealer: "<<blackJackDealer<<endl;
    if(player>21&&blackJackDealer<=21)
        cout<<"You lose! The Dealer wins!"<<endl;
    else if(player<=21&&blackJackDealer<=21&&player>blackJackDealer)
        cout<<"You win!"<<endl;
    else if(player<=21&&blackJackDealer>21)
        cout<<"You win!"<<endl;
    else if(player<=21&&blackJackDealer<=21&&player<blackJackDealer)
        cout<<"You lose! The Dealer wins!"<<endl;
    else if(player>21&&blackJackDealer>21)
        cout<<"No one wins!"<<endl;
    else if(player==blackJackDealer)
        cout<<"It is a tie!"<<endl;
    
    system("pause");
    return 0;
}