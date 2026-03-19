#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 

ll qpower(ll a,ll k,ll p){
    ll res = 1;
    while (k){
        if (k&1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int sieve[N];
int prime[N];
int Eular(int n){

}