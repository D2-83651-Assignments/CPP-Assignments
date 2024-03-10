
/*
Q1. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically.
*/
#include <iostream>
using namespace std;

enum ETime
{
    SET_TIME = 1,
    GET_TIME
};
class Time
{
    int hour;
    int minute;
    int seconds;

public:
    Time()
    {
        this->hour = 0;
        this->minute = 0;
        this->seconds = 0;
    }
    Time(int hour, int minute, int seconds)
    {
        this->hour = hour;
        this->minute = minute;
        this->seconds = seconds;
    }
    int getHour()
    {
        return hour;
    }
    int getMinute()
    {
        return minute;
    }
    int getSeconds()
    {
        return seconds;
    }
    void printTime()
    {
        cout << "Time : " << hour << ":" << minute << ":" << seconds << endl;
    }

    void setHour(int hour)
    {
        this->hour = hour;
    }
    void setMinute(int minute)
    {
        this->minute = minute;
    }
    void setSeconds(int seconds)
    {
        this->seconds=seconds;
    }

    int menu()
    {
        int choice;
        
        return choice;
    }
};

int main()
{
    int choice,num,hour,minute,second,index=-1;
    cout<<"\nEnter how many times do you want to time : ";
    cin>>num;
    Time *t = new Time[num];
    do
    {
        cout << "\n0.Exit";
        cout << "\n1.Set Time.";
        cout << "\n2.Display Time";
        cout << "\nEnter your choice : ";

        cin >> choice;

        switch(ETime(choice))
        {
            case SET_TIME:
                index++;
                cout<<"\nEnter hour : ";
                cin>>hour;
                cout<<"\nEnter Minute : ";
                cin>>minute;
                cout<<"\nEnter Seconds : ";
                cin>>second;
                t[index].setHour(hour); 
                t[index].setMinute(minute);
                t[index].setSeconds(second);
                break;
            case GET_TIME:
                for(int i=0;i<=index;i++)
                {
                    cout<<"\nHours are : "<<t[i].getHour();
                    cout<<"\nMinutes are : "<<t[i].getMinute();
                    cout<<"\nSeconds are : "<<t[i].getSeconds();
                    //t[i].printTime();
                }
                break;
        }
    } while (choice!=0);

    // Deallocate array of object memory
    delete[] t;
    t =  NULL;   
    return 0;
}