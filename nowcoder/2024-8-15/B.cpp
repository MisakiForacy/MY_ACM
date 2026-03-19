#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
const int P = 131;

unordered_map<ull,pair<int,int>> mp;
unordered_map<ull,ll> vs;

ll qpower(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

ull Hash(string s){
    ull val = 0;
    int len = s.length();
    for (int i=0;i<len;i++){
        val += int(s[i]) * qpower(P,len-i-1) % mod;
    }
    return val;
}

pair<ll,ll> get_val(string s){
    int f = 0;
    ll val = 0, idx;
    ll w = 0;
    for (int i=0;i<s.length();i++){
        if (s[i]=='.' && !f){
            idx = Hash(s.substr(0,i));
            val += vs[idx];
            f = 1;
        }
        if (s[i]=='.' && s[i+1]=='f'){
            w ++;
            val += 1 * qpower(3,w);
            i += 5;
        } else if (s[i]=='.' && s[i+1]=='s'){
            w ++;
            val += 2 * qpower(3,w);
            i += 6;
        }
    }
    return {idx,val};
}

void f(string ty,ll st,ll val,ll w){
    int l,r;
    int cnt = 0;
    l = r = -1;
    for (int i=0;i<int(ty.size());i++){
        if (l==-1 && ty[i]=='<'){
            l = i;
        } 
        if (ty[i]=='<') cnt ++;
        else if (ty[i]=='>') cnt --;
        if (cnt==1 && ty[i]==','){
            int l1 = l+1, r1 = i, l2 = i+1, r2 = int(ty.size())-1;
            string t1 = ty.substr(l1,r1-l1);
            string t2 = ty.substr(l2,r2-l2);
            ll v1 = val + 1 * qpower(3,w);
            ll v2 = val + 2 * qpower(3,w);
            mp[v1] = {st+l1,r1-l1}, mp[v2] = {st+l2,r2-l2};
            if (int(t1.find("pair"))!=-1){
                f(t1,st+l1,v1,w+1);
            }
            if (int(t2.find("pair"))!=-1){
                f(t2,st+l2,v2,w+1);
            }
        }
    }
}

int main(){
    int n,q;
    cin >> n >> q;
    string name,type;
    unordered_map<ull,string>base;
    for (int i=1;i<=n;i++){
        cin >> type >> name;
        name.erase(name.size()-1);
        ull val = i*100000;
        base[val] = type;
        int len = type.length();
        mp[val] = {0,len};
        vs[Hash(name)] = val;
        if (int(type.find("pair"))!=-1){
            f(type,0,val,1);
        }
    }
    string s;
    for (int i=0;i<q;i++){
        cin >> s;
        ll val,idx;
        if (s.find(".")==-1){
            val = vs[Hash(s)];
            idx = val;
        } else{
            pair<ll,ll> tt;
            val = tt.second;
            idx = tt.first;
        }
        // cout << val << '\n';
        cout << base[idx] << '\n';
        cout << mp[val].first << ' ' << mp[val].second << '\n';
        cout << base[idx].substr(mp[val].first,mp[val].second) << '\n';
    }
}