#include <iostream>

using namespace std;

class Employee
{
    int empId;
    float salary;

public:
    Employee()
    {
        empId = 0;
        float salary = 0;
    }

    Employee(int empId, float salary)
    {
        this->empId = empId;
        this->salary = salary;
    }

    void setEmpId(int empId)
    {
        this->empId = empId;
    }

    int getId()
    {
        return empId;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    float getSalary()
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "\nEnter emp Id : ";
        cin >> empId;
        cout << "\nEnter salary : ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "\nEmp Id : " << empId;
        cout << "\nSalary : " << salary;
    }

    virtual ~Employee()
    {

    }
};

class Manager : virtual public Employee
{
    float bonus;

protected:
    void acceptManager()
    {
        cout << "\nEnter bonus : ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "\nBonus : " << bonus;
    }

public:
    Manager()
    {
        bonus = 0;
    }

    Manager(int empId, float salary, float bonus) : Employee(empId, salary)
    {
        //Employee(empId,salary);
        this->bonus = bonus;
    }

    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }

    float getBonus()
    {
        return bonus;
    }

    void accept()
    {
        cout<<"\n--------------------------------";
        cout<<"\n---- Enter Manager details -----";
        cout<<"\n--------------------------------";
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        cout<<"\n--------------------------------";
        cout<<"\n------- Manager details --------";
        cout<<"\n--------------------------------";
        Employee::display();
        displayManager();
    }

    ~Manager()
    {

    }
};

class Salesman : virtual public Employee
{
    float commission;

protected:
    void acceptSalesman()
    {
        cout << "\nEnter Commission : ";
        cin >> commission;
    }

    void displaySalesman()
    {
        cout << "\nCommission of salesman is : "<<commission;
    }


public:
    Salesman()
    {
        commission = 0;
    }

    Salesman(int empId, float salary, float commission)
    {
        Employee(empId, salary);
        this->commission = commission;
    }

    void setCommission(float commission)
    {
        this->commission = commission;
    }

    float getCommission()
    {
        return commission;
    }

    void accept()
    {
        cout<<"\n--------------------------------";
        cout<<"\n---- Enter Salesman details ----";
        cout<<"\n--------------------------------";
       Employee::accept();
       acceptSalesman();
        
    }

    void display()
    {
        cout<<"\n--------------------------------";
        cout<<"\n------- Salesman details -------";
        cout<<"\n--------------------------------";
        Employee::display();
        displaySalesman();
    }

    ~Salesman()
    {

    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {

    }

    SalesManager(int empId, float salary, float commission, float bonus)
    {
        setEmpId(empId);
        setSalary(salary);
        setCommission(commission);
        setBonus(bonus);
    }

    void accept()
    {
        cout<<"\n--------------------------------";
        cout<<"\n-- Enter Salesmanager details --";
        cout<<"\n--------------------------------";
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }

    void display()
    {
        cout<<"\n--------------------------------";
        cout<<"\n----- Salesmanager details -----";
        cout<<"\n--------------------------------";
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

enum EEmployee
{
    EXIT,ACCEPT_MANAGER,ACCEPT_SALESMAN,SALES_MANAGER,COUNT_WITH_DEGIGNATION, DISPLAY_MANAGER,DISPLAY_SALESMAN, DISPLAY_SALESMANAGER
};

int menu()
{
    int choice;
    cout<<"\n-----------------------------------------------";
    cout<<"\n0. Exit";
    cout<<"\n1.Accept Manager.";
    cout<<"\n2.Accept Salesman.";
    cout<<"\n3.Accept SalesManager.";
    cout<<"\n4.Display Count of employee with designation.";
    cout<<"\n5.Display All Managers.";
    cout<<"\n6.Display All SalesMan.";
    cout<<"\n7.Display All SalesManager.";
    cout<<"\n-----------------------------------------------";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    return choice;
}

int main()
{
    int choice,size,count=0;
    int managerCount = 0,salesmanCount = 0,salesManagerCount = 0;
    cout<<"\nEnter how many employees do you want in your firm : ";
    cin>>size;
    Employee *ptr[size];

    while((choice=menu())!=0)
    {
        switch(EEmployee(choice))
        {
            case ACCEPT_MANAGER:
                if(count<size)
                {
                    managerCount++;
                    count++;
                    ptr[count] = new Manager();
                    ptr[count]->accept();
                }
                else
                {
                    cout<<"\nNo Vacancy!!, Ressession period.";
                }
                break;
            case ACCEPT_SALESMAN:
                if(count < size)
                {
                    salesmanCount++;
                    count++;
                    ptr[count] = new Salesman();
                    ptr[count]->accept();
                }
                else
                {
                    cout<<"\nNo Vacancy!!, Ressession period.";
                }
                break;  
            case SALES_MANAGER:
                if(count < size)
                {
                    salesManagerCount++;
                    count++;
                    ptr[count] = new SalesManager();
                    ptr[count]->accept();
                }
                else{
                    cout<<"\nNo Vacancy!!, Ressession period.";
                }
                break;
            case COUNT_WITH_DEGIGNATION:{  
                cout<<"\n--------------------------------------------------------------";              
                cout<<"\n"<<managerCount<<" Managers are working in company.";
                cout<<"\n"<<salesmanCount<<" Salesman are working in company.";
                cout<<"\n"<<salesManagerCount<<" Sales Manager are working in company.";
                cout<<"\n--------------------------------------------------------------";
                break;}
            case DISPLAY_MANAGER :
                for(int i=1; i<=count ; i++)
                {
                    if(typeid(*ptr[i]) == typeid(Manager))
                        ptr[i]->display();
                }
                break;
            case DISPLAY_SALESMAN :
                for(int i=1;i<=count;i++)
                {
                    if(typeid(*ptr[i])==typeid(Salesman))
                        ptr[i]->display();
                }
                break;
            case DISPLAY_SALESMANAGER :
                for(int i=1;i<=count;i++)
                {
                    if(typeid(*ptr[i])==typeid(SalesManager))
                        ptr[i]->display();
                }
                break;               
        }

    }
    cout<<"\n===========Thank You!!============="<<endl;

    for(int i=1;i<=count;i++)
    {
        delete ptr[i];
    }
    return 0;
}