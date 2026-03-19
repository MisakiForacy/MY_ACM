#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct haha{
    string a,b,d;
    int t;
};

int n;
vector<int>ans;
map<string,int>nu;
vector<haha>rul;

ll qpower(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

bool check(){
    int len = rul.size();
    for (int i=0;i<len;i++){
        if (((nu[rul[i].a]+nu[rul[i].b])/qpower((n-1),rul[i].t))%(n-1)!=nu[rul[i].d]){
            return 0;
        }
    }
    return 1;
}

int main(){
    string s;
    cin >> n;
    vector<string>col(n), row(n);
    map<pair<string,string>,string>mp;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> s;
            if (i==0 && j!=0){
                col[j] = s;
            }
            if (j==0 && i!=0){
                row[i] = s;
            }
            if (i!=0 && j!=0){
                mp[{col[j],row[i]}] = s;
            }
        }
    }
    int ok = 0;
    ans.resize(n+1);
    for (int i=0;i<n;i++){
        ans[i+1] = i;
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            string str = mp[{col[j],row[i]}];
            int len = str.length();
            for (int k=0;k<len;k++){
                haha node;
                node.a = col[j], node.b = row[i], node.d = str[len-k-1], node.t = k;
                rul.push_back(node);
            }
        }
    }
    do{
        for (int i=1;i<n;i++){
            nu[col[i]] = ans[i]; 
        }
        if (check()){
            ok = 1;
            break;
        }
    } while (next_permutation(ans.begin(),ans.end()));

    if (!ok){
        cout << "ERROR!\n";
    } else{
        for (int i=1;i<n;i++){
            cout << col[i] << '=' << nu[col[i]] << " \n"[i==n-1];
        }
        cout << n-1 << '\n';
    }
}