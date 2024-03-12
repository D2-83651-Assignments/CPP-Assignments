# include <iostream>

using namespace std;

class Box{

    private:

    int length;
    int width;
    int height;
    int volume;

    public :
    Box(){
        length=0;
        width=0;
        height=0;
        volume = 0;
    }

    void setLength(int length)
    {
        this->length = length;
    }
    void setWidth(int width)
    {
        this->width=width;
    }

    void setHeight(int height)
    {
        this->height = height;
    }

    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    int calculateVolume(int length,int width,int height)
    {
        volume = length * width * height;
        return volume;
    }

    void DisplayVolume()
    {
        cout<<"Volume of Box is : "<< volume<<endl;
    }
    

    int menu()
    {
        int choice;
        cout<<"\n1. Create Box";
        cout<<"\n2. Calculate Volume";
        cout<<"\n3. Display Box";
        cout<<"\nEnter your choice :";
        cin>>choice;
        return choice;
    }

};
int main()
{
    int choice,length,width,height;
    Box b1;
    
    while((choice = b1.menu())!= 0)
    {
        switch (choice)
        {
        case 1:
            cout<<"\nEnter length : ";
            cin>>length;
            cout<<"\nEnter width : ";
            cin>>width;
            cout<<"\nEnter height : ";
            cin>>height;
            b1.setLength(length);
            b1.setWidth(width);
            b1.setHeight(height);
            break;
        case 2:
            b1.calculateVolume(length,width,height);
            break;
        case 3:
            b1.DisplayVolume();
            break;
        default:
            cout<<"You have entered wrong choice!!";
            break;
        }
    }
    

    
    return 0;
}