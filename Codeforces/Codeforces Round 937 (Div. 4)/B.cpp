#include <bits/stdc++.h>
typedef long long i64;
using namespace std;
i64 i,j,t,n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(i=0;i<n*2;i++){
            for(j=0;j<n*2;j++){
                if(i/2%2==0 && j/2%2==0)cout<<"#";
                else if(i/2%2==1 && j/2%2==0)cout<<".";
                else if(i/2%2==0 && j/2%2==1)cout<<".";
                else cout<<"#";
            }
            cout << endl; 
        }
    }
    return 0;
}