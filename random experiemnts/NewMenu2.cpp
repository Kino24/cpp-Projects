#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    
    int key=0, menu=1;
    do
    {
        key=0;
        if(menu==0||menu==4)
            {
                if(menu==0)
                    menu=3;
                else if(menu==4)
                    menu=1;
            }
        if(menu==1)
            {
                system("cls");
                SetConsoleTextAttribute(hConsole,112);
                cout<<"[1]Register Client"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                cout<<"[2]Client List"<<endl
                    <<"[3]Quit Program"<<endl;
            }
        else if(menu==2)
            {
                system("cls");
                cout<<"[1]Register Client"<<endl;
                SetConsoleTextAttribute(hConsole,112);
                cout<<"[2]Client List"<<endl;
                SetConsoleTextAttribute(hConsole,7);
                cout<<"[3]Quit Program"<<endl;
            }
        else if(menu==3)
            {
                system("cls");
                cout<<"[1]Register Client"<<endl;
                cout<<"[2]Client List"<<endl;
                SetConsoleTextAttribute(hConsole,112);
                cout<<"[3]Quit Program"<<endl;
                SetConsoleTextAttribute(hConsole,7);
            }
        switch(key=getch())
            {
                case KEY_DOWN:
                    ++menu;
                    break;
                case KEY_UP:
                    --menu;
                    break;
                default:
                    break;
            }
        if(key==13)
            break;
    } while (1);

    if(menu==1)
        cout<<"1";
    else if(menu==2)
        cout<<"2";
    else
        cout<<"3";
    return 0;
    
}