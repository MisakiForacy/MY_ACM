#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string ans;
    cin >> n >> m;
    while(m--){
        cin >> ans;
        int num = 0;
        for(int i=0;i<n;i++){
            if(ans[i]=='n')num+=pow(2,n-i-1);
        }
        cout << num+1 << endl;
    }
    return 0;
}