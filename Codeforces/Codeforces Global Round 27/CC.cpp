#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    // while (cin >> n){
        vector<int> p;
        p = {5,4,2,3,1,6,7,8};
        int k = 0;
        for (int i=0;i<p.size();i++){
            if (i & 1){
                k |= p[i];
            } else{
                k &= p[i];
            }
        }
        cout << k << '\n';
        // for (int i=1;i<=n;i++){
        //     p.push_back(i);
        // }
        // int Max = 0;
        // do{
        //     int k = 0;
        //     for (int i=0;i<n;i++){
        //         if (i & 1){
        //             k |= p[i];
        //         } else{
        //             k &= p[i];
        //         }
        //     }
        //     Max = max(Max,k);
        // } while (next_permutation(p.begin(),p.end()));
        // sort(p.begin(),p.end());
        // do{
        //     int k = 0;
        //     for (int i=0;i<n;i++){
        //         if (i & 1){
        //             k |= p[i];
        //         } else{
        //             k &= p[i];
        //         }
        //     }
        //     if (k == Max){
        //         for (int i=0;i<n;i++){
        //             cout << p[i] << " \n"[i==n-1];
        //         }
        //     }
        // } while (next_permutation(p.begin(),p.end()));
    // }
}