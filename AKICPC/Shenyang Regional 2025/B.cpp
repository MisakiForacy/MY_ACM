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
    for(;t>0;t--){
        long long n,m,a,b,ans=0;
        cin>>n>>m>>a>>b;
        vector<int> ech(n*m,0);
        int zero=0;
        for(int i=0;i<n*m;i++){
            int lin;
            cin>>lin;
            if(lin==0) zero++;
            else ech[lin-1]++;
        }
        sort(ech.rbegin(),ech.rend());
        ans=min(zero*b+(n*m-zero-ech[0])*a,a*(n*m-zero));
        for(int i=1;i<n*m;i++){
            long long hua=a*ech[i],ca=zero*b+b*ech[i]*i;
            if(hua>ca){
                ans-=hua-ca;
            }else break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}