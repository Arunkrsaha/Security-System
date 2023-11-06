#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int choice;
    string username, oldPassword, newPassword, reenteredPassword, line, data, age, user, word, word1;

    cout << "     Security System     " << endl;
    cout << "______________________________" << endl
         << endl;
    cout << "|      1. Register           |" << endl;
    cout << "|      2. Login              |" << endl;
    cout << "|      3. Change Password    |" << endl;
    cout << "|      4. End Program        |" << endl;
    cout << "|____________________________|" << endl
         << endl;

    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "___________________" << endl
                 << endl;
            cout << "|-----Register----|" << endl;
            cout << "|_________________|" << endl
                 << endl;
            cout << "Please enter Username: ";
            cin >> username;
            cout << "Please enter the password: ";
            cin >> data;
            cout << "Please enter your age: ";
            cin >> age;

            ofstream ofs("file.txt");
            if (ofs.is_open())
            {
                ofs << username << "\n";
                ofs << data;
                cout << "Registration successful" << endl;
                ofs.close();
            }
            break;
        }

        case 2:
        {
            cout << "_____________________" << endl
                 << endl;
            cout << "|------Login--------|" << endl;
            cout << "|___________________|" << endl
                 << endl;

            ifstream ifs("file.txt");
            cout << "Please enter your Username: ";
            cin >> user;
            cout << "Please enter your password: ";
            cin >> data;

            if (ifs.is_open())
            {
                bool found = false;

                while (getline(ifs, line))
                {
                    istringstream iss(line);
                    iss >> word;

                    if (user == word)
                    {
                        getline(ifs, line);
                        istringstream iss2(line);
                        iss2 >> word;
                        if (data == word)
                        {
                            cout << "---Log in successful---" << endl
                                 << endl;
                            cout << "Details: " << endl;
                            cout << "Username: " + user << endl;
                            cout << "Age: " + age << endl;
                            found = true;
                        }
                    }
                }

                if (!found)
                {
                    cout << "Incorrect Credentials" << endl;
                    cout << "|    1. Press 2 to Login          |" << endl;
                    cout << "|    2. Press 3 to change password|" << endl;
                }
            }
            ifs.close();
            break;
        }

        case 3:
        {
            cout << "--------Change Password--------" << endl;
            ifstream ifs("file.txt");

            if (!ifs.is_open())
            {
                cout << "Error opening the file." << endl;
                break;
            }

            cout << "Enter the old password: ";
            cin >> oldPassword;

            bool passwordChanged = false;
            stringstream updatedData;

            if (ifs.is_open())
            {
                while (getline(ifs, line))
                {
                    istringstream iss(line);
                    iss >> word1;
                    if (oldPassword == word1)
                    {
                        cout << "Enter your new Password: ";
                        cin >> newPassword;
                        cout << "Reenter your new Password: ";
                        cin >> reenteredPassword;
                        if (newPassword == reenteredPassword)
                        {
                            updatedData << newPassword << "\n";
                            passwordChanged = true;
                        }
                        else
                        {
                            updatedData << oldPassword << "\n";
                        }
                    }
                    else
                    {
                        updatedData << word1 << "\n";
                    }
                }
                ifs.close();
            }

            if (passwordChanged)
            {
                ofstream ofs("file.txt");
                if (ofs.is_open())
                {
                    ofs << updatedData.str();
                    cout << "Password changed successfully" << endl;
                    ofs.close();
                }
            }
            else
            {
                cout << "Please enter a valid Password" << endl;
            }

            break;
        }

        case 4:
        {
            cout << "__________Thank you!__________" << endl;
            break;
        }

        default:
            cout << "Enter a valid choice";
        }
    } while (choice != 4);

    return 0;
}
