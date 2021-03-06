#include"pch.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<Windows.h>
#include<algorithm>
#include"MainMenu.h"
using namespace std;

string currentUser, currentPassword;
string reguser, hashedRegpass, ru, rp;
string user, hashedPass, u, p;

bool check = false;

void setPosition(short a, short b)
{
    COORD coordinates;
    coordinates.X = a;
    coordinates.Y = b;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}

string hashPassword(string pass) {
    string hashed(pass);

    transform(hashed.begin(), hashed.end(), hashed.begin(), [](char& i) {
        return i ^= 15;
        });

    return hashed;
}

bool hasDuplicates(string username, string password)
{
    ifstream fi;
    string uname, pass;

    fi.open("database.txt", ios::in);

    if (fi.fail())
        return false;

    while (fi >> uname >> pass) {
        if (uname == username && pass == password) {
            fi.close();
            return true;
        }
    }

    fi.close();

    return false;
    
}

void login()
{
    int count = 0;
    system("cls");
    setPosition(43, 7);
    cout << "         -- ";
    cout << "Login";
    cout << " --          " << endl;
    setPosition(43, 8);
    cout << " ---------------------------- " << endl;
    setPosition(43, 9);
    cout << "|          ";
    cout << "Username: "; 
    cout << "        | " << endl;
    setPosition(43, 10);
    cout << "|         ->                 |" << endl;
    setPosition(43, 11);
    cout << "|          ";
    cout << "Password: "; 
    cout << "        | " << endl;
    setPosition(43, 12);
    cout << "|         ->                 |" << endl;
    setPosition(43, 13);
    cout << " ---------------------------- " << endl;
    
    setPosition(55, 10);
    cin >> user;
    setPosition(55, 12);
    cin >> hashedPass;

    hashedPass = hashPassword(hashedPass);

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == hashedPass)

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
        currentUser = user;
        currentPassword = hashedPass;
        system("cls");
        check = true;

        mainMenu();
    }
    else
    {
        system("cls");
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
    }
}

void registr()
{
    Beggining:
    system("cls");
    setPosition(43, 7);
    cout << "        -- ";
    cout << "Register ";
    cout << "--        " << endl;
    setPosition(43, 8);
    cout << " ---------------------------- " << endl;
    setPosition(43, 9);
    cout << "|          ";
    cout << "Username: ";
    cout << "        | " << endl;
    setPosition(43, 10);
    cout << "|         ->                 |" << endl;
    setPosition(43, 11);
    cout << "|          ";
    cout << "Password: ";
    cout << "        | " << endl;
    setPosition(43, 12);
    cout << "|         ->                 |" << endl;
    setPosition(43, 13);
    cout << " ---------------------------- " << endl;

    setPosition(55, 10);
    cin >> reguser;

    setPosition(55, 12);
    cin >> hashedRegpass;

    hashedRegpass = hashPassword(hashedRegpass);

    if (hasDuplicates(reguser, hashedRegpass) == true)
    {
        system("cls");
        cout << "This password already exists!" << endl;
        Sleep(1000);
        goto Beggining;
    }
    else
    {
        fstream reg("database.txt", ios::app);
        reg << reguser << ' ' << hashedRegpass << endl;
        system("cls");
        cout << "\nRegistration Sucessful\n";
        cout << "Redirecting you to the Login Menu";
        Sleep(1000);
        system("cls");

        login();
    }

}

void forgot()
{
    system("cls");
    setPosition(26, 5);
    cout << "        -- ";
    cout << "ForgotDetails ";
    cout << "--        " << endl;
    setPosition(30, 6);
    cout << "---------------------------" << endl;
    setPosition(30, 7);
    cout << "|" << endl;
    setPosition(30, 8);
    cout << "|" << endl;
    setPosition(30, 9);
    cout << "|" << endl;
    setPosition(30, 10);
    cout << "|" << endl;
    setPosition(30, 11);
    cout << "|" << endl;
    setPosition(30, 12);
    cout << "|" << endl;
    setPosition(56, 7);
    cout << "|" << endl;
    setPosition(56, 8);
    cout << "|" << endl;
    setPosition(56, 9);
    cout << "|" << endl;
    setPosition(56, 10);
    cout << "|" << endl;
    setPosition(56, 11);
    cout << "|" << endl;
    setPosition(56, 12);
    cout << "|" << endl;
    setPosition(30, 13);
    cout << "---------------------------" << endl;
    setPosition(35, 9);
    cout << " Search by username" << endl;
    setPosition(35, 10);
    cout << " Search by password" << endl;
    setPosition(35, 11);
    cout << " Main menu" << endl;

    int y = 9, choice = 0;

    while (true) {
        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && y != 13) {
            setPosition(32, y);
            cout << "  ";
            y++;
            setPosition(32, y);
            cout << "-> ";
            choice++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && y != 9) {
            setPosition(32, y);
            cout << "  ";
            y--;
            setPosition(32, y);
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
                    cout << "\nYour password is " << hashPassword(sp);
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
                    if (sp2 == hashPassword(searchpass))
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

void showUsers()
{
    if (check == true)
    {
        fstream myFile;
        string text;
        myFile.open("database.txt");

        while (getline(myFile, text))
        {
            cout << text << endl;
        }
    }
    else
    {
        cout << "You must sign in first" << endl;
        Sleep(1000);
        system("cls");
        login();
    }
}



void mainMenu()
{
    setPosition(27, 5);
    cout << "        -- ";
    cout << "MainMenu ";
    cout << "--        " << endl;
    setPosition(30, 6);
    cout << "-------------------------" << endl;
    setPosition(30, 7);
    cout << "|" << endl;
    setPosition(30, 8);
    cout << "|" << endl;
    setPosition(30, 9);
    cout << "|" << endl;
    setPosition(30, 10);
    cout << "|" << endl;
    setPosition(30, 11);
    cout << "|" << endl;
    setPosition(30, 12);
    cout << "|" << endl;
    setPosition(30, 13);
    cout << "|" << endl;
    setPosition(30, 14);
    cout << "|" << endl;
    setPosition(54, 7);
    cout << "|" << endl;
    setPosition(54, 8);
    cout << "|" << endl;
    setPosition(54, 9);
    cout << "|" << endl;
    setPosition(54, 10);
    cout << "|" << endl;
    setPosition(54, 11);
    cout << "|" << endl;
    setPosition(54, 12);
    cout << "|" << endl;
    setPosition(54, 13);
    cout << "|" << endl;
    setPosition(54, 14);
    cout << "|" << endl;
    setPosition(30, 15);
    cout << "-------------------------" << endl;
    setPosition(37, 9);
    cout << "Login";
    setPosition(37, 10);
    cout << "Register";
    setPosition(37, 11);
    cout << "ForgotDetails";
    setPosition(37, 12);
    cout << "ShowUsers";
    setPosition(37, 13);
    cout << "Exit";

    int y = 9, choice = 0;

    while (true) {
        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && y != 13) {
            setPosition(33, y);
            cout << "  ";
            y++;
            setPosition(33, y);
            cout << "-> ";
            choice++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && y != 9) {
            setPosition(33, y);
            cout << "  ";
            y--;
            setPosition(33, y);
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
            case 3:
                system("cls");
                showUsers();
                break;
            case 4:
                system("cls");
                cout << "Goodbye!";
                break;
            }

        }
    }
}

