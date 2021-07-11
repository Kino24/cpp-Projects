#include "clientList.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
void showClient::showClientList()
{
    ifstream clientInput("dataFile.txt");
    while(clientInput.good())
    {
        clientInput>>first_name>>last_name>>phone_number>>week_day>>month>>day>>time>>year;
        if(clientInput.good())
            cout<<"Name: "<<first_name<<" "<<last_name<<endl
                <<"Number: "<<phone_number<<endl
                <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                <<"Time Registered: "<<time<<endl<<endl;
    }
    clientInput.close();
    system("pause");
    system("cls");
}

void showClient::findClient(string firstName, string lastName)
{
    ifstream clientInput("dataFile.txt");
    while(clientInput.good())
    {
        clientInput>>first_name>>last_name>>phone_number>>week_day>>month>>day>>time>>year;
        if(firstName==first_name&&lastName==last_name)
        {
            system("cls");
            cout<<"Name: "<<first_name<<" "<<last_name<<endl
                <<"Number: "<<phone_number<<endl
                <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                <<"Time Registered: "<<time<<endl<<endl;
            break;
        }
        else
        {
            system("cls");
            cout<<"Person not found"<<endl;
            system("pause");
        }
    }
}