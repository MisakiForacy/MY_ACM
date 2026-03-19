#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 n, i;
string num;
bool cheak(string n){
    for(auto s:n){
        if(!(s == '4' || s == '7'))return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(i = 4; i <= n; i ++){
        if(n % i == 0){
            num = to_string(i);
            if(cheak(num)){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}