/*
Q2. Create a class called as Employee with data members id,name and salary.Take the input of size
when program starts and Create the array of employee pointers of that size. Provide a menu driven
code for accepting employee, dislpay all employees, find employee based on empid. Here the empid
should be auto-generated and once initialized it should not be changed.
*/

#include <iostream>
using namespace std;

class Employee
{
    const int empId;
    string name;
    double salary;
    static int generateEmpID;

public:
    Employee() : empId(++generateEmpID)
    {
        name = "";
        salary = 0.0;
    }

    void acceptEmployeeInfo()
    {
        cout << "\nEnter Employee name : ";
        cin >> name;
        cout << "\nEnter salary : ";
        cin >> salary;
    }

    void displayEmployeeInfo()
    {
        cout << "\nEmp Id : " << empId;
        cout << "\nname : " << name;
        cout << "\nsalary : " << salary;
    }

    int getEmpId()
    {
        return empId;
    }
};
int Employee::generateEmpID = 1000;
int menu()
{
    int choice;

    return choice;
}

enum EEmp
{
    EXIT,
    ACCEPT_EMP_INFO,
    FINDEMP,
    DISPLAY
};

int main()
{
    int choice, n, index = -1, id;
    int flag = 0;
    cout << "\nEnter how many times do you want to fill employee details : ";
    cin >> n;
    Employee **emp = new Employee *[n];

    do
    {
        cout << "\n0.Exit.";
        cout << "\n1.Enter Employee Info.";
        cout << "\n2.Find Employee.";
        cout << "\n3.Display Employee Info";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (EEmp(choice))
        {
        case ACCEPT_EMP_INFO:
            index++;
            emp[index] = new Employee;
            emp[index]->acceptEmployeeInfo();
            break;
        case FINDEMP:
            if (index == -1)
            {
                cout << "Employee not found!!";
                cout << "\nCreate account first.";
            }
            else
            {
                cout << "\nEnter employee id do you want to find : ";
                cin >> id;
                for (int i = 0; i < n; i++)
                {
                    if (emp[i]->getEmpId() == id)
                    {
                        emp[i]->displayEmployeeInfo();
                        flag = 1;
                    }
                    else
                    {
                        continue;
                    }
                    if (!flag)
                    {
                        cout << "Employee not found!!";
                    }
                }
                break;
            }
        case DISPLAY:
            if (index == -1)
            {
                cout << "Employee not found!!";
                cout << "\nCreate account first.";
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    emp[i]->displayEmployeeInfo();
                }
                break;
            }
        }
    } while (choice != 0);

    for(int i=0; i<n; i++)
        {
            delete emp[i];
            emp[i] = NULL;
        }
        delete[] emp;
        emp = NULL;

    return 0;
}