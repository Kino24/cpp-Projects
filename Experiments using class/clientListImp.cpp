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
        clientInput>>show.clientFirstName>>show.clientLastName>>show.client_number>>show.clientScore>>show.clientAge>>show.clientSex>>week_day>>month>>day>>time>>year;
        getline(clientAddress,address);
        if(clientInput.good()&&clientAddress.good())
        {
            if(show.clientScore>5)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"Name: "<<show.clientFirstName<<" "<<show.clientLastName<<endl
                <<"Number: "<<show.client_number<<endl
                <<"Sex: "<<show.clientSex<<endl
                <<"Age: "<<show.clientAge<<endl
                <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                <<"Time Registered: "<<time<<endl
                <<"Address: "<<address<<endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
            else
            {
                cout<<"Name: "<<show.clientFirstName<<" "<<show.clientLastName<<endl
                <<"Number: "<<show.client_number<<endl
                <<"Sex: "<<show.clientSex<<endl
                <<"Age: "<<show.clientAge<<endl
                <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                <<"Time Registered: "<<time<<endl
                <<"Address: "<<address<<endl;
            }
            cout<<endl;
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
        clientInput>>find.clientFirstName>>find.clientLastName>>find.client_number>>find.clientScore>>find.clientAge>>find.clientSex>>week_day>>month>>day>>time>>year;
        getline(clientAddress, address);
        if(find.clientFirstName==first_name&&find.clientLastName==last_name)
        {
            system("cls");
            if(find.clientScore>5)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"Name: "<<find.clientFirstName<<" "<<find.clientLastName<<endl
                    <<"Number: "<<find.client_number<<endl
                    <<"Sex: "<<find.clientSex<<endl
                    <<"Age: "<<find.clientAge<<endl
                    <<"Date Registered: "<<week_day<<" "<<month<<" "<<day<<" "<<year<<endl
                    <<"Time Registered: "<<time<<endl
                    <<"Address: "<<address<<endl<<endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else
                {
                    cout<<"Name: "<<find.clientFirstName<<" "<<find.clientLastName<<endl
                    <<"Number: "<<find.client_number<<endl
                    <<"Sex: "<<find.clientSex<<endl
                    <<"Age: "<<find.clientAge<<endl
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