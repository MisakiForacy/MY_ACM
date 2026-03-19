#include <bits/stdc++.h>
using namespace std;

class FastScanner {
public:
    static constexpr size_t BUFSIZE = 1 << 20;

    FastScanner() : idx_(0), size_(0) {}

    template <typename T>
    bool readInt(T &out) {
        char c;
        T sign = 1;
        T val = 0;

        c = nextChar();
        if (!c) return false;

        while (c != '-' && (c < '0' || c > '9')) {
            c = nextChar();
            if (!c) return false;
        }

        if (c == '-') {
            sign = -1;
            c = nextChar();
        }

        for (; c >= '0' && c <= '9'; c = nextChar()) {
            val = val * 10 + (c - '0');
        }

        out = val * sign;
        return true;
    }

private:
    char buffer_[BUFSIZE];
    size_t idx_, size_;

    char nextChar() {
        if (idx_ >= size_) {
            size_ = fread(buffer_, 1, BUFSIZE, stdin);
            idx_ = 0;
            if (size_ == 0) return 0;
        }
        return buffer_[idx_++];
    }
};

struct Triple {
    int t;
    int a;
    int b;
};

struct Node {
    vector<int> T;
    vector<int> preA;
    vector<int> sufB;
};

class SegTree {
public:
    explicit SegTree(int n = 0) { init(n); }

    void init(int n) {
        n_ = n;
        tree_.clear();
        tree_.resize((n_ << 2) + 5);
    }

    void build(const vector<int> &a, const vector<int> &b) {
        buildImpl(1, 1, n_, a, b);
    }

    long long rangeQuery(int ql, int qr, long long d) const {
        return queryImpl(1, 1, n_, ql, qr, d);
    }

private:
    static constexpr long long NEG = -(1LL << 60);

    int n_ = 0;
    vector<Node> tree_;

    static inline long long evalNode(const Node &nd, long long d) {
        const int m = static_cast<int>(nd.T.size());
        const int pos = static_cast<int>(lower_bound(nd.T.begin(), nd.T.end(), d) - nd.T.begin());

        long long bestA = NEG;
        long long bestB = NEG;

        if (pos > 0) bestA = nd.preA[pos - 1];
        if (pos < m) bestB = nd.sufB[pos];

        long long res = bestA;
        if (bestB != NEG) res = max(res, d + bestB);
        return res;
    }

    vector<Triple> buildImpl(int idx, int l, int r, const vector<int> &a, const vector<int> &b) {
        if (l == r) {
            vector<Triple> cur(1);
            cur[0] = {a[l] - b[l], a[l], b[l]};

            tree_[idx].T = {cur[0].t};
            tree_[idx].preA = {cur[0].a};
            tree_[idx].sufB = {cur[0].b};
            return cur;
        }

        int mid = (l + r) >> 1;
        vector<Triple> left = buildImpl(idx << 1, l, mid, a, b);
        vector<Triple> right = buildImpl(idx << 1 | 1, mid + 1, r, a, b);

        vector<Triple> merged;
        merged.reserve(left.size() + right.size());

        size_t i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i].t <= right[j].t) {
                merged.push_back(left[i++]);
            } else {
                merged.push_back(right[j++]);
            }
        }
        while (i < left.size()) merged.push_back(left[i++]);
        while (j < right.size()) merged.push_back(right[j++]);

        const int m = static_cast<int>(merged.size());
        Node &nd = tree_[idx];
        nd.T.resize(m);
        nd.preA.resize(m);
        nd.sufB.resize(m);

        for (int k = 0; k < m; ++k) {
            nd.T[k] = merged[k].t;
            nd.preA[k] = (k == 0 ? merged[k].a : max(nd.preA[k - 1], merged[k].a));
        }
        for (int k = m - 1; k >= 0; --k) {
            nd.sufB[k] = (k == m - 1 ? merged[k].b : max(nd.sufB[k + 1], merged[k].b));
        }

        return merged;
    }

    long long queryImpl(int idx, int l, int r, int ql, int qr, long long d) const {
        if (ql <= l && r <= qr) {
            return evalNode(tree_[idx], d);
        }

        int mid = (l + r) >> 1;
        long long ans = NEG;
        if (ql <= mid) ans = max(ans, queryImpl(idx << 1, l, mid, ql, qr, d));
        if (qr > mid) ans = max(ans, queryImpl(idx << 1 | 1, mid + 1, r, ql, qr, d));
        return ans;
    }
};

int main() {
    FastScanner fs;

    int T = 0;
    if (!fs.readInt(T)) return 0;

    string out;
    out.reserve(1 << 22);

    while (T--) {
        int n = 0, q = 0;
        fs.readInt(n);
        fs.readInt(q);

        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) {
            fs.readInt(a[i]);
            fs.readInt(b[i]);
        }

        SegTree st(n);
        st.build(a, b);

        long long lastAns = 0;
        for (int i = 1; i <= q; ++i) {
            int l = 0, r = 0;
            long long X = 0, Y = 0;
            fs.readInt(l);
            fs.readInt(r);
            fs.readInt(X);
            fs.readInt(Y);

            long long x = (X ^ lastAns);
            long long y = (Y ^ lastAns);
            long long d = y - x;

            long long best = st.rangeQuery(l, r, d);
            long long ans = x + best;

            out.append(to_string(ans));
            out.push_back('\n');
            lastAns = ans;
        }
    }

    fwrite(out.c_str(), 1, out.size(), stdout);
    return 0;
}
