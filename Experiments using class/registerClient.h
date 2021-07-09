#ifndef registerClient_H
#define registerClient_H
#include <iostream>
class registerClient
{
    private:
        std::string clientFirstName, clientLastName;
        long long int clientNumber, temp;
        void writeClientInformation();
    public:
        void clientDetails(std::string firstName, std::string lastName, long long int number);
};

#endif