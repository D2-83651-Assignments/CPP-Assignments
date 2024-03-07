// Q3. Create a namespace NStudent. Create the Student class(created as per assignment-1 Q3) inside
// namespace. Test the functionalities.

#include <iostream>
using namespace std;

namespace NStudent
{
class student
{
    int rollNo;
    string name;
    int marks;

public:
    void initStudent()
    {
        rollNo = 0;
        name = "NULL";
        marks = 0;
    }

    void printStudentOnConsole()
    {
        cout << "==========================================" << endl;
        cout << "Student information : " << endl;
        cout << "==========================================" << endl;
        cout << "\nRoll number : " << rollNo;
        cout << "\nName : " << name;
        cout << "\nmarks : " << marks;
    }

    void acceptStudentFromConsole()
    {
        cout << "\n==========================================";
        cout << "\nEnter student details : " << endl;
        cout << "==========================================" << endl;

        cout << "Roll Number : ";
        cin >> rollNo;
        cin.ignore();
        cout << "\nName : ";
        // cin >> name;
        getline(cin, name);
        cout << "\nMarks : ";
        cin >> marks;
    }

    int menu()
    {
        int choice;
        cout << "\n==========================================";
        cout << "\n1. Display student information" << endl;
        cout << "2. Accept student information from user" << endl;
        cout << "==========================================" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        return choice;
    }
};
}

//using namespace NStudent;
int main()
{
    NStudent::student s;
    s.initStudent();
    int choice;

    while ((choice = s.menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            s.printStudentOnConsole();
            
            break;
        case 2:
            s.acceptStudentFromConsole();
            break;
        default:
            cout << "You have entered wrong choice!!" << endl;
            break;
        }
    }
    return 0;
}