# Codeforces Round 961 (Div. 2)
### A. Diagonals
* 题意：在$n*n$的矩阵上放$k$个物品，问最少会占用多少条对角线
* 画图即可，例如n等于3，那么其每个对角线可以存放的个数为  
  1 2 3 2 1，要让占用的对角线最少，从中间往两边取即可
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (!k){
            cout << 0 << '\n';
        } else{
            if (k <= n){
                cout << 1 << '\n';
            } else{
                k -= n;
                int cnt = 1;
                for (int i=n-1;i>=1;i--){
                    k -= i;
                    cnt ++;
                    if (k <= 0){
                        break;
                    }
                    k -= i;
                    cnt ++;
                    if (k <= 0){
                        break;
                    }
                }
                cout << cnt << '\n';
            }
        }
    }
}
~~~
### B1. Bouquet (Easy Version)
* 题意：有n个数，从中取任意个数，使得任意两个数之间的差不大于1，且总和小于等于m
* 由于n的数据范围为2e5，所以可以使用相对暴力的解法，首先对n个数进行排序，然后对排序后的数列计算前缀和，最后用双指针去计算区间和，时该区间中任意两个数之间的差不大于1，且总和小于等于m
* 使用前缀和可以使计算区间和的复杂度降为$O(1)$，$sum=pre_{hi}-pre_{lo-1}$
* 维护双指针的条件:
* 1) 高指针指向的值与低指针指向的值之间的差小于等于1
* 2) $pre_{hi}-pre_{lo-1}<=m$
* 3) 滑动窗口？
* 开long long
~~~cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n, m;
        cin >> n >> m;
        vector<ll>ar(n+1),pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar.begin(),ar.end());
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + ar[i];
        }
        ll lo = 1,hi = 1, mx = 0;
        for (hi = 1; hi <= n;hi ++){
            while (ar[hi] - ar[lo] > 1) lo ++;
            while (pre[hi] - pre[lo-1] > m) lo ++;
            mx = max(mx,pre[hi]-pre[lo-1]);
        }
        cout << mx << '\n';
    }
}
~~~

### B2. Bouquet (Hard Version)
* 题意同上，唯一不同在于是通过输入一个数组记录每个数的数量
* 由于数量会很大，所以这题再用暴力是行不通的
* 设$h1$为取的$k$数量，$h2$为取的$k+1$的数量，$C_k$为$k$自身的数量
* 若同时存在k和k+1，先尽可能多的取k，取的数量不得超过k自身的数量，也不得超过m可以存放的数量  
  $\therefore h1=min(C_k,\lfloor \frac{m}{k} \rfloor)$，
  取完$k$之后，我们要在剩余的$m$中尽可能多的去取$k+1$  
  $\therefore h2=min(C_{k+1},\lfloor \frac{m-h1k}{k+1} \rfloor)$
  在得到$h1$和$h2$之后，$m-h1k-h2(k+1)$可能会存在余数，欲使总和最大，那么我们就要使余数最小，使余数减小的方法就是尽可能多的将$k$替换成$k+1$，而可替换的数量为$n=min(h1,C_{k+1}-h2)$，
  我们不得不考虑一种情况，就是如果当替换完$n$个$k$为$k+1$之后，其总和有可能会大于$m$，所以我们还得加一层比较$n=min(n,m)$。最后，取$n+h1k+h2(k+1)$的最大值
* 若存在$k$，不存在$k+1$，我们只需要知道$h1$即可，$h1=min(C_k,\lfloor \frac{m}{k} \rfloor)$，取$h1k$的最大值
~~~cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,m,ans = 0;
        cin >> n >> m;
        vector<ll>a(n),p(n);
        map<ll,ll>mp;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> p[i], mp[a[i]] = p[i];
        for (auto [k,v]:mp){
            ll mm = m;
            if (mp.count(k+1)){
                ll h1 = min(v,mm / k);
                ll h2 = min(mp[k+1],((mm - h1 * k) / (k+1)));
                ans = max(ans,min(mm,min(h1,mp[k+1]-h2) + h1 * k + h2 * (k+1)));
            } else{
                ans = max(ans,k * min(mm / k,v));
            }
        }
        cout << ans << '\n';
    }
}
~~~
### C. Squaring
* 题意：给定一个无序数组，可以对数组中任意一个数进行平方操作，直至使数组变成递增
* 首先判断始终无法满足递增的情况，不难发现如果数组中存在1且小于前面的数是无法通过平方满足递增的情况的
* 对一个数多次进行平方操作不仅会TLE还会超出int_64的范围
* 我们可以记录前一个数的次方数，如果前一个数的cnt次方大于后一个数，那么就对后一个数的次方数++
~~~cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, ok = 1;
        cin >> n;
        vector<ll>ar(n+1,1);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i] == 1 && ar[i-1] > ar[i]) ok = 0;
        }
        if (ok){
            ll cnt = 0, now = 1, sum = 0;
            for (int i=1;i<n;i++){
                now = ar[i];
                while (now < ar[i+1] && cnt){
                    now *= now;
                    cnt --;
                }
                ll suf = ar[i+1];
                while (now > suf){
                    suf *= suf;
                    cnt ++;
                }
                sum += cnt;
            }
            cout << sum << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}
~~~