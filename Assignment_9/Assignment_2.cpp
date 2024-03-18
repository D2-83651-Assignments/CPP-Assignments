#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

enum EAccountType
{
    SAVING,
    CURRENT,
    DMAT
};

class InsufficientFundsException
{
    string message;

public:
    InsufficientFundsException(string message)
    {
        this->message = message;
    }

    void getInsufficientFundsException()
    {
        cout << message << endl;
    }
};

class Account
{
    int id;
    double balance;
    EAccountType type;

public:
    Account() {}

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

    int getId() const
    {
        return id;
    }

    void setType(EAccountType type)
    {
        this->type = type;
    }

    EAccountType getType() const
    {
        return type;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    double getBalance() const
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
        type = static_cast<EAccountType>(number);
    }

    void display() const
    {
        cout << "\n ID : " << id;
        cout << "\n Balance : " << balance;
        cout << "\n Account Type : ";
        if (type == SAVING)
        {
            cout << "Saving";
        }
        else if (type == CURRENT)
        {
            cout << "Current";
        }
        else
        {
            cout << "DMAT";
        }
        cout << "\n";
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

int menu()
{
    int choice;
    cout << "\n0.Exit.";
    cout << "\n1.Add Account.";
    cout << "\n2.Deposit.";
    cout << "\n3.Withdraw.";
    cout << "\n4.Display All Accounts.";
    cout << "\nEnter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice, id;
    double depositAmount, withdrawAmount;
    list<Account> accountList;
    try
    {
        while ((choice = menu()) != 0)
        {
            switch (choice)
            {
            case 1:
            {
                Account newAccount;
                newAccount.accept();
                accountList.push_back(newAccount);
                break;
            }
            case 2:
                cout << "\nEnter Account ID to deposit: ";
                cin >> id;
                for (auto &account : accountList)
                {
                    if (account.getId() == id)
                    {
                        cout << "\nEnter amount to deposit: ";
                        cin >> depositAmount;
                        account.deposite(depositAmount);
                        break;
                    }
                }
                break;
            case 3:
                cout << "\nEnter Account ID to withdraw: ";
                cin >> id;
                for (auto &account : accountList)
                {
                    if (account.getId() == id)
                    {
                        cout << "\nEnter amount to withdraw: ";
                        cin >> withdrawAmount;
                        account.withdraw(withdrawAmount);
                        break;
                    }
                }
                break;
            case 4:
                for (const auto &account : accountList)
                {
                    account.display();
                }
                break;
            default:
                cout << "\nYou have entered the wrong choice!!";
                break;
            }
        }
    }
    catch (InsufficientFundsException &error)
    {
        error.getInsufficientFundsException();
    }

    return 0;
}
