#include<iostream>
using namespace std;
int main(){
// int marks[6];
//     for(int i=0;i<=5;i++){
//         cin>>marks[i];
//     }

//     for(int i=0;i<5;i++){
//         if(marks[i]<35){
//             cout<<i<<" ";
//         }
//     }

int n;
cout<<"enter number of students:";
cin>>n;
int marks[n];
cout<<"enter the marks:";
    for(int i=0;i<=(n-1);i++){
        cin>>marks[i];
    }

    for(int i=0;i<(n-1);i++){
        if(marks[i]<35){
            cout<<i<<" ";
        }
    }
}