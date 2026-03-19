#include<bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
long long max(long long a,long long b){
    if(a>b){
        return a;
    }
    return b;
}
long long min(long long a,long long b){
    if(a<b){
        return a;
    }
    return b;
}
long long mod=998244353;
long long mod2=1e9+7;
mt19937_64 rnd(time(0)); 
long long pow_mod(long long base, long long exp, int mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
long long inv(long long b, int mod) {
    return pow_mod(b, mod-2, mod);
}
int main(){
    int t;
    cin>>t;
    vector<vector<int>> qq(411,vector<int>(14,0));
    vector<int> sum(411,0);
    for(;t>0;t--){
        int a,b,c;
        cin>>a>>b>>c;
        qq[a][b]++;
        if(qq[a][b]==1){
            if(c<240) cout<<b<<"\n";
            else if(sum[a]<3) cout<<b<<"\n";
            else cout<<0<<"\n";
            sum[a]++;
        }else cout<<0<<"\n";
    }
    return 0;
}