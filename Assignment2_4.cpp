// Q4. Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
// Instead of char[] use string datatype

#include<iostream>
using namespace std;
class Address
{
    private:
        string building;
        string street;
        string city;
        int pin;

    public:
    Address()
    {
        building = "null";
        street = "null";
        city = "null";
        pin =0;
    }

    Address(string building ,string street, string city, int pin)
    {
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }



    void setBuilding(string building)
    {
        this->building = building;
    }

    void setstreet(string buildistreetng)
    {
        this->street = street;
    }

    void setCity(string city)
    {
        this->city=city;
    }

    void setPin(int pin)
    {
        this->pin = pin;
    }

    string getBuilding()
    {
        return building;
    }

    string getStreet()
    {
        return street;
    }

    string getCity()
    {
        return city;
    }

    int getPin()
    {
        return pin;
    }

    void acceptAddress()
    {
        cout<<"\nEnter City : ";
        cin>>city;
        cout<<"\nEnter street : ";
        cin>>street;
        cout<<"\nEnter building : ";
        cin>>building;
        cout<<"\nEnter pin : ";
        cin>>pin;
    }

};

int main()
{
    Address a;
    a.setCity("Kolhapur");
    a.setstreet("Choundeshwari Galli");
    a.setBuilding("Mauli");
    a.setPin(591241);

    cout<<"\nCity : "<<a.getCity();
    cout<<"\nStreet : "<<a.getStreet();
    cout<<"\nBuilding : "<<a.getBuilding();
    cout<<"\nPin : "<<a.getPin();

    return 0;
}