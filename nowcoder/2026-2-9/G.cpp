#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct Entry {
    int g;
    LL prod;
    LL num;
};

unordered_map<LL, int> memo;
LL powd[10][19];
int cnt[10];

LL digit_prod(LL n) {
    if (n == 0) return 0;
    LL prod = 1;
    while (n > 0) {
        prod *= (n % 10);
        n /= 10;
    }
    return prod;
}

int g_value(LL n) {
    auto it = memo.find(n);
    if (it != memo.end()) return it->second;
    if (n < 10) return memo[n] = 0;
    LL p = digit_prod(n);
    if (p == n) return memo[n] = 0;
    return memo[n] = 1 + g_value(p);
}

LL build_number() {
    LL num = 0;
    for (int d = 2; d <= 9; ++d) {
        for (int i = 0; i < cnt[d]; ++i) {
            num = num * 10 + d;
        }
    }
    return num;
}

void dfs(int d, int remaining, LL prod, unordered_map<LL, Entry> &best_by_prod) {
    if (d == 10) {
        if (remaining == 0) {
            LL num = build_number();
            int gv = 1 + g_value(prod);
            auto it = best_by_prod.find(prod);
            if (it == best_by_prod.end() || num < it->second.num) {
                best_by_prod[prod] = {gv, prod, num};
            }
        }
        return;
    }
    for (int c = 0; c <= remaining; ++c) {
        cnt[d] = c;
        LL new_prod = prod * powd[d][c];
        dfs(d + 1, remaining - c, new_prod, best_by_prod);
    }
    cnt[d] = 0;
}

void solve() {
    for (int d = 2; d <= 9; ++d) {
        powd[d][0] = 1;
        for (int i = 1; i <= 18; ++i) powd[d][i] = powd[d][i - 1] * d;
    }

    unordered_map<LL, Entry> best_by_prod;
    for (int len = 2; len <= 18; ++len) {
        dfs(2, len, 1, best_by_prod);
    }

    vector<Entry> entries;
    entries.reserve(best_by_prod.size());
    for (const auto &kv : best_by_prod) entries.push_back(kv.second);

    int g_max = -1;
    for (const auto &e : entries) g_max = max(g_max, e.g);

    vector<Entry> max_entries;
    for (const auto &e : entries) if (e.g == g_max) max_entries.push_back(e);

    Entry a{}, b{};
    if (max_entries.size() >= 2) {
        a = max_entries[0];
        b = max_entries[1];
    } else {
        a = max_entries[0];
        b.g = -1;
        for (const auto &e : entries) {
            if (e.prod == a.prod) continue;
            if (e.g > b.g) b = e;
        }
    }

    cout << a.num << ' ' << b.num << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
