#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class User
{
protected:
    string firstName;
    string surName;
    string password;
    string contactDetails;
    string nationalID;

public:
    // User() {}
    // User(const string &_name, const string &_nationalID, const string &_password, const string &_contactDetails)
    //     : name(_name), nationalID(_nationalID), password(_password), contactDetails(_contactDetails) {}

    void inputData()
    {
        cout << "Enter your first name: ";
        cin >> firstName;
        cout << "Enter your surname: ";
        cin >> surName;
        cout << "Enter your national ID: ";
        cin >> nationalID;
        password = getPassword();
        cout << "Contact details: ";
        cin >> contactDetails;
    }
    virtual void FileData() = 0;
};