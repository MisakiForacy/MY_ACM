#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
struct info{
    string style,singer;
};
// bool flg;
i64 t, n, cnt, de = 0;
string s1,s2;
vector<info>List;
vector<bool>var;
void dfs(int i);
void solve();
bool cmp(const info &a,const info &b);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        de ++;
        solve();
    }
    return 0;
}
void solve(){
    int maxn = 1;
    cin >> n;
    // if(de == 1 && n == 6)flg = true;
    // if(de == 183 && flg)cout << n << ":"; 
    List.clear();
    vla.resize(n,1);
    for(int i = 0; i < n; i ++){
        cin >> s1 >> s2;
        List.push_back({s1,s2});
        // if(de == 183 && flg)cout << s1 << ":" << s2 << "<";
    }
    sort(List.begin(),List.end(),cmp);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++)var[j] = 1;
        cnt = 0;
        dfs(i);
        // cout << cnt << endl;
        if(cnt > maxn){
            maxn = cnt;
        }
    }
    cout << n - maxn << endl;
}
void dfs(int i){
    cnt ++;
    var[i] = 0;
    for(int j = 0; j < n; j ++){
        if(var[j] && (List[j].singer == List[i].singer || List[j].style == List[i].style)){
            dfs(j);
            break;
        }
    }
}
bool cmp(const info &a,const info &b){
    if(a.style != b.style)return a.style < b.style;
    return a.singer < b.singer;
}

// 8
// x d
// z nj
// zw i
// zw d
// x mu
// zw nj
// q i
// tt m
