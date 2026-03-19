#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>>pq;
int main(){
    int n,x,sum = 0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        pq.push(x);
    }
    while (1){
        int a = pq.top();
        pq.pop();
        if (pq.empty()){
            break;
        }
        int b = pq.top();
        pq.pop();
        int c = a + b;
        sum += c;
        pq.push(c);
    }
    cout << sum << '\n';
}