#include <iostream>
#include <Windows.h>
#include <string>
#include "registerClient.h"
#include "clientList.h"

int main()
{
    registerClient clientClass;
    showClient find_Client;
    char address[100], clientSex;
    std::string firstName, lastName;
    long long int phoneNumber;
    int choice=0,choice2=0, clientAge;
    while(choice!=99)
    {
        std::cout<<"[1]Register, [2]Find Person/Show Client List, [99]Exit"<<std::endl;
        std::cin>>choice;
        system("cls");
        if(choice==1)
        {
            std::cout<<"Enter first name, last name and age"<<std::endl;
            std::cin>>firstName>>lastName>>clientAge;
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
    