#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    if (!(cin >> n >> x)) return 0;
    vector<int> a(n), b(n);
    for (int &v : a) cin >> v;
    for (int &v : b) cin >> v;
    
    vector<int> sorted_a = a, sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    
    int max_beauty = 0;
    int j = 0;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        while (j < n && sorted_b[j] < sorted_a[i]) {
            j++;
        }
        if (j > 0) {
            max_beauty++;
            j--;
        }
    }
    
    if (x > max_beauty || x < 0) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    sort(b.begin(), b.end());
    vector<int> result(n);
    int use = 0;
    int target = x;
    
    vector<int> b_used(n, 0);
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        int cnt_b_less = 0;
        for (int j = 0; j < n; ++j) {
            if (!b_used[j] && b[j] < a[i]) {
                cnt_b_less++;
            }
        }
        if (target > 0 && cnt_b_less > 0) {
            for (int j = 0; j < n; ++j) {
                if (!b_used[j] && b[j] < a[i]) {
                    pairs.push_back({a[i], b[j]});
                    b_used[j] = 1;
                    target--;
                    break;
                }
            }
        }
    }
    
    fill(b_used.begin(), b_used.end(), 0);
    for (auto &[ai, bi] : pairs) {
        for (int i = 0; i < n; ++i) {
            if (!b_used[i] && b[i] == bi) {
                result[i] = ai;
                b_used[i] = 1;
                break;
            }
        }
    }
    
    vector<int> remaining;
    for (int i = 0; i < n; ++i) {
        if (!b_used[i]) remaining.push_back(b[i]);
    }
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (result[i] == 0) {
            result[i] = remaining[idx++];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << result[i];
    }
    cout << "\n";
    
    return 0;
}