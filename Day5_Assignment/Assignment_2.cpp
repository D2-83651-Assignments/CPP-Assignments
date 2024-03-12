/*
Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint -> Create class Product and inherit into Book and Tape. Also array should be created of
Product*
*/

#include <iostream>

using namespace std;

class Product
{
    int id;
    string title;
    float price;

public :
    Product(){

        id=0;
        title="No title";
        price = 0.0;
    }

    virtual float calculateDiscount() = 0;

    virtual void acceptProducts()
    {
        cout<<"\n-----------------------";
        cout<<"\n----Product Details----";
        cout<<"\n-----------------------";
        cout<<"\nEnter Id : ";
        cin>>id;
        cout<<"\nEnter Title : ";
        cin>>title;
        cout<<"\nEnter Price : ";
        cin>>price;
    }
    virtual void displayProduct()
    {
        cout<<"\nId : "<<getId();
        cout<<"\nTitle : "<<getTitle();
        cout<<"\nPrice : "<<getPrice();
    }

    void setId(int id)
    {
        this->id=id;
    }

    int getId()
    {
        return id;
    }

    void setTitle(string title)
    {
        this->title=title;
    }

    string getTitle()
    {
        return title;
    }

    void setPrice(float price)
    {
        this->price=price;
    }

    float getPrice()
    {
        return price;
    }
};

class Book : public Product
{
    string author;

public:
    Book()
    {
        author = "";
    }

    void acceptProducts()
    {
        Product::acceptProducts();
        cout<<"\nEnter Author name : ";
        cin>>author;
    }

    void displayProduct()
    {
        Product::displayProduct();
        cout<<"\nAuthor name : "<<author;
        cout<<"\n-----------------------";
    }

    float calculateDiscount()
    { 
        return getPrice()*0.9 ;
    }
};

class Tape : public Product 
{
    string artist;

public :
    void acceptProducts()
    {
        Product::acceptProducts();
        cout<<"\nEnter Artist name : ";
        cin>>artist;
    }

    void displayProduct()
    {
        Product::displayProduct();
        cout<<"\nArtist name : "<<artist;
        cout<<"\n-----------------------";
    }

    float calculateDiscount()
    { 
        return getPrice()*0.95 ;
    }
};

int main()
{
    int choice,number, index=-1,sum=0;
    Product *ptr[3];
    do{
        cout<<"\n0.Exit.";
        cout<<"\n1.Book.";
        cout<<"\n2.Tape.";
        cout<<"\n3.Calculate Discount.";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                cout<<"\nThank you! Visit again.";
                break;
            case 1:
                index++;
                ptr[index] = new Book;
                ptr[index]->acceptProducts();
                break;
            case 2:
                index++;
                ptr[index] = new Tape;
                ptr[index]->acceptProducts();
                break;
            case 3:
            {
                for(int i=0;i<3; i++)
                {
                    cout<<"\n-----------------------";
                    ptr[i]->displayProduct();
                    cout<<"\nDiscount Amount : "<<ptr[i]->calculateDiscount();
                    cout<<"\n-----------------------";
                    sum += ptr[i]->getPrice();
                }
                cout<<"\n-----------------------";
                cout<<"\nTotal Amount : "<<sum;
                cout<<"\n-----------------------";
                break;
            }
            default:
                cout<<"\nWrong choice!!";
                break;            
        }
    }while(choice!=0);

    for(int i=0; i<3; i++)
    {
        delete ptr[i];
        ptr[i] = NULL;
    }
    return 0;
}