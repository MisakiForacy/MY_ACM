/**
 * E - Digit Circus  — 数位DP 教学版
 *
 * 数位DP = DFS + 记忆化
 *
 * 核心概念:
 *   tight (上限标记): 前缀是否还和 N 完全一样
 *     tight=1 → 当前位只能填 0~N[pos]，因为超过就大于 N 了
 *     tight=0 → 当前位可以填 0~9，因为前缀已经小于 N 了
 *
 *   关键优化: tight=0 的状态被大量共享！比如 N=4567，
 *   前缀 "1??" 和 "2??" 后面的状态空间完全一样，只需算一次。
 *
 * 状态:
 *   mod: 数位和 % 3 → 判断条件1 (3的倍数)
 *   mask: 位掩码，bit d=1 表示数字 d 出现过 → 判断条件2 (含3) 和条件3 (恰好3种)
 *   mask==0 表示全是前导零(数字为0)，需在结果排除
 *
 * 复杂度: O(n * 2 * 3 * 1024 * 10) ≈ 3千万，2秒足够
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD = 998244353;

string N;
int n;
LL memo[501][2][3][1024];
// memo[pos][tight][mod][mask]

LL dfs(int pos, bool tight, int mod, int mask) {
    if (pos == n) {
        // 递归基: 所有位处理完毕
        if (mask == 0) return 0;  // 排除数字0 (全前导零)

        int cond = 0;  // 满足几个条件
        if (mod == 0)                cond++;  // 条件1: 是3的倍数
        if (mask >> 3 & 1)          cond++;  // 条件2: 包含数字3
        if (popcount((unsigned)mask) == 3) cond++;  // 条件3: 恰好3种不同数字
        return cond == 1 ? 1 : 0;  // 恰好满足1个条件
    }

    LL &res = memo[pos][tight][mod][mask];
    if (res != -1) return res;  // 记忆化: 算过就直接返回
    res = 0;

    int limit = tight ? (N[pos] - '0') : 9;
    for (int d = 0; d <= limit; d++) {
        // 更新mask: 如果还没开始(mask==0)且d==0 → 保持0 (前导零)
        //          否则 → 把数字d加入mask
        int nmask = (mask == 0 && d == 0) ? 0 : (mask | (1 << d));
        res = (res + dfs(pos + 1,
                         tight && (d == limit),  // 只有之前tight且当前取到上限, 下一位才tight
                         (mod + d) % 3,
                         nmask)) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    n = N.size();
    memset(memo, -1, sizeof(memo));  // -1 表示"未计算过"
    cout << dfs(0, true, 0, 0) << '\n';
}
