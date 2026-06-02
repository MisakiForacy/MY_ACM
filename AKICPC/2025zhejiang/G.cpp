#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct nd1
{
    double l, t;
    bool operator < (const nd1&T) const {
        double cur = 1.0 + l * t / 100;
        double nxt = 1.0 + l * (t + 1) / 100;
        double Tcur = 1.0 + T.l * T.t / 100;
        double Tnxt = 1.0 + T.l * (T.t + 1) / 100;
        return (nxt / cur) < (Tnxt / Tcur);
    }
};

struct nd2
{
    double l, t;
    bool operator < (const nd2&T) const {
        double cur = 1.0 + l * t / 100;
        double nxt = 1.0 + l * (t - 1) / 100;
        double Tcur = 1.0 + T.l * T.t / 100;
        double Tnxt = 1.0 + T.l * (T.t - 1) / 100;
        return (cur / nxt) > (Tcur / Tnxt);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> l(n + 1), t(n + 1);
    for (int i = 1;i <= n;i ++) cin >> l[i];
    priority_queue<nd1> q;
    priority_queue<nd2> p;
    for (int i = 1;i <= n;i ++) q.push({l[i], double(k / n)});
    k %= n;
    while (k --) {
        auto [ll, tt] = q.top();
        q.pop();
        tt += 1;
        q.push({ll, tt});
    }
    priority_queue<nd1> tp;
    while (siz(q)) {
        tp.push(q.top()), p.push({q.top().l, q.top().t});
        q.pop();
    }
    while (siz(tp)) q.push(tp.top()), tp.pop();
    double ans = 1;
    // int cnt = 0;
    auto print = [&]() -> void {
        priority_queue<nd2> view = p;
        while (siz(view)) {
            auto [ll, tt] = view.top();
            view.pop();
            cout << ll << ' ' << tt << '\n';
        }
        cout << '\n';
    };
    while (1) {
        // cout << cnt ++ << '\n';
        auto [l1, t1] = q.top();
        auto [l2, t2] = p.top();
        q.pop();
        // cout << siz(p) << '\n';
        // print();
        while (t2 == 0 && siz(p)) {
            // cout << t2 << '\n';
            tp.push({l2, t2});
            p.pop();
            // [l2, t2] = p.top();
            l2 = p.top().l;
            t2 = p.top().t;
        }
        p.pop();
        while (siz(tp)) {
            p.push({tp.top().l, tp.top().t});
            tp.pop();
        }
        while (siz(p)) {
            auto [ll2, tt2] = p.top();
            p.pop();
            if (ll2 == l1 && tt2 == t1) {
                p.push({ll2, tt2 + 1});
                p.push({l2, t2 - 1});
                while (siz(tp)) {
                    p.push({tp.top().l, tp.top().t});
                    tp.pop();
                }
                break;
            }
            tp.push({ll2, tt2});
        }
        while (siz(q)) {
            auto [ll1, tt1] = q.top();
            q.pop();
            if (ll1 == l2 && tt1 == t2) {
                q.push({ll1, tt1 - 1});
                q.push({l1, t1 + 1});
                while (siz(tp)) {
                    q.push(tp.top());
                    tp.pop();
                }
                break;
            }
            tp.push({ll1, tt1});
        }
        // cout << "ok\n";
        double val = 1;
        while (siz(q)) {
            auto [ll, tt] = q.top();
            q.pop();
            // cout << ll << ' ' << tt << '\n';
            tp.push({ll, tt});
            val *= (1.0 + ll * tt / 100);
        }
        while (siz(tp)) {
            q.push(tp.top());
            tp.pop();
        }
        // cout << val << '\n';
        if (val == ans) break;
        ans = max(ans, val);
    }
    cout << ans << '\n';
}
// nlogm

/*
2
3 5
50 100 50
1+1/2 -> 3/2
1+2/2 -> 4/2
1+3/2 -> 5/2

1+1/1 -> 2/1
1+2/1 -> 3/1
1+3/1 -> 4/1

1+1/100 -> 101/100 -> 1.01
1+2/100 -> 102/100 -> 1.02
10 1000000
1 2 3 4 5 6 7 8 9 10
*/

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}