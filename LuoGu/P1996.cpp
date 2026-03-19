#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    queue<int>q1,q2;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        q1.push(i);
    }
    int cnt = 0;
    while (!q1.empty() || !q2.empty()){
        if (q2.empty()){
            while(!q1.empty()){
                cnt ++;
                if (cnt==m){
                    cnt = 0;
                    cout << q1.front() << ' ';
                    q1.pop();
                } else{
                    q2.push(q1.front());
                    q1.pop();
                }
            }
        }
        if (q1.empty()){
            while(!q2.empty()){
                cnt ++;
                if (cnt==m){
                    cnt = 0;
                    cout << q2.front() << ' ';
                    q2.pop();
                } else{
                    q1.push(q2.front());
                    q2.pop();
                }
            }
        }
        // cout << cnt << '\n';
    }
}