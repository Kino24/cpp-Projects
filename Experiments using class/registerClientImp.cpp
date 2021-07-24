#include "registerClient.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

void registerClient::clientDetails(string firstName, string lastName, long long int number,int client_age, char client_sex)
{
    clientFirstName=firstName;
    clientLastName=lastName;
    clientNumber=number;
    clientAge=client_age;
    clientSex=client_sex;
    registerClient::writeClientInformation();
}

void registerClient::writeClientInformation()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    ofstream outFile("dataFile.dat",ios::app);
    registerClient::writeClientAddress();
    registerClient::contactTracingQuestion();
    outFile<<clientFirstName<<" "<<clientLastName<<" "<<"+63"<<clientNumber<<" "<<clientScore<<" "<<clientAge<<" "<<clientSex<<" "<<dt;
    outFile.close();
}

void registerClient::contactTracingQuestion()
{
    bool isCorrect;
    system("cls");
    clientScore=0;
    cout<<"Answer 'YES' or 'NO'"<<endl;
    ifstream inFile("CONTACT_TRACING_QUESTIONS.txt");
    ifstream symptomFile("Symptoms.txt");
    while(inFile.good())
    {
        getline(inFile, question);
        if(inFile.good())
        {
            cout<<question<<endl<<"Answer:";
            cin>>answer; cout<<endl;
            transform(answer.begin(),answer.end(),answer.begin(),::toupper);
            if(answer=="YES")
                clientScore++;
            else if(answer!="YES")
                {
                    isCorrect=false;
                    while(isCorrect!=true)
                    {
                        if(answer=="NO")
                            break;
                        cout<<"Invalid Input! Please input yes or no."<<endl<<question<<endl<<"Answer:";
                        cin>>answer; cout<<endl;
                        transform(answer.begin(),answer.end(),answer.begin(),::toupper);
                        if(answer=="YES")
                            {
                                clientScore++;
                                isCorrect=true;
                            }
                        else if(answer=="NO")
                            isCorrect=true;
                    }
                }
        }
    }
    cout<<"Do you currently have any of the following conditions during this time?"<<endl;
    while(symptomFile.good())
        {
            getline(symptomFile, question);
            if(symptomFile.good())
            {
                cout<<question<<endl<<"Answer:";
                cin>>answer; cout<<endl;
                transform(answer.begin(),answer.end(),answer.begin(),::toupper);
                if(answer=="YES")
                    clientScore++;
                else if(answer!="YES")
                {
                    isCorrect=false;
                    while(isCorrect!=true)
                    {
                        if(answer=="NO")
                            break;
                        cout<<"Invalid Input! Please input yes or no.";
                        cout<<question<<endl<<"Answer:";
                        cin>>answer; cout<<endl;
                        transform(answer.begin(),answer.end(),answer.begin(),::toupper);
                        if(answer=="YES")
                            {
                                clientScore++;
                                isCorrect=true;
                            }
                        else if(answer=="NO")
                            isCorrect=true;
                    }
                }
           }
        }
    inFile.close();
    symptomFile.close();
    system("cls");
}

void registerClient::writeClientAddress()
{
    ofstream addressData("ADDRESS_DATA.dat",ios::app);
    cin.ignore();
    cout<<"Enter Address: ";
    cin.getline(clientAddress, 99); cout<<endl;
    addressData<<clientAddress<<endl;
}