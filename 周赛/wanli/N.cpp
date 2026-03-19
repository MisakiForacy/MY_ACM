#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,i,j;
    string str;
    ll y;
    cin >> n;
    while(n--){
        y = 0;
        cin >> str;
        for(i=0;i<str.length();i++){
            if(isdigit(str[i]))break;
        }
        for(j=i-1;j>-1;j--){
            y += (str[j]-'A'+1) * pow(26,i-j-1);
        }
        cout << y << " " << str.substr(i) << endl;
    }
}