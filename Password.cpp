string getPassword()
{
    string password;
    char ch;

    cout << "Enter password: ";
    while ((ch = _getch()) != 13)
    {
        if (ch == '\b' && !password.empty())
        {
            cout << "\b \b";
            password.pop_back();
        }
        else if (ch != '\b')
        {
            cout << '*';
            password.push_back(ch);
        }
    }
    cout << endl;
    return password;
}