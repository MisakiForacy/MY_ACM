#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define N 100000
#define INF 0x3f3f3f3f
#define FOR(i,x,y,z) for(ll (i)=(x);(i)!=(y);(i)+=(z))
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<bool>res;
    FOR(i,0,T,1){
        ll n,q;//n串长，q操作次数
        string s,t;
        vector<ll> diff;
        bool o,flag = true;
        ll p;
        char c;
        cin >> n >> q;
        cin >> s >> t;
        FOR(i,0,n,1){
            if(t[i]!=s[i]){
                flag = false;
                diff.push_back(i);
            }
        }
        res.push_back(flag);
        FOR(i,0,q,1){
            flag = true;
            cin >> o >> p >> c;
            auto ff = find(diff.begin(),diff.end(),p-1);
            if(ff != diff.end() || diff.size()==0){     //在数组diff中找到匹配项
                if(diff.size()!=0)diff.erase(ff);
                if(o)t[p-1] = c;
                else s[p-1] = c;
                if(t[p-1]!=s[p-1]){
                    flag = false;
                    diff.push_back(p-1);
                }
            }
            res.push_back(flag);
        }
    }
    for(vector<bool>::iterator it=res.begin();it!=res.end();it++){
        cout << (*it?"Yes":"No") << endl;
    }
    return 0;
}