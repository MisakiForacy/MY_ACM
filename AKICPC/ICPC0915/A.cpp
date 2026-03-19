#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        vector<int> a(32);
        for (int i=0;i<32;i++) cin >> a[i];
        int ch = a[0];
        sort(all(a),[&](int a,int b){
            return a > b;
        });
        int idx = find(all(a),ch) - begin(a) + 1;
        if(idx==1){
            cout<<1<<endl;
        }
        else if(idx>=31){
            cout<<32<<endl;
        }
        else if(idx<=32-27){
            cout<<2<<endl;
        }
        else if(idx<=32-13){
            cout<<4<<endl;
        }
        else if(idx<=26){
            cout<<8<<endl;
        }
        else if(idx<=30){
            cout<<16<<endl;
        }
    }
}