#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n;
int main(){
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d;
        if(a[0]=='y'&&b[0]=='y'&&c=="ding"&&d=="zhen"){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}