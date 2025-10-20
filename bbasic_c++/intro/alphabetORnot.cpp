#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"enter your character:";
    cin>>ch;
    int ascii=(int) ch;
    if((90 >= ascii && ascii>= 65) || (122 >= ascii && ascii >= 97))
    {
        cout<<"it is a alphabet";
    }
    else 
    {
        cout<<"it is not a alphabet";
    }
}