#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int arr[] = {10,9,8,7,4,70,60,50};
    // vector <int> ans;
    int idx=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    priority_queue<int, vector<int>, greater<int>> pq; // minHeap
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k){
            // ans.push_back(pq.top());
            arr[idx++]=pq.top();
            pq.pop();
        }
    }
    while(pq.size()>0){
        // ans.push_back(pq.top());
        arr[idx++]=pq.top();

        pq.pop();        
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}