
/*
Q1. Implement following classes. Test all functionalities in main().
Create a class Date with data memebrs day,month and year.
Create a class Person with data members name,address and birthdate. The birthdate should be of
type date.
Create a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement the above class as per the class Hirerachy and test the functunalities.
*/

#include<iostream>

using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2001;
    }

    Date(int day,int month,int year)
    {
        this->day=day;
        this->month=month;
        this->year = year;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    int getDay(int day)
    {
        return day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    int getMonth(int month)
    {
        return month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    int getYear(int year)
    {
        return year;
    }

    void acceptDate()
    {   
        cout<<"\nEnter day : ";
        cin>>day;
        cout<<"\nEnter month : ";
        cin>>month;
        cout<<"\nEnter year : ";
        cin>>year;
    }

    void DisplayDate()
    {
        cout<<"\nDate : "<<day<<":"<<month<<":"<<year<<endl;
    }

};

class Person  
{
    string name;
    string address;
    Date birthDate;

public: 
    Person()
    {
        name = "";
        address = "";
    }

    Person(string name,string address , int day , int month, int year)
    {
        this->name=name;
        this->address = address;
        Date(day,month,year);
    }

    void setName()
    {
        getline(cin,name);
    }

    string getName()
    {
        return name;
    }

    void setAddress()
    {
        getline(cin,address);
    }

    string getAddress()
    {
        return address;
    }

    void setDate(Date date)
    {
        this->birthDate = date;
    }

    Date getDate()
    {
        return birthDate;
    }

    void acceptPersonDetails()
    {
        cout<<"\nEnter name : ";
        cin>>name;
        cout<<"\nEnter Address : ";
        cin>>address;
        cout<<"\nEnter Date : ";
        birthDate.acceptDate();
    }

    void displayPersonDetails()
    {
        cout<<"\n---------------------------\n";
        cout<<"        Person Details       \n";
        cout<<"\n---------------------------\n";
        cout<<"\nName : "<<name;
        cout<<"\nAddress : "<<address;
        birthDate.DisplayDate();
    }
};

class Employee : public Person
{
    int empId;
    double salary;
    string department;
    Date joining;

public:
    Employee()
    {
        empId = 0;
        salary = 0.0;
        string department = "Bench";
    }

    Employee(int empId,double salary, string department,int day, int month, int year)
    {
        this->empId = empId;
        this->salary = salary;
        this->department = department;
        Date(day,month,year);
    }

    void setJoining(Date date)
    {
        this->joining=date;
    }

    Date getJoining()
    {
        return joining;
    }

    void acceptEmployeeDetails()
    {
        cout<<"\n-----------------------------------";
        cout<<"Enter name : ";
        setName();
        cout<<"Enter address : ";
        setAddress();
        cout<<"\nEnter employee id : ";
        cin>>empId;
        cout << "\nEnter employee salary : ";
        cin>>salary;
        cout << "\nEnter employee department : ";
        cin.ignore();
        getline(cin,department);
        cout << "\nEnter Employee's joining date : ";
        joining.acceptDate();
        cout<<"\n-----------------------------------\n" ;
    }

    void displayEmployeeDetails()
    {
        cout<<"\n---------------------------\n";
        cout<<"        Employee Details       \n";
        cout<<"\n---------------------------\n";
        cout<<"\nEMployee Name : "<<getName();
        cout<<"\nAddress : "<<getAddress();
        cout<<"\nID : "<<empId;
        cout<<"\nSalary : "<<salary;
        cout<<"\nDepartment : "<<department;
        joining.DisplayDate();
    }
};


int main()
{

    Employee e;
    e.acceptEmployeeDetails();
    e.displayEmployeeDetails();

    Person p;
    p.acceptPersonDetails();
    p.displayPersonDetails();
    return 0;
}