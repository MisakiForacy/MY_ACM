#include <iostream>
using namespace std;
typedef long long ll;
typedef double db;
int main(){
    ll m,t,s;
    cin >> m >> t >> s;
    if(t==0)cout << 0;
    else{
        if(s%t==0){
            if(s/t<=m)cout<<m-s/t;
            else cout << 0;
        }
        else{
            if(s/t+1<=m)cout<<m-s/t-1;
            else cout << 0;
        }
    }
}