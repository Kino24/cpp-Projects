#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <conio.h>
#include "registerClient.h"
#include "clientList.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int MAIN_MENU();
int subMenu();

int main()
{
    registerClient clientClass;
    showClient find_Client;
    char address[100], clientSex;
    std::string firstName, lastName;
    long long int phoneNumber;
    int choice=0,choice2=0, clientAge;
    while(choice!=3)
    {
        choice=MAIN_MENU();
        if(choice==1)
        {
            std::cout<<"Enter first name, last name and age"<<std::endl;
            std::cin>>firstName>>lastName>>clientAge;
            transform(firstName.begin(),firstName.end(),firstName.begin(),::toupper);
            transform(lastName.begin(),lastName.end(),lastName.begin(),::toupper);
            std::cout<<"Enter your phone number: +63 ";
            std::cin>>phoneNumber;
            do
            {
                std::cout<<"\nEnter 'M' for male or 'F' for female:"<<std::endl;
                std::cin>>clientSex;
                clientSex=toupper(clientSex);
                if(clientSex!='M'&&clientSex!='F')
                    std::cout<<"Invalid Input!"<<std::endl;
                
            } while (clientSex!='M'&&clientSex!='F');
            
            clientClass.clientDetails(firstName,lastName,phoneNumber,clientAge,clientSex);
        }
        else if(choice==2)
        {
            choice2=subMenu();
            system("cls");
            if(choice2==1)
                find_Client.showClientList(clientClass);
            else if(choice2==2)
            {
                std::cout<<"Enter first name, last name"<<std::endl;
                std::cin>>firstName>>lastName;
                transform(firstName.begin(),firstName.end(),firstName.begin(),::toupper);
                transform(lastName.begin(),lastName.end(),lastName.begin(),::toupper);
                find_Client.findClient(clientClass, firstName, lastName);
            }
        }
        system("cls");
    }

    return 0;
}

int MAIN_MENU()
{
    int key=0,menu=1;
    do
    {
        key=0;
        if(menu==0||menu==4)
            {
                if(menu==0)
                    menu=3;
                else if(menu==4)
                    menu=1;
            }
        if(menu==1)
            {
                system("cls");
                std::cout<<"Navigate with 'UP' and 'DOWN' arrow keys. Press 'ENTER' to select choice."<<std::endl;
                SetConsoleTextAttribute(hConsole,112);
                std::cout<<"[1]Register Client"<<std::endl;
                SetConsoleTextAttribute(hConsole,7);
                std::cout<<"[2]Client List"<<std::endl
                    <<"[3]Quit Program"<<std::endl;
            }
        else if(menu==2)
            {
                system("cls");
                std::cout<<"Navigate with 'UP' and 'DOWN' arrow keys. Press 'ENTER' to select choice."<<std::endl;
                std::cout<<"[1]Register Client"<<std::endl;
                SetConsoleTextAttribute(hConsole,112);
                std::cout<<"[2]Client List"<<std::endl;
                SetConsoleTextAttribute(hConsole,7);
                std::cout<<"[3]Quit Program"<<std::endl;
            }
        else if(menu==3)
            {
                system("cls");
                std::cout<<"Navigate with 'UP' and 'DOWN' arrow keys. Press 'ENTER' to select choice."<<std::endl;
                std::cout<<"[1]Register Client"<<std::endl;
                std::cout<<"[2]Client List"<<std::endl;
                SetConsoleTextAttribute(hConsole,112);
                std::cout<<"[3]Quit Program"<<std::endl;
                SetConsoleTextAttribute(hConsole,7);
            }
        switch(key=getch())
            {
                case KEY_DOWN:
                    ++menu;
                    break;
                case KEY_UP:
                    --menu;
                    break;
                default:
                    break;
            }
        if(key==13)
            break;
    } while (1);

    return(menu);   
}

int subMenu()
{
    int key=0,menu=1;
    do
    {
        key=0;
        if(menu==0||menu==4)
            {
                if(menu==0)
                    menu=3;
                else if(menu==4)
                    menu=1;
            }
        if(menu==1)
            {
                system("cls");
                std::cout<<"Navigate with 'UP' and 'DOWN' arrow keys. Press 'ENTER' to select choice."<<std::endl;
                SetConsoleTextAttribute(hConsole,112);
                std::cout<<"[1]Show Registrant List"<<std::endl;
                SetConsoleTextAttribute(hConsole,7);
                std::cout<<"[2]Find Registrant"<<std::endl
                        <<"[3]Back"<<std::endl;
            }
        else if(menu==2)
            {
                system("cls");
                std::cout<<"Navigate with 'UP' and 'DOWN' arrow keys. Press 'ENTER' to select choice."<<std::endl;
                std::cout<<"[1]Show Registrant List"<<std::endl;
                SetConsoleTextAttribute(hConsole,112);
                std::cout<<"[2]Find Registrant"<<std::endl;
                SetConsoleTextAttribute(hConsole,7);
                std::cout<<"[3]Back"<<std::endl;
            }
        else if(menu==3)
            {
                system("cls");
                std::cout<<"Navigate with 'UP' and 'DOWN' arrow keys. Press 'ENTER' to select choice."<<std::endl;
                std::cout<<"[1]Show Registrant List"<<std::endl;
                std::cout<<"[2]Find Registrant"<<std::endl;
                SetConsoleTextAttribute(hConsole,112);
                std::cout<<"[3]Back"<<std::endl;
                SetConsoleTextAttribute(hConsole,7);
            }
        switch(key=getch())
            {
                case KEY_DOWN:
                    ++menu;
                    break;
                case KEY_UP:
                    --menu;
                    break;
                default:
                    break;
            }
        if(key==13)
            break;
    } while (1);

    return(menu);   
}