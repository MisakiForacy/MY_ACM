#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool flag = true;
    while(scanf("%d",&n)!=EOF){
        vector<int>arr(n);
        cin >> arr[0];
        for(int i=1;i<n;i++){
            cin >> arr[i];
            if(arr[i]>arr[i-1]){
                flag = false;
            }
        }
        if(flag){
            cout << 0 << endl;
        }
        else{
            if(arr[0]==n && arr[n-1]!=1){
                cout << 1 << endl;
            }
            else if(arr[n-1]==1 && arr[n-1]!=n){
                cout << 1 << endl;
            }
            else if(arr[0]==1 && arr[n-1]==n){
                cout << 3 << endl;
            }
            else{
                cout << 2 << endl;
            }
        }
    }
    return 0;
}