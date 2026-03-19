#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin >> a;
    getchar();
    getline(cin,b);
    int ok1,ok2;
    ok1 = ok2 = 1;
    for (int i=0;i<a.length();i++){
        if (!isdigit(a[i])){
            ok1 = 0;
        }
    }
    if (ok1 && !(0<stoi(a)&&stoi(a)<=1000)){
        ok1 = 0;
    }
    for (int i=0;i<b.length();i++){
        if (!isdigit(b[i])){
            ok2 = 0;
        }
    }
    if (ok2 && !(0<stoi(b)&&stoi(b)<=1000)){
        ok2 = 0;
    }
    string c;
    if (ok1 && ok2){
        c = to_string(stoi(a) + stoi(b));
    } else{
        c = "?";
    }
    if (ok1){
        a = to_string(stoi(a));
    }
    else{
        a = "?";
    }
    if (ok2){
        b = to_string(stoi(b));
    } else{
        b = "?";
    }
    cout << a << " + " << b << " = " << c << '\n';
}