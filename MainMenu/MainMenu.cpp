#include"pch.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"MainMenu.h"
using namespace std;


void setPosition(short a, short b)
{
    COORD coordinates;
    coordinates.X = a;
    coordinates.Y = b;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}


void login()
{
    int count = 0;
    string user, pass, u, p;
    system("cls");
    cout << "         -- ";
    cout << "Login";
    cout << " --          " << endl;
    cout << " ---------------------------- " << endl;
    cout << "|          ";
    cout << "Username: "; 
    cout << "        | " << endl;
    cout << "|         ->                 |" << endl;
    cout << "|          ";
    cout << "Password: "; 
    cout << "        | " << endl;
    cout << "|         ->                 |" << endl;
    cout << " ---------------------------- " << endl;
    
    setPosition(12, 3);
    cin >> user;
    setPosition(12, 5);
    cin >> pass;

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "Hello " << user << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
        cin.get();
        cin.get();
        system("cls");

        mainMenu();
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
    }
}

void registr()
{
    system("cls");
    string reguser, regpass, ru, rp;
    cout << "        -- ";
    cout << "REGISTER ";
    cout << "--        " << endl;
    cout << " ---------------------------- " << endl;
    cout << "|          ";
    cout << "Username: ";
    cout << "        | " << endl;
    cout << "|         ->                 |" << endl;
    cout << "|          ";
    cout << "Password: ";
    cout << "        | " << endl;
    cout << "|         ->                 |" << endl;
    cout << " ---------------------------- " << endl;

    setPosition(12, 3);
    cin >> reguser;

    setPosition(12, 5);
    cin >> regpass;

    fstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    cout << "Redirecting you to the Login Menu";
    Sleep(1000);
    system("cls");

    login();

}

void forgot()
{
    system("cls");
    cout << "------------------------" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    setPosition(23, 1);
    cout << "|" << endl;
    setPosition(23, 2);
    cout << "|" << endl;
    setPosition(23, 3);
    cout << "|" << endl;
    setPosition(23, 4);
    cout << "|" << endl;
    setPosition(23, 5);
    cout << "|" << endl;
    setPosition(23, 6);
    cout << "|" << endl;
    setPosition(23, 7);
    cout << "|" << endl;
    setPosition(23, 8);
    cout << "|" << endl;
    cout << "------------------------" << endl;
    setPosition(3, 3);
    cout << " Search by username" << endl;
    setPosition(3, 4);
    cout << " Search by password" << endl;
    setPosition(3, 5);
    cout << " Main menu" << endl;

    int y = 3, choice = 0;

    while (true) {
        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && y != 13) {
            setPosition(1, y);
            cout << "  ";
            y++;
            setPosition(1, y);
            cout << "-> ";
            choice++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && y != 9) {
            setPosition(1, y);
            cout << "  ";
            y--;
            setPosition(1, y);
            cout << "-> ";
            choice--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN)) {
            switch (choice) {
            case 0:
            {
                system("cls");
                int count = 0;
                string searchuser, su, sp;
                cout << "\nEnter your remembered username :";
                cin >> searchuser;

                ifstream searchu("database.txt");
                while (searchu >> su >> sp)
                {
                    if (su == searchuser)
                    {
                        count = 1;
                    }
                }
                searchu.close();
                if (count == 1)
                {
                    cout << "\n\nHurray, account found\n";
                    cout << "\nYour password is " << sp;
                    cin.get();
                    cin.get();
                    system("cls");

                    mainMenu();
                }
                else
                {
                    cout << "\nSorry, Your userID is not found in our database\n";
                    cout << "\nPlease kindly contact your system administrator for more details \n";
                    cin.get();
                    cin.get();
                }
                break;
            }
            case 1:
            {
                system("cls");
                int count = 0;
                string searchpass, su2, sp2;
                cout << "\nEnter the remembered password :";
                cin >> searchpass;

                ifstream searchp("database.txt");
                while (searchp >> su2 >> sp2)
                {
                    if (sp2 == searchpass)
                    {
                        count = 1;
                    }
                }
                searchp.close();
                if (count == 1)
                {
                    cout << "\nYour password is found in the database \n";
                    cout << "\nYour Id is : " << su2;
                    cin.get();
                    cin.get();
                    system("cls");
                    mainMenu();
                }
                else
                {
                    cout << "Sorry, We cannot found your password in our database \n";
                    cout << "\nkindly contact your administrator for more information\n";
                    cin.get();
                    cin.get();
                }

                break;
            }
                
            case 2:
                system("cls");
                mainMenu();
                
            default:
                system("cls");
                cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
                forgot();
        }

        }
    }
}

    void mainMenu()
    {
        cout << "----------------------" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        setPosition(21, 1);
        cout << "|" << endl;
        setPosition(21, 2);
        cout << "|" << endl;
        setPosition(21, 3);
        cout << "|" << endl;
        setPosition(21, 4);
        cout << "|" << endl;
        setPosition(21, 5);
        cout << "|" << endl;
        setPosition(21, 6);
        cout << "|" << endl;
        setPosition(21, 7);
        cout << "|" << endl;
        setPosition(21, 8);
        cout << "|" << endl;
        cout << "----------------------" << endl;
        setPosition(5, 3);
        cout << "Login" << endl;
        setPosition(5, 4);
        cout << "Register";
        setPosition(5, 5);
        cout << "ForgotPassword";

        int y = 3, choice = 0;

        while (true) {
            system("pause>nul");

            if (GetAsyncKeyState(VK_DOWN) && y != 13) {
                setPosition(1, y);
                cout << "  ";
                y++;
                setPosition(1, y);
                cout << "-> ";
                choice++;
                continue;
            }

            if (GetAsyncKeyState(VK_UP) && y != 9) {
                setPosition(1, y);
                cout << "  ";
                y--;
                setPosition(1, y);
                cout << "-> ";
                choice--;
                continue;
            }

            if (GetAsyncKeyState(VK_RETURN)) {
                switch (choice) {
                case 0:
                    system("cls");
                    login();
                    break;
                case 1:
                    system("cls");
                    registr();
                    break;
                case 2:
                    system("cls");
                    forgot();
                    break;
                }

            }
        }
    }

