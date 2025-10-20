#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"enter your character:";
    cin>>ch;
    int ascii = (int) ch;
    if((90 >= ascii && ascii >= 65) || (122 >= ascii && ascii >=97))
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch =='A' || ch =='E' || ch =='I' || ch =='O' || ch == 'U')
        {
                cout<<"given character is vowel"; 
        }
        else
        {
            cout<<"given character is consonent"; 
        }
    else
    {
        cout<<"character is not a alphabet";
    }
}