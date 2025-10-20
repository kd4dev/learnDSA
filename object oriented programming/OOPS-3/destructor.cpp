#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Bike
{
public:
    int tyreSize;
    int engineSize;

    // default constructor
    Bike(int tyreSize, int engineSize)
    {
        this->tyreSize = tyreSize;
        this->engineSize = engineSize;
    }
    ~Bike() {
        cout<<"destructor call hua"<<endl;
    }
};
int main()
{
    Bike tvs(12, 23); // object creation //constructor ko call jayegi
    Bike Honda(23, 34);
    Bike RoyalEnfield(13, 45);
    bool flag=true;
    if(flag==true){
        Bike bmw(45,56);
        cout<<bmw.tyreSize<< " " << bmw.engineSize << endl;
    }
    cout << tvs.tyreSize << " " << tvs.engineSize << endl;
    cout << Honda.tyreSize << " " << Honda.engineSize << endl;
    cout << RoyalEnfield.tyreSize << " " << RoyalEnfield.engineSize << endl;
}
