#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<int> a(2*n);
        map<int,int> mp1,mp2;
        for (int i=0;i<2*n;i++){
            cin >> a[i];
            if (i<n) mp1[a[i]] ++;
            else mp2[a[i]] ++;
        }
        vector<int> a1,a2;
        for (auto c:mp1){
            if (c.second==2){
                a1.push_back(c.first);
                a1.push_back(c.first);
            }
        }
        for (auto c:mp2){
            if (c.second==2){
                a2.push_back(c.first);
                a2.push_back(c.first);
            }
        }
        if (a1.size()<2*k){
            for (auto c:mp1){
                if (c.second==1){
                    a1.push_back(c.first);
                    a2.push_back(c.first);
                }
                if (a1.size()==2*k) break;
            }
        }
        for (int i=0;i<2*k;i++) cout << a1[i] << " \n"[i==2*k-1];
        for (int i=0;i<2*k;i++) cout << a2[i] << " \n"[i==2*k-1];
    }
}