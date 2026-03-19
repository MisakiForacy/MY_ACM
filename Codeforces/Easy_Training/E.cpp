#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    cin >> t;
    while(t --){
        cin >> n;
        if((n-1)%3==0||(n+1)%3==0)cout << "First\n";
        else cout << "Second\n";
    }
}