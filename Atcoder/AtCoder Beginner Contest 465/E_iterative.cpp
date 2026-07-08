/**
 * E - Digit Circus  — 迭代版 (和你原代码风格一致)
 *
 * 迭代DP的本质: 按位置逐层递推
 *   dp[pos][tight][mod][mask] 表示"处理完前pos位后处于某状态"的方案数
 *   从 dp[pos] 转移到 dp[pos+1]，枚举当前位填什么数字
 *
 * 和DFS的对应关系:
 *   DFS: dfs(pos, tight, mod, mask) = 从该状态出发, 填完剩余位置的方案数
 *   迭代: dp[pos][tight][mod][mask] = 从前pos位走到该状态的方案数
 *   两者方向相反: DFS自顶向下(从0到n), 迭代逐层递推(也从0到n)
 *
 *   最终答案: DFS在pos=n时判断; 迭代在dp[n]中统计
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string N;
    cin >> N;
    int n = N.size();

    // dp[pos][tight][mod][mask]
    // 用两行滚动数组节省内存 (只用上一个pos来算当前pos)
    static LL dp[2][2][3][1024];
    int cur = 0, nxt = 1;

    // 初始化: 空前缀, tight=1, mod=0, mask=0 (还没开始)
    memset(dp, 0, sizeof(dp));
    dp[cur][1][0][0] = 1;

    for (int pos = 0; pos < n; pos++) {
        memset(dp[nxt], 0, sizeof(dp[nxt]));  // 清空下一层
        int digit = N[pos] - '0';

        for (int tight = 0; tight <= 1; tight++) {
            int limit = tight ? digit : 9;
            for (int mod = 0; mod < 3; mod++) {
                for (int mask = 0; mask < (1 << 10); mask++) {
                    LL val = dp[cur][tight][mod][mask];
                    if (val == 0) continue;  // 剪枝: 不可达状态跳过

                    for (int d = 0; d <= limit; d++) {
                        int nt = tight && (d == limit);
                        int nm = (mod + d) % 3;
                        int nma = (mask == 0 && d == 0) ? 0 : (mask | (1 << d));
                        dp[nxt][nt][nm][nma] = (dp[nxt][nt][nm][nma] + val) % MOD;
                    }
                }
            }
        }
        swap(cur, nxt);
    }

    // 统计答案: 在pos=n那一层 (现在在cur)
    LL ans = 0;
    for (int tight = 0; tight <= 1; tight++) {
        for (int mod = 0; mod < 3; mod++) {
            for (int mask = 1; mask < (1 << 10); mask++) {  // mask=0排除(数字0)
                int cond = 0;
                if (mod == 0) cond++;
                if (mask >> 3 & 1) cond++;
                if (popcount((unsigned)mask) == 3) cond++;
                if (cond == 1) {
                    ans = (ans + dp[cur][tight][mod][mask]) % MOD;
                }
            }
        }
    }
    cout << ans << '\n';
}
