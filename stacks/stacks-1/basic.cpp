#include <iostream>
#include<stack>
using namespace std;
int main() {
    stack<int>st;
    cout<<st.size()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    // while(st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    //we will use extra stack
    stack<int>temp;
    while (st.size()>0)
    {
        cout<<st.top()<<endl;
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        cout<<temp.top()<<endl;
        st.push(temp.top());
        temp.pop();
    }
    cout<<st.top()<<endl;
    
}