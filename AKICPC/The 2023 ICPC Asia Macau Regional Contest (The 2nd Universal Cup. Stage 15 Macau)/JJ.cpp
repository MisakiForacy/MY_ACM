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
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> time(n,INT_MAX);
    // time[0]=0;
    
    vector<int> now(n);
    for(auto &i:now) cin>>i;
    queue<int> get;
    get.emplace(0);
    int ans=0;
    queue<int> add;
    while(time[x]==INT_MAX){
    	// cout<<"?";
    	ans++;
    	int g=add.size();
    	int s=get.size();
    	for(;g>0;g--){
    		int f=add.front();
    		add.pop();
    		if(time[(f)%n]==INT_MAX){
    			time[(f)%n]=ans;
    			get.emplace((f)%n);
			}
			add.emplace((f+1)%n);
		}
    	for(;s>0;s--){
    		int f=get.front();
    		get.pop();
    		if(time[(f+now[f])%n]==INT_MAX){
    			time[(f+now[f])%n]=ans;
    			get.emplace((f+now[f])%n);
    			if(time[(f+now[f]+1)%n]==INT_MAX) add.emplace((f+now[f]+1)%n);
			}
		}
	}
	cout<<ans<<"\n";
    return 0;
}
