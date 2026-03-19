#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),cmp);
    double mx = 0;
    double sum = a[0];
    double ans = 0;
    int t = 1;
    mx = sum * sum / t;
    for (int i=1;i<n;i++){
        sum += a[i];
        t ++;
        ans = sum * sum / t;
        if (ans > mx){
            mx = ans;
        } else{
            sum -= a[i];
            t --;
            break;
        }
    }
    cout << fixed << setprecision(8) << sum*sum/t << '\n';
}