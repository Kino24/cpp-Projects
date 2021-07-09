#ifndef registerClient_H
#define registerClient_H
#include <iostream>
class registerClient
{
    private:
        std::string clientFirstName, clientLastName;
        std::string clientNumber, temp;
        void writeClientInformation();
    public:
        void clientDetails(std::string firstName, std::string lastName, std::string number);
};

#endif