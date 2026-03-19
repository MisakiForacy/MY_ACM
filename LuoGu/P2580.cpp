#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int P = 13331;
const ull mod = 1e9+7;
ull qpower(int x,int k){
    ull res = 1;
    while (k){
        if (k&1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}
ull get(string s){
    int hash = 0;
    int n = s.length();
    for (int i=0;i<n;i++){
        hash += s[i] * qpower(P,n-i-1);
    }
    return hash;
} 
int main(){
    int n,m;
    string s;
    cin >> n;
    map<ull,int>hash;
    for (int i=0;i<n;i++){
        cin >> s;
        hash[get(s)]++;
    }
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> s;
        if (hash[get(s)]>1){
            cout << "REPEAT\n";
        } else if (hash[get(s)]==1){
            cout << "OK\n";
            hash[get(s)]++;
        } else{
            cout << "WRONG\n";
        }
    }
}