#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    ll diff = a[1] - a[0];
    ll ans = n;
    ll cnt = 1;
    for (int i=1;i<n-1;i++){
        if (a[i+1]-a[i]!=diff){
            diff = a[i+1] - a[i];
            ans += (cnt*(cnt+1)) / 2;
            cnt = 1;
        } else{
            cnt ++;
        }
    }
    ans += (cnt*(cnt+1)) / 2;
    cout << ans << '\n';
}

/*
长度n=4的数组
1 2 3 4
要找到该数组的子串，公式为ans =（n+1）* n / 2
这个公式包含了4个一项、3个两项、2个三项、1个四项
假设，我们先把一项的数量提取出来
那么 ans = (n+1) * n / 2 - n
这样的实际意义就是我们只取两项、三项以及四项的数量之和
也就是
(1,2),(2,3),(3,4),(1,2,3),(2,3,4),(1,2,3,4)
也就是 (n-1) * n / 2
我们为什么要这么麻烦去计算从两项开始，而不是直接从一项开始呢？
那是因为，
两项可以直接得到它们之间的差，
从而决定是否能加入到数组中（也就是cnt
*/