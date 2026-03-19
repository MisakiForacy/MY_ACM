#include <bits/stdc++.h>

// #define FastIO
#define MULITY
#define DEBUG

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first
#define y second

#define LOG 60

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL MOD = 1e9 + 7;
const LL N = 1e6 + 10;

class IO {
private:
    static const int S = 1 << 20;
    int i = 0, n = 0, o = 0;
    char ib[S], ob[S];

public:
    ~IO() { flush(); }
    inline char gc() {
        if (i >= n) {
            n = (int)fread(ib, 1, S, stdin);
            i = 0;
            if (!n) return 0;
        }
        return ib[i++];
    }
    inline bool skipBlank(char &c) {
        c = gc();
        if (!c) return false;
        while (c <= ' ') {
            c = gc();
            if (!c) return false;
        }
        return true;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, int>::type = 0>
    inline bool readInt(T &x) {
        char c;
        if (!skipBlank(c)) return false;
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = gc();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = (T)(x * 10 + (c - '0'));
            c = gc();
        }
        if (neg) x = -x;
        return true;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value, int>::type = 0>
    inline bool readInt(T &x) {
        char c;
        if (!skipBlank(c)) return false;
        x = 0;
        while (c >= '0' && c <= '9') {
            x = (T)(x * 10 + (c - '0'));
            c = gc();
        }
        return true;
    }
    inline bool readString(string &s) {
        char c;
        if (!skipBlank(c)) return false;
        s.clear();
        while (c > ' ') { s.push_back(c); c = gc(); if (!c) break; }
        return true;
    }
    inline void pc(char c) { if (o == S) flush(); ob[o++] = c; }
    inline void flush() { if (o) fwrite(ob, 1, o, stdout), o = 0; }
    template <class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline IO &operator>>(T &x) { readInt(x); return *this; }
    inline IO &operator>>(string &s) { readString(s); return *this; }
    inline IO &operator>>(char &c) { return skipBlank(c), *this; }
    template <class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline IO &operator<<(T x) {
        if (x == 0) return pc('0'), *this;
        if (x < 0) pc('-'), x = -x;
        char s[32]; int t = 0;
        while (x) s[t++] = (char)('0' + (x % 10)), x /= 10;
        while (t--) pc(s[t]);
        return *this;
    }
    inline IO &operator<<(const char *s) { while (*s) pc(*s++); return *this; }
    inline IO &operator<<(char c) { pc(c); return *this; }
};

#ifdef FastIO
inline IO io;
#define cin io
#define cout io
#else
struct StdIOInit {
    StdIOInit() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} std_io_init;
#endif

void INIT();
void SOLVE();
void BRUTE();

int main() {
#ifdef MULITY
    int T = 1;
    cin >> T;
    while (T --) {
        INIT();
        SOLVE();
    }
#else
    INIT();
    SOLVE();
#endif
}

void BRUTE() {

}

void INIT() {

}

void SOLVE() {
    
}