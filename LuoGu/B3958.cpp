#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
bool res;
i64 n,i,j,cnt,l1,l2;
string s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s1 >> s2;
        l1 = s1.length(), l2 = s2.length();
        cnt = 0,res = 0;
        if(l1==l2){
            for(j=0;j<s1.length();j++){
                if(s1[j]!=s2[j])cnt++;
            }
            if(cnt>1)res = 1;
        }
        else if(l1<l2){
            for(j=0;j<l2;j++){
                if(s1[j] != s2[j]){
                    s1.insert(s1.begin()+j,s2[j]);
                    break;
                }
            }
            if(s1!=s2)res = 1;
        }
        else if(l2<l1){
            for(j=0;j<l1;j++){
                if(s1[j] != s2[j]){
                    s2.insert(s2.begin()+j,s1[j]);
                    break;
                }
            }
            if(s1!=s2)res = 1;
        }
        if(res)cout << "not similar" << endl;
        else cout << "similar" << endl;
    }
    return 0;
}