#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

struct node {
    // ok = -1 未提交，ok = 0 未过， ok = 1 过， ok = 2 ?
    // a, 提交次数， b 通过时间
    int id, ok, a, b, c, l, r;
};

void solve () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vector<node> p(m + 1);
        vector<node> posb;
        int A = 0, B = 0;
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            p[j].id = j;
            if (c == '.') {
                p[j].ok = -1;
            } else if (c == '+') {
                p[j].ok = 1;
                scanf("%d/%d", &p[j].a, &p[j].b);
                A += 1;
                B += (p[j].a - 1) * 20 + p[j].b;
            } else if (c == '?') {
                p[j].ok = 2;
                scanf("%d%d", &p[j].a, &p[j].b);
                p[j].l = (p[j].b - p[j].a) * 20 + 240;
                p[j].r = (p[j].b - 1) * 20 + 299;
                p[j].c = p[j].b - p[j].a;
                posb.push_back(p[j]);
            } else if (c == '-') {
                p[j].ok = 0;
                scanf("%d", &p[j].a);
            }
            // printf("%c", c);
        }
        if (A > x || B > y || A + siz(posb) < x || (A == x && B != y)) {
            printf("No\n");
            continue;
        }
        auto print = [&]() -> void {
            printf("Yes\n");
            for (int j = 1;j <= m;j ++) {
                if (p[j].ok == -1) {
                    printf(".\n");
                } else if (p[j].ok == 0) {
                    printf("- %d\n", p[j].a);
                } else if (p[j].ok == 1) {
                    printf("+ %d/%d\n", p[j].a, p[j].b);
                }
            }
        };
        int n_P = x - A, n_T = y - B;
        int M = siz(posb);
        int ok = 0;
        for (int j = 0;j < 1LL << M;j ++) {
            if (__builtin_popcount(j) != n_P) continue;
            LL L = 0, R = 0;
            for (int k = 0;k < M;k ++) {
                if (!(j >> k & 1)) continue;
                L += posb[k].l;
                R += posb[k].r;
            }
            if (L <= n_T && n_T <= R) {
                int need = n_T;
                for (int k = 0;k < M;k ++) {
                    if (!(j >> k & 1)) {
                        p[posb[k].id].ok = 0;
                        p[posb[k].id].a = posb[k].b;
                    } else {
                        p[posb[k].id].ok = 1;
                        need -= posb[k].c * 20 + 240;
                    }
                }
                for (int k = 0;k < M;k ++) {
                    if (j >> k & 1) {
                        if (need / 20 >= posb[k].a) {
                            need -= (posb[k].a - 1) * 20;
                            posb[k].a = posb[k].b;
                        } else {
                            posb[k].a = need / 20 + 1;
                            need -= (posb[k].a - 1) * 20;
                            posb[k].a += posb[k].c;
                        }
                        if (need >= 59) {
                            posb[k].b = 299;
                            need -= 59;
                        } else {
                            posb[k].b = 240 + need;
                            need = 0;
                        }
                        p[posb[k].id].a = posb[k].a;
                        p[posb[k].id].b = posb[k].b;
                    }
                }
                print();
                ok = 1;
                break;
            }
        }
        if (!ok) {
            printf("No\n");
        }
    }
}

int main () {
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}