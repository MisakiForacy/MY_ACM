/*HihoCoder 1636 : Pangu and Stones　区间DP
 *
 * 【题意】：给出ｎ堆石子，每堆石子的数量为ａ[i],给出l,r，表示每进行一次合并，最少合并连续的l堆，最多合并连续r堆。
 * 问：最后石子合并为１堆时所需的花费。花费：合并的石子的数量。
 *
 *
 * 【分析】：很明显是个区间dp的经典问题，只不过是在这加了一个花费和堆的数量限制。
 * dp[st][ed][k]:区间[st,ed]分成k堆的花费。
 * 初始化：dp[st][st][1]=0;
 * 由于最后的k==1，因此在划分区间[st,ed]的时候，每次将其划分成1,k-1块。
 * 转移方程：dp[st][ed][k]=min(dp[st][ed][k],dp[st][mid][k-1]+dp[mid+1][ed][1]);
 *
 * 上述的转移方程是对于区间[st,ed]未加堆的限制下的之前的花费；
 *
 * 枚举堆的数量k-->[l-1,r-1]，计算区间[st,ed]合并为１堆时的花费。
 *
 * 转移方程为:dp[st][ed][1] = min(dp[st][ed][1],dp[st][mid][k] + dp[mid + 1][ed][1] + sum[ed] - sum[st - 1]);
 *
 *
 * [tricks]:
 * 注意区间DP角标。
 *
 * [时间复杂度]：n^4
 *
 * */

#include <bits/stdc++.h>
 
#define  ll long long
 
using namespace std;
 
void scan() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
const int maxn = 110;
const int INF = 0x3f3f3f3f;
int dp[maxn][maxn][maxn], a[maxn], sum[maxn];
int n, l, r;
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scan();
    while (cin >> n >> l >> r) {
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            dp[i][i][1] = 0;;
        }
        for (int len = 2; len <= n; len++) {
            for (int st = 1; st + len - 1 <= n; st++) {
                int ed = st + len - 1;
                for (int k = 2; k <= min(len, r); k++) {
                    for (int mid = st + k - 2; mid < ed; mid++) {
                        dp[st][ed][k] = min(dp[st][ed][k], dp[st][mid][k - 1] + dp[mid + 1][ed][1]);
                    }
                }
 
                for (int k = l - 1; k <= r - 1; k++) {
                    for (int mid = st + k - 1; mid < ed; mid++) {
                        dp[st][ed][1] = min(dp[st][ed][1], dp[st][mid][k] + dp[mid + 1][ed][1] + sum[ed] - sum[st - 1]);
                    }
                }
            }
        }
 
        cout << (dp[1][n][1] == INF ? 0 : dp[1][n][1]) << endl;
    }
 
    return 0;
}