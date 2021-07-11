#ifndef clientList_H
#define clientList_H
#include <iostream>

class showClient
{
    public:
        void showClientList();
        void findClient(std::string firstName, std::string lastName);
    private:
        std::string first_name, last_name, week_day,month, time, year, phone_number,day;
};

#endif