#include <iostream>

using namespace std;
class FactorialException
{
    string exceptionMessage;
public :
    FactorialException()
    {
        cout<<"Something went wrong!!";
    }

    FactorialException(string exceptionMessage)
    {   
        this->exceptionMessage = exceptionMessage;
    }

    void displayException()
    {
        cout<< exceptionMessage <<endl;
    }
};

class Factorial
{
public:
    int factorial(int num)
    {
        if(num < 0)
            throw FactorialException("Value must be non-negative number!!");
        else if (num == 0)
        {
            return 1;
        }
        else if (num == 1)
        {
            return 1;
        }
        else
        {
            return num * factorial(num - 1);
        }
    }
};

int main()
{
    Factorial f;
    try
    {
        cout<<"\n"<<f.factorial(-1)<<endl;
    }
    catch(FactorialException &error)
    {
        error.displayException();
    }
    return 0;
}