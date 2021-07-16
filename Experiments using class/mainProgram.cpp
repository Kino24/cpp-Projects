#include <iostream>
#include <Windows.h>
#include "registerClient.h"
#include "clientList.h"

int main()
{
    registerClient clientClass;
    showClient find_Client;
    std::string firstName, lastName;
    std::string phoneNumber;
    std::string phone_number;
    int choice=0,choice2=0;
    while(choice!=99)
    {
        std::cout<<"[1]Register, [2]Find Person/Show Client List, [99]Exit"<<std::endl;
        std::cin>>choice;
        system("cls");
        if(choice==1)
        {
            std::cout<<"Enter first name, last name, and phone number(please use 09 format):"<<std::endl;
            std::cin>>firstName>>lastName>>phoneNumber;
            clientClass.clientDetails(firstName,lastName,phoneNumber);
        }
        else if(choice==2)
        {
            std::cout<<"[1]Show Registrants List, [2]Find Registrant"<<std::endl;
            std::cin>>choice2;
            system("cls");
            if(choice2==1)
                find_Client.showClientList(clientClass);
            else if(choice2==2)
            {
                std::cout<<"Enter first name, last name"<<std::endl;
                std::cin>>firstName>>lastName;
                find_Client.findClient(clientClass, firstName, lastName);
            }
            else
                std::cout<<"Invalid Input!"<<std::endl; 
        }
        system("cls");
    }

    return 0;
}
    