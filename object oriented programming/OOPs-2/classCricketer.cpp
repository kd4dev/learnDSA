#include <iostream>
#include <vector>
using namespace std;

class Cricketer {
public:
    string name; 
    int age;
    int noOfTestMatches;
    int avgRuns;
};

int main() {
    Cricketer* virat = new Cricketer();
    virat->name = "Virat";
    virat->age = 30;
    virat->noOfTestMatches = 100;
    virat->avgRuns = 80;

    Cricketer* dhoni = new Cricketer();
    dhoni->name = "Dhoni";
    dhoni->age = 40;
    dhoni->noOfTestMatches = 90;
    dhoni->avgRuns = 50;

    vector<Cricketer*> cricketers;
    cricketers.push_back(virat);
    cricketers.push_back(dhoni);

    for (int i = 0; i < 2; i++) {
        Cricketer* cricketer = new Cricketer();
        cout << "Enter name: ";
        cin >> cricketer->name;
        cout << "Enter age: ";
        cin >> cricketer->age;
        cout << "Enter number of test matches: ";
        cin >> cricketer->noOfTestMatches;
        cout << "Enter average runs: ";
        cin >> cricketer->avgRuns;
        cricketers.push_back(cricketer);
    }

    for (int i = 0; i < cricketers.size(); i++) {
        cout << "Name: " << cricketers[i]->name << endl;
        cout << "Age: " << cricketers[i]->age << endl;
        cout << "Number of Test Matches: " << cricketers[i]->noOfTestMatches << endl;
        cout << "Average Runs: " << cricketers[i]->avgRuns << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < cricketers.size(); i++) {
        delete cricketers[i];
    }

    return 0;
}