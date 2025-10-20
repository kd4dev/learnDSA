#include <iostream>
using namespace std;
class a
{
private:
    int a_ka_private;

protected:
    int a_ka_protected;

public:
    int a_ka_public;
    a()
    {
        cout << "a ka constructor call hua" << endl;
    }
};
class b : virtual public a
{
public:
    int b_ka_public;
    b()
    {
        cout << "b ka constructor call hua" << endl;
    }
};
class c : virtual public a
{
public:
    int c_ka_public;
    c()
    {
        cout << "c ka constructor call hua" << endl;
    }
};
class d : public b, public c
{
public:
    int d_ka_public;
    d()
    {
        cout << "d ka constructor call hua" << endl;
    }

    void show(){
        cout<<a_ka_public<<endl;
    }
};


int main()
{

d kedar;
kedar.a_ka_public=10;
kedar.show();

}