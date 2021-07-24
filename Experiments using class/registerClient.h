#ifndef registerClient_H
#define registerClient_H
#include <iostream>
class registerClient
{
    private:
        void writeClientInformation();
        void contactTracingQuestion();
        void writeClientAddress();
    public:
        std::string clientFirstName, clientLastName,question,answer,client_number;
        long long int clientNumber;
        char clientAddress[100];
        int clientScore,clientAge;
        char clientSex;
        void clientDetails(std::string firstName, std::string lastName, long long int number, int age, char sex);
        friend class clientList;
};

#endif