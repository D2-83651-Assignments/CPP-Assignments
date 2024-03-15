#include <iostream>

using namespace std;

enum EAccountType
{
    SAVING,
    CURRENT,
    DMAT
};

class InsufficientFundsException
{
    int accId;
    double cur_balance;
    double withraw_amount;
    string message;

public:
    // InsufficientFundsException(int accId, double cur_balance, double withraw_amount)
    // {
    //     this->accId = accId;
    //     this->cur_balance = cur_balance;
    //     this->withraw_amount = withraw_amount;
    // }

    InsufficientFundsException(string message)
    {
        this->message = message;
    }

    void getInsufficientFundsException()
    {
        cout << message << endl;
    }

    // void display()
    // {
    //     cout << "\n Account ID : " << accId;
    //     cout << "\n Current Balance : " << cur_balance;
    //     cout << "\n WIthraw Amount : " << withraw_amount;
    // }
};

class Account
{
    int id;
    double balance;
    EAccountType type;

public:
    Account()
    {
    }

    Account(int id, double balance, EAccountType type)
    {
        this->id = id;
        this->balance = balance;
        this->type = type;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setType(EAccountType type)
    {
        this->type = type;
    }

    EAccountType getType()
    {
        return type;
    }

    void setBalance(int balance)
    {
        this->balance = balance;
    }

    int getBalance()
    {
        return balance;
    }

    void accept()
    {
        int number;
        cout << "\nEnter id : ";
        cin >> id;
        cout << "\nEnter Balance : ";
        cin >> balance;
        cout << "\nEnter Account Type : ";
        do
        {
            cout << "\n 0.Saving account.";
            cout << "\n 1.Current Account.";
            cout << "\n 2.DMAT Account.";
            cin >> number;
            if (number < 0 || number > 2)
            {
                cout << "\nEnter again..!!";
            }
        } while (number < 0 || number > 2);
        type = (EAccountType)number;
    }

    void display()
    {
        cout << "\n ID : " << id;
        cout << "\n Balance : " << balance;
        cout << "\nAccount Type : " << type;
        if (type == SAVING)
        {
            cout << "Saving.";
        }
        else if (type == CURRENT)
        {
            cout << "Current.";
        }
        else
        {
            cout << "DMAT.";
        }
        cout << "\nTotal Account Balance is : " << balance;
    }

    void deposite(double amount)
    {
        if (amount < 0)
            throw InsufficientFundsException("\nAmount should be positive!!");
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount < 0)
            throw InsufficientFundsException("\nInsufficient balance, In your account!!");
        balance -= amount;
    }
};

int searchEmployeeById(Account *acc[], int id, int num)
{
    int flag = 0;
    for (int i = 0; i < num; i++)
    {
        if (acc[i]->getId() == id)
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
        cout << "\n Employee not found!!";
    }
    return -1;
}

int menu()
{
    int choice;
    cout << "\n0.Exit.";
    cout << "\n1.Add Account.";
    cout << "\n2.Deposite.";
    cout << "\n3.Withdraw.";
    cout << "\n4.Display All Accounts.";
    cout << "\nEnter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice, count = -1, id;
    double depositeAmount, withdrawAmount;
    Account *aptr[5];
    try
    {
        while ((choice = menu()) != 0)
        {
            switch (choice)
            {
            case 1:
                if (count < 5)
                {
                    count++;
                    aptr[count] = new Account();
                    aptr[count]->accept();
                }
                else
                {
                    cout << "\nArray is full!!";
                }
                break;
            case 2:
                if (count < 5)
                {
                    cout << "\nEnter employee Id : ";
                    cin >> id;
                    int num = searchEmployeeById(aptr, id, 5);
                    if (num < 0)
                        break;
                    cout << "\nEnter amount to deposite : ";
                    cin >> depositeAmount;
                    aptr[num]->deposite(depositeAmount);
                }
                else
                {
                    cout << "\nArray is full!!";
                }
                break;
            case 3:
                if (count < 5)
                {
                    cout << "\nEnter employee Id : ";
                    cin >> id;
                    int num = searchEmployeeById(aptr, id, 5);
                    if (num < 0)
                        break;
                    cout << "\nEnter amount to withdraw : ";
                    cin >> withdrawAmount;
                    aptr[num]->withdraw(withdrawAmount);
                }
                else
                {
                    cout << "\nArray is full!!";
                }
                break;
            case 4:
                for (int i = 0; i <= count; i++)
                    aptr[i]->display();
                break;
            default:
                cout << "\nYou have entered wrong choice!!";
                break;
            }
        }
    }
    catch (InsufficientFundsException &error)
    {
        error.getInsufficientFundsException();
    }

    for (int i = 0; i < count; i++)
    {
        delete aptr[i];
    }

    return 0;
}
