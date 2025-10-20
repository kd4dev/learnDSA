#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Bike
{
public:
    int tyreSize;
    int engineSize;


    //default constructor
    Bike (int tyreSize,int engineSize){
        this->tyreSize=tyreSize;
        this->engineSize=engineSize;
    }
};
int main()
{
    Bike tvs(12,23); //object creation //constructor ko call jayegi 
    Bike Honda(23,34);
    Bike RoyalEnfield(13,45);
    cout<<tvs.tyreSize<<" "<<tvs.engineSize<<endl;
    cout<<Honda.tyreSize<<" "<<Honda.engineSize<<endl;
    cout<<RoyalEnfield.tyreSize<<" "<<RoyalEnfield.engineSize<<endl;
}
