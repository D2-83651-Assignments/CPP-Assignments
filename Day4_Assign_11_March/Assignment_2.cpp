/*
Q2. Write a menu driven program for Student management.
In main(), create Array of Objects and provide facility for accept, print, search and sort.
For student accept name, gender, rollNumber and marks of three subjects from user and print name,
rollNumber, gender and percentage.
Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
sorting and searching array.
Search function returns index of found Student, otherwise returns -1.
*/
#include <iostream>
#define SWAP(a,b) {Student temp =a; a=b;b=temp;}
using namespace std;

class Student
{
    string name;
    string gender;
    int rollNumber;
    float marks[3];

public:
    Student()
    {
        name = "";
        gender = "";
        rollNumber = 0;
    }

    void acceptStudentDetails()
    {
        cout << "\nEnter name : ";
        cin >> name;
        cout << "\nEnter gender : ";
        cin >> gender;
        cout << "\nRoll Number : ";
        cin >> rollNumber;
        cout << "\nEnter student marks : ";
        for(int i=0;i<3;i++)
        {
            cin >> marks[i];
        }
    }

    int calculatePercentage()
    {
        int total_Marks=0;
        for(int i=0;i<3;i++)
        {
            total_Marks +=marks[i];
        }
        return (total_Marks/3.0);
    }

    int getStudentRoll()
    {
        return rollNumber;
    }

    void displayStudentDetails()
    {
        cout << "\n--------------------------";
        cout << "\nName : " << name;
        cout << "\nGender : " << gender;
        cout << "\nRoll Number : " << rollNumber;
        cout<<"\nPercentage : "<<calculatePercentage()<<"%";
        cout << "\n--------------------------\n";
    }
};

int searchStudentDetails(Student s[], int n, int rollNumber)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].getStudentRoll() == rollNumber)
        {
            flag = 1;
            return i;
        }
        else
        {
            continue;
        }
    }
    if (!flag)
    {
        cout << "\n Student not found!!";
    }
    return -1;
}

void sortRecords(Student arr[], int n)
{
    
    for (int sel_pos = 0; sel_pos < n - 1; sel_pos++)
    {
    
        for (int pos = sel_pos + 1; pos < n; pos++)
        {
            if (arr[sel_pos].getStudentRoll() > arr[pos].getStudentRoll())
            {
                SWAP(arr[sel_pos], arr[pos]);
            }
        }
    }
}
enum EStudent
{
    EXIT,
    ACCEPT,
    DISPLAY,
    SEARCH,
    SORT
};

int main()
{
    int choice, index = -1, id, number;
    Student *std = NULL;
    cout << "\nHow many student details do you want : ";
    cin >> number;
    std = new Student[number];
    do
    {
        cout << "\n0.Exit.";
        cout << "\n1.Accept student details.";
        cout << "\n2.Display Student details.";
        cout << "\n3.Search employee details.";
        cout << "\n4.Sort Students";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (EStudent(choice))
        {
        case ACCEPT:
            index++;
            std[index].acceptStudentDetails();
            break;
        case DISPLAY:
            for (int i = 0; i < number; i++)
            {
                std[i].displayStudentDetails();
            }

            break;
        case SEARCH:{
            cout << "\nEnter student id do you want to search : ";
            cin >> id;
            int value = searchStudentDetails(std, number, id);
            std[index].displayStudentDetails();
            break;}
        case SORT:
            cout<<"\nArray is Sortes Sort.";
            sortRecords(std, number);
            break;
        default :
            cout<<"\nYou have entered wrong choice!!";
            break;
        };

    } while (choice != 0);
    
    delete[] std;
    std = NULL;
    return 0;
}
