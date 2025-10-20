#include <iostream>
using namespace std;
class book
{
private:
    string name;
    string Author;
    int price;
    int Number_of_pages;

public:
    // setter
    void setName(string n)
    {
        cout << "name set  kiya jaa rha he" << endl;
        name = n;
    }
    void setPrice(int p)
    {
        cout << "price set ki jaa rahi he" << endl;
        price = p;
    }
    void setNumber_of_pages(int nop)
    {
        cout << "Number_of_pages set ki jaa rahi he" << endl;
        Number_of_pages = nop;
    }

    void setAuthor(string Author){
        cout<<"author set kr rahe eh"<<endl;
        this->Author=Author;
    }

    // getter
    string getName()
    {
        return name;
    }
    int getPrice()
    {
        return price;
    }
    int getNumber_of_pages()
    {
        return Number_of_pages;
    }
    int count(int p)
    {
        if (price < p)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    string getAutohr(){
        return Author;
    }
    bool isBookPresent(string book)
    {
        if (name == book)
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    book harryPotter;
    harryPotter.setName("H");
    harryPotter.setPrice(400);
    harryPotter.setNumber_of_pages(1213);
    cout<<"number of pages in book is:  "<<harryPotter.getNumber_of_pages()<<endl;
    cout<<"price of book is: "<<harryPotter.getPrice()<<endl;
    cout<<"name of book is:"<<harryPotter.getName()<<endl;
    cout<<"book is present or not:"<<harryPotter.isBookPresent("H")<<endl;
    cout<<"price is less than 500 or not:"<<harryPotter.count(500)<<endl;
    harryPotter.setAuthor("kedar");
    cout<<"Author is:"<<harryPotter.getAutohr()<<endl;

}