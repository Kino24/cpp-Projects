#ifndef clientList_H
#define clientList_H
#include <iostream>
#include <Windows.h>
#include "registerClient.h"
class showClient
{
    public:
        void showClientList(registerClient& show);
        void findClient(registerClient& findClient, std::string first_name, std::string last_name);
    private:
        std::string week_day,month, time, year, day;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        friend class registerClient;
};

#endif