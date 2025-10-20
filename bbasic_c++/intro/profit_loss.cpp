#include<iostream>
using namespace std;
int main()
{
    float cost_price;
    cout<<"enter cost price:";
    cin>>cost_price;
    float sell_price;
    cout<<"enter selling price:";
    cin>>sell_price;

    if(sell_price>=cost_price) 
    {
        cout<<"you made a profit of,"<<(sell_price-cost_price);
    }

    else if(cost_price>sell_price)
    {
        cout<<"you made a loss of,"<<(cost_price-sell_price);
    }

    else
    {
        cout<<"no profit,no loss";
    }
}