#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string gets(ll s){
    if (s < 1200){
        return "Newbie";
    } else if (s < 1400){
        return "Pupil";
    } else if (s < 1600){
        return "Specialist";
    } else if (s < 1900){
        return "Expert";
    } else if (s < 2100){
        return "Candidate master";
    } else if (s < 2300){
        return "Master";
    } else if (s < 2400){
        return "International master";
    } else if (s < 2600){
        return "Grandmaster";
    } else if (s < 3000){
        return "International grandmaster";
    } else{
        return "Legendary grandmaster";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n,k,ch;
        cin >> n >> k;
        for (int i=0;i<n;i++){
            cin >> ch;
            if (gets(k) != gets(k + ch)){
                cout << gets(k) << " -> " << gets(k + ch) << '\n';
            }
            k += ch;
        }
        cout << gets(k) << '\n';
    }
}