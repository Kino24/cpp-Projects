#include "registerClient.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

void registerClient::clientDetails(string firstName, string lastName, long long int number)
{
    clientFirstName=firstName;
    clientLastName=lastName;
    clientNumber=number;
    registerClient::writeClientInformation();
}

void registerClient::writeClientInformation()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    ofstream outFile("dataFile.txt",ios::app);
    outFile<<clientFirstName<<" "<<clientLastName<<" "<<"+63"<<clientNumber<<" "<<dt;
    outFile.close();
}
