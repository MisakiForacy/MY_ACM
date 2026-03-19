#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        cout << (n%(m+1)?"Grass\n":"Rabbit\n");
    }
}