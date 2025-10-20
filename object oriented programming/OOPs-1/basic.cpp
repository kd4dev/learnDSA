#include<iostream>
using namespace std;
class player{
    public:
    int score;
    int health;
    void showhealth(){
        cout<<"health is : "<<health<<endl;
    }
};

int main(){
    player amit;
    amit.score=90;
    amit.health=100;
    amit.showhealth();
    cout<<amit.score<<endl;
}