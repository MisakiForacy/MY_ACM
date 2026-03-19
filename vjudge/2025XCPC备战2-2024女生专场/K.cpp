#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cerr << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

struct node
{
    string name;
    int a1, a2, a3, b1, b2, b3;
    int a4, b4;
    int s1, s2;
};

LL n, m, pp, qq;
LL x1_, x2_, y1_, y2_;
int A[3], B[3];
string cc = "crazyzhk";
vector<node> p;

node make_node(string name, int a1, int a2, int a3, int b1, int b2, int b3) {
    node res;
    res.name = name;
    res.a1 = a1, res.a2 = a2, res.a3 = a3;
    res.b1 = b1, res.b2 = b2, res.b3 = b3;
    res.a4 = res.b4 = res.s1 = res.s2 = 0;
    return res;
}

void cal1() {
    for (auto &v : p) {
        v.a4 = v.a1 + v.a2 + v.a3;
        v.b4 = v.b1 + v.b2 + v.b3;
    }
}

LL cal2() {
    cal1();
    vector<int> use1(n, 0);
    vector<int> use2(n, 0);
    vector<int> A1, B1;
    for (int i = 0;i < n;i ++) A1.push_back(p[i].a1);
    for (int i = 0;i < n;i ++) B1.push_back(p[i].b1);
    sort(all(A1));
    sort(all(B1));
    sort(all(p), [&](node x, node y) {
        if (x.a4 != y.a4) return x.a4 > y.a4;
        if (x.a1 != y.a1) return x.a1 > y.a1;
        return x.name < y.name;
    });
    for (int i = 0;i < 3;i ++) {
        int need = A[i];
        for (int j = 0;j < n;j ++) {
            if (!use1[j]) {
                int rk = n - (upper_bound(all(A1), p[j].a1) - A1.begin());
                if (rk < B[i]) {
                    need --;
                    use1[j] = 1;
                    p[j].s1 = (3 - i) * 5;
                }
                if (need == 0) break;
            }
        }
    }
    sort(all(p), [&](node x, node y) {
        if (x.b4 != y.b4) return x.b4 > y.b4;
        if (x.b1 != y.b1) return x.b1 > y.b1;
        return x.name < y.name;
    });
    for (int i = 0;i < 3;i ++) {
        int need = A[i];
        for (int j = 0;j < n;j ++) {
            if (!use2[j]) {
                int rk = n - (upper_bound(all(B1), p[j].b1) - B1.begin());
                if (rk < B[i]) {
                    need --;
                    use2[j] = 1;
                    p[j].s2 = (3 - i) * 5;
                }
                if (need == 0) break;
            }
        }
    }
    sort(all(p), [&](node x, node y) {
        if (x.s1 + x.s2 != y.s1 + y.s2) return x.s1 + x.s2 > y.s1 + y.s2;
        if (x.a4 + x.b4 != y.a4 + y.b4) return x.a4 + x.b4 > y.a4 + y.b4;
        if (x.a1 + x.b1 != y.a1 + y.b1) return x.a1 + x.b1 > y.a1 + y.b1;
        return x.name < y.name;
    });
    int ok = 0;
    for (int i = 0;i < m;i ++) {
        if (p[i].name == cc)
            ok = 1;
    }
    if (ok) {
        return (x2_ - x1_) * pp + (y2_ - y1_) * qq;
    } else {
        return inf;
    }
}

void fxy_ac() {
    cin >> n;
    p.clear();
    A[0] = n * 0.15, A[1] = n * 0.25, A[2] = n * 0.35;
    B[0] = n * 0.25, B[1] = n * 0.45, B[2] = n * 0.75;
    for (int i = 0;i < n;i ++) {
        string name;
        int a1, a2, a3, b1, b2, b3;
        cin >> name >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
        p.push_back(make_node(name, a1, a2, a3, b1, b2, b3));
        if (name == cc) {
            x1_ = a1;
            y1_ = b1;
        }
    }
    cin >> m >> pp >> qq;
    cal1();
    LL Min = inf;
    for (x2_ = x1_;x2_ <= 100;x2_ ++) {
        for (y2_ = y1_;y2_ <= 100;y2_ ++) {
            for (int i = 0;i < n;i ++) {
                if (cc == p[i].name) {
                    p[i].a1 = x2_;
                    p[i].b1 = y2_;
                }
            }
            LL val = cal2();
            Min = min(Min, val);
        }
    }
    if (Min == inf) {
        cout << "Surely next time\n";
    } else {
        cout << Min << '\n';
    }
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}