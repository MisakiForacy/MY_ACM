#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        priority_queue<int> q;
        for (int i=0;i<n;i++){
            cin >> a[i];
            q.push(a[i]);
        }
        int k = n-1,ok = 1;
        while (q.size()>1){
            int n1 = q.top(); q.pop();
            int n2 = q.top(); q.pop();
            int n3 = a[k--];
            int n4 = a[k--];
            if (max(n1,n2)!=max(n3,n4) || min(n1,n2)!=min(n3,n4)){
                ok = 0;
            }
        }
        if (!q.empty()){
            if (q.top()!=a[0]){
                ok = 0;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}