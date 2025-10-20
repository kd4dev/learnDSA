#include <iostream>
using namespace std;
class  Student{ //user defined data type
public:
    string name;
    int rno;
    float marks;
    Student(string name,int rno,float marks){
        this->name =name;
        this->rno=rno;
        this->marks=marks;
    }
};

int main(){
    Student s("kedar baswade",45,92.6);
    // s.name="kedar baswade";
    // s.rno=45;
    // s.marks=92.6;
    cout<<s.marks;
}