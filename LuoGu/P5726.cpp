#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,sum = 0;
    cin >> n;
    vector<int>ar(n);
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    for (int i=1;i<n-1;i++){
        sum += ar[i];
    }
    double ave = 1.0 * sum / (n-2);
    cout << fixed << setprecision(2) << ave << '\n';
}