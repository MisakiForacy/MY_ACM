#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while (cin >> n >> m){
        int idx = -1;
        vector<int>ar(2*n,0);
        for (int i=0;i<n;i++){
            int mm = m;
            while (mm){
                idx = (idx+1)%(n*2);
                if (!ar[idx]) mm --;
            }
            ar[idx] = 1;
        }
        for (int i=0;i<2*n;i++){
            cout << (ar[i]?"B":"G");
        }
        cout << '\n' << '\n';
    }
}