#include <iostream>
#include <fstream> //to read write files
#include <string>

using namespace std;

void login();
void registration();
void forgot();

bool isLoggedIn()
{
    // checks if input uname and pas-s are in database or not
    string username, password, u, p;
    // u and p are to compare username and password

    cout << "Please Enter Username and Password: \n";
    cout << "Username: \n";
    cin >> username;
    cout << "Password:\n ";
    cin >> password;

    ifstream read("userData\\" + username + ".txt"); // searches for the username.txt file in userData folder
    read >> u >> p;

    if (u == username && p == password)
    {
        // checking if username and password exists or not
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << " Welcome!\n\n";
    cout << " Press 1 to LOGIN \n";
    cout << " Press 2 to REGISTER \n";
    cout << "Press 3 if you FORGOT your PASSWORD\n";
    cout << "Press 4 to EXIT \n";
    cout << "Enter your choice:    ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "You have exited the system, thankyou! . see you soon .\n\n";
        break;
    default:
        cout << "Invalid choice, please select from the options given.\n";
        main();
    }

    return 0;
}

void registration()
{
    string username, password, color;

    cout << "\nEnter a Username (no spaces allowed): \n";
    cin >> username;
    cout << "Enter a password (no spaces allowed): \n";
    cin >> password;
    cout << "Security Question (to recover your account in case you forgot your password)\nWhat is your favorite color: ";
    cin >> color;

    ofstream file;
    file.open("userData\\" + username + ".txt");
    file << username << endl
         << password << endl
         << color;

    // store user credentials in username.txt
    file.close();

    cout << "\n\t\t\tSuccessfully Registered.";
    main();
}

void login()
{

    if (!isLoggedIn())
    {
        cout << "Invalid Credentials!\nTry Again.";
        main();
    }
    else
        cout << "\n congratulations!! you are successfully Loggedin.";
    exit(0);
}

void forgot()
{
    string username, u, p, c, color;
    cout << "\nforgot your password ? lets try to recover it.";
    cout << "\nEnter your Username: ";
    cin >> username;

    ifstream file;
    file.open("userData\\" + username + ".txt");
    if (file)
    {
        // checks if username is correct
        cout << "\n Answer the Question correctly to recover your password.";
        cout << "\n  What is your favorite color: ";
        cin >> color;
        file >> u >> p >> c;
        if (c == color)
        {
            cout << "\n  Yes you answered it correctly. Your Password is: " << p;
            main();
        }
        else
        {
            cout << "\n Wrong Answer. Try again later.";
            exit(0);
        }
    }
    else
    {
        cout << "\n--- Username not found, try again later.";
        exit(0);
    }
}