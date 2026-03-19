#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,q,m,k;
    cin>>n>>q>>m>>k;
    vector<string> same(n);
    vector<unsigned long long> yu(250,1);
    // long long mod=131,mmd=1e9+7;
    for(long long i=1;i<250;i++){
        yu[i]=yu[i-1]*131;
        // yu[i]%=mod;
    }
    for(auto &i:same) cin>>i;
    vector<vector<unsigned long long>> hs(n,vector<unsigned long long>(250,0));
    for(int i=0;i<n;i++){
        int p=-1;
        for(long long j=0;j<m;j++){
            if(j%250==0) p++;
            hs[i][p]+=yu[(j%250)]*same[i][j];
            // hs[i][p]%=mmd;
        }
    }
    for(;q>0;q--){
        string s;
        cin>>s;
        vector<unsigned long long> nhs(250,0);
        int p=-1;
        for(long long j=0;j<m;j++){
            if(j%250==0) p++;
            nhs[p]+=yu[(j%250)]*s[j];
            // nhs[p]%=mmd;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int dif=0;
            for(int j=0;j<250&&dif<=k;j++){
                if(hs[i][j]==nhs[j]) continue;
                for(int c=j*250;c<m&&c<(j+1)*250;c++){
                    if(s[c]!=same[i][c]) dif++;
                }
            }
            if(dif<=k) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

/*
6 4 4 1
kaki
kika
manu
nana
tepu
tero
kaka
mana
teri
anan
*/

/*
8 6 7 3
delphis
aduncus
peronii
plumbea
clymene
hectori
griseus
electra
delphis
helpiii
perphii
clumeee
eleelea
ddlpcus
*/