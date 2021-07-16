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
        std::string clientFirstName, clientLastName;
        std::string clientNumber,question,answer;
        char clientAddress[100];
        int clientScore;
        void clientDetails(std::string firstName, std::string lastName, std::string number);
        friend class clientList;
};

#endif