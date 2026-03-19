#include <bits/stdc++.h>
typedef long long i64;
using namespace std;
const int zs[] = {10,11,101,111,1001,1011,1101,10001,10011,10101,10111};
i64 t,i,j,nn;
string n;
bool flag;
int main(){
    cin >> t;
    while(t--){
        int nn=0;
        flag = true;
        cin >> n;
        for(i=0;i<n.length();i++){
            if(n[i]=='0')continue;
            else if(n[i]=='1')continue;
            else{flag=false;break;}
        }
        for(i=0;i<n.length();i++){
            nn += (n[i]-'0')*pow(10,n.length()-i-1);
        }
        if(flag)cout << "YES" << endl;
        else{
            int i=0;
            while(i<11 && nn!=1){
                if(nn%zs[i]==0)nn=nn/zs[i];
                else ++i;
            }
            if(i==11)cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}