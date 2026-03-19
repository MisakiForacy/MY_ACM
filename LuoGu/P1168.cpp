#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>>q1;
    priority_queue<int,vector<int>,less<int>>q2;
    int n,x,mid;
    cin >> n;
    cin >> x;
    mid = x;
    cout << mid << '\n';
    int cnt = 0;
    while (--n){
        cnt ++;
        cin >> x;
        if (x > mid){
            q1.push(x);
        } else{
            q2.push(x);
        }
        if (cnt==2){
            if (q1.size() > q2.size()){
                q2.push(mid);
                mid = q1.top();
                q1.pop();
            } else if (q1.size() < q2.size()){
                q1.push(mid);
                mid = q2.top();
                q2.pop();
            }
            cnt = 0;
            cout << mid << '\n';
        }
    }
}