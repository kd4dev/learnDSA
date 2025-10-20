#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Bike
{
public:
    static int noOfBikes; //this belongs to class   
    int tyreSize;
    int engineSize;

    // default constructor
    Bike(int tyreSize, int engineSize)
    {
        this->tyreSize = tyreSize;
        this->engineSize = engineSize;
    }
    static void increaseNoOfBikes(){
        noOfBikes++;
    }
};
int Bike::noOfBikes=10;

int main()
{
    Bike tvs(12, 23); // object creation //constructor ko call jayegi
    Bike Honda(23, 34);
    cout<<tvs.noOfBikes<<endl;
    Bike::increaseNoOfBikes();
    cout<<tvs.noOfBikes<<endl;
    cout << tvs.tyreSize << " " << tvs.engineSize << endl;
    cout << Honda.tyreSize << " " << Honda.engineSize << endl;

}
