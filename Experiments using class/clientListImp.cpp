#include "clientList.h"
#include "registerClient.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <limits>
using namespace std;
void showClient::showClientList(registerClient& show)
{
    ifstream clientInput("dataFile.dat");
    ifstream clientAddress("ADDRESS_DATA.dat");
    cout<<"If name is color ";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"RED ";
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"then the person is suspected for COVID-19"<<endl<<endl;
    while(clientInput.good()&&clientAddress.good())
    {
        clientInput>>show.clientFirstName>>show.clientLastName>>show.clientNumber>>show.clientScore>>week_day>>month>>day>>time>>year;
        getline(clientAddress,address);
        if(clientInput.good()&&clientAddress.good())
        {
            if(show.clientScore>3)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Name: "<<show.clientFirstName<<" "<<show.clientLastName<<endl
                <<"Number: "<<show.clientNumber<<endl
                <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                <<"Time Registered: "<<time<<endl
                <<"Address: "<<address<<endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                cout<<"Name: "<<show.clientFirstName<<" "<<show.clientLastName<<endl
                <<"Number: "<<show.clientNumber<<endl
                <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                <<"Time Registered: "<<time<<endl
                <<"Address: "<<address<<endl;
            }
        }
            
    }
    clientInput.close();
    system("pause");
    system("cls");
}

void showClient::findClient(registerClient& find, string first_name, string last_name)
{
    ifstream clientInput("dataFile.dat");
    ifstream clientAddress("ADDRESS_DATA.dat");
    while(clientInput.good()&&clientAddress.good())
    {
        clientInput>>find.clientFirstName>>find.clientLastName>>find.clientNumber>>find.clientScore>>week_day>>month>>day>>time>>year;
        getline(clientAddress, address);
        if(find.clientFirstName==first_name&&find.clientLastName==last_name)
        {
            system("cls");
            if(find.clientScore>3)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Name: "<<find.clientFirstName<<" "<<find.clientLastName<<endl
                    <<"Number: "<<find.clientNumber<<endl
                    <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                    <<"Time Registered: "<<time<<endl
                    <<"Address: "<<address<<endl<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    cout<<"Name: "<<find.clientFirstName<<" "<<find.clientLastName<<endl
                    <<"Number: "<<find.clientNumber<<endl
                    <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                    <<"Time Registered: "<<time<<endl
                    <<"Address: "<<address<<endl<<endl;
                }
        }
        
    }
    if(find.clientFirstName!=first_name&&find.clientLastName!=last_name)
    {
        cout<<"Person not found"<<endl;
    }
    system("pause");
    system("cls");
}