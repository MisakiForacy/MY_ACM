#include <bits/stdc++.h>
using namespace std;
int s[1005];
void multiply(int n){
    for (int i=1;i<1005;i++){
        s[i] *= n;
    }
    for (int i=1;i<1004;i++){
        int x = s[i] / 10;
        s[i+1] = s[i+1] + x;
        s[i] = s[i] % 10;
    }
}
void print(){
    int len = 1;
    for (int i=1;i<1005;i++){
        if (s[i]) len = i;
    }
    for (int i=len;i>=1;i--){
        cout << s[i];
    }
}
int main(){
    int n;
    cin >> n;
    vector<int>ans;
    if (n<=4){
        cout << n << '\n' << n << '\n';
    } else{
        s[1] = 1;
        int t = 2;
        while ((t*t+t-2)/2<n) t ++;
        int d = (t*t+t-2)/2 - n;
        if (d==1){
            for (int i=3;i<t;i++){
                cout << i << ' ';
                multiply(i);
            }
            cout << t+1 << '\n';
            multiply(t+1);
            print();
        } else{
            for (int i=2;i<=t;i++){
                if (i!=d){
                    cout << i << " \n"[i==t];
                    multiply(i);
                }
            }
            print();
        }
    }
}