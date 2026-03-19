#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << fixed << setprecision(3);
    int n,k,m;
    cin >> n >> k >> m;
    vector<double> ave(n);
    vector<double> num(k);
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++){
            cin >> num[j];
        }
        sort(num.begin(),num.end());
            double sum = 0;
            for (int i=1;i<k-1;i++){
                sum += num[i];
            }
            ave[i] = 1.0 * sum / (k-2);
    }
    sort(ave.begin(),ave.end());
    for (int i=n-m;i<n;i++){
        cout << ave[i] << " \n"[i==n-1];
    }
}