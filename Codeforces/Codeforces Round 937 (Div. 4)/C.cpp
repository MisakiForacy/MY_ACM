#include <bits/stdc++.h>
typedef long long i64;
using namespace std;
const string H[] = {"12","01","02","03","04","05","06","07","08","09","10","11","12"};
i64 t,hh,mm;
string hm,dd;
int main(){
    cin >> t;
    while(t--){
        cin >> hm;
        hh = (hm[0]-'0')*10+(hm[1]-'0');
        mm = (hm[3]-'0')*10+(hm[4]-'0');
        if(hh>=12)dd="PM";
        else dd="AM";
        if(dd=="PM"){
            cout << H[hh-12] << ":" << hm[3] << hm[4] << " " << dd << endl;
        }
        else cout << H[hh] << ":" << hm[3] << hm[4] << " " << dd << endl;
    }
    return 0;
}