#include <iostream>
using namespace std;

class vehicle
{
public:
    int tyre_size;
    int engine_size;
    int lights;
    string company_name; 
    vehicle(){
        cout<<"vehicle ka constructor"<<endl; 
    }

    void show_company(){
        cout<<company_name<<endl;
    }
};
class car : public vehicle
{ 
public:
    int steering_size;
};
class bike : public vehicle
{
public:
    int handle_size;
    bike(){
        cout<<"bike ka constructor"<<endl;
    }
};

    int main()
    {
        bike honda;
        honda.handle_size=5;
        honda.company_name="HONDA";
        honda.engine_size=10;
        cout<<honda.handle_size<<endl;
        cout<<honda.engine_size<<endl;
        honda.show_company();
    }