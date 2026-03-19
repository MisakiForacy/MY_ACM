#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5;
const LL inf = 1e15;

struct node
{
    LL b, c;
    bool operator < (const node&that) const {
        // if (that.c != 0 && c != 0) {
        //     if (b != that.b) {
        //         return b < that.b;
        //     } else {
        //         return c > that.c;
        //     }
        // } else {
        //     if (c != 0) {
        //         return c > that.c;
        //     } else if (that.c != 0) {
        //         return that.c > c;
        //     } else if (c == 0 && that.c == 0) {
        //         return b < that.b;
        //     }
        // }
        if (b != that.b)
            return b < that.b;
        return c > that.c;
    }
};

void solve () {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1, 0);
    vector<node> p(m);
    multiset<LL> st;
    for (int i = 1;i <= n;i ++) cin >> a[i], st.insert(a[i]);
    for (int i = 0;i < m;i ++) cin >> p[i].b;
    for (int i = 0;i < m;i ++) cin >> p[i].c;

    vector<node> A, B;
    for (int i = 0;i < m;i ++) {
        if (p[i].c) A.push_back(p[i]);
        else B.push_back(p[i]);
    }

    sort(all(A)), sort(all(B));

    int cnt = 0;

    for (int i = 0;i < siz(A);i ++) {
        if (st.lower_bound(A[i].b) == st.end()) break;
        LL use = *st.lower_bound(A[i].b);
        st.erase(st.lower_bound(A[i].b));
        use = max(use, A[i].c);
        st.insert(use);
        cnt ++;
    }

    for (int i = 0;i < siz(B);i ++) {
        if (st.lower_bound(B[i].b) == st.end()) break;
        st.erase(st.lower_bound(B[i].b));
        cnt ++;
    }

    cout << cnt << '\n';
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}