#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
using namespace std;
typedef long long i64;
typedef double llf;
i64 n,i,maxn;
llf ave,datle,sum,x;
deque<llf>arr;
int main(){
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    arr.pop_front(),arr.pop_back();
    for(i=0;i<n-2;i++){
        sum += arr[i];
    }
    ave = sum / (n-2);
    datle = max((ave - arr[0]), (arr[n-3]-ave));
    cout << fixed << setprecision(2) << ave << " " << datle << endl;
    return 0;
}