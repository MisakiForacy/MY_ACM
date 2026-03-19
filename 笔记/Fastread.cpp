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
    inline bool readFloat(long double &x) {
        std::string s; if (!readString(s)) return false;
        x = strtold(s.c_str(), nullptr); return true;
    }
    inline bool readString(std::string &s) {
        char c;
        if (!skipBlank(c)) return false;
        s.clear();
        while (c > ' ') { s.push_back(c); c = gc(); if (!c) break; }
        return true;
    }
    inline void pc(char c) { if (o == S) flush(); ob[o++] = c; }
    inline void flush() { if (o) fwrite(ob, 1, o, stdout), o = 0; }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, int>::type = 0>
    inline IO &writeInt(T x) {
        if (x == 0) return pc('0'), *this;
        if (x < 0) pc('-'), x = -x;
        char s[32];
        int t = 0;
        while (x) s[t++] = (char)('0' + (x % 10)), x /= 10;
        while (t--) pc(s[t]);
        return *this;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value, int>::type = 0>
    inline IO &writeInt(T x) {
        if (x == 0) return pc('0'), *this;
        char s[32];
        int t = 0;
        while (x) s[t++] = (char)('0' + (x % 10)), x /= 10;
        while (t--) pc(s[t]);
        return *this;
    }
    inline IO &writeFloat(long double x) {
        char s[64]; int len = snprintf(s, sizeof(s), "%.12Lg", x);
        for (int k = 0; k < len; ++k) pc(s[k]);
        return *this;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline IO &operator>>(T &x) { readInt(x); return *this; }
    inline IO &operator>>(std::string &s) { readString(s); return *this; }
    inline IO &operator>>(char &c) { return skipBlank(c), *this; }
    inline IO &operator>>(bool &b) { int t; readInt(t); b = (t != 0); return *this; }
    inline IO &operator>>(float &x) { long double t; readFloat(t); x = (float)t; return *this; }
    inline IO &operator>>(double &x) { long double t; readFloat(t); x = (double)t; return *this; }
    inline IO &operator>>(long double &x) { readFloat(x); return *this; }
    template <class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline IO &operator<<(T x) { return writeInt(x); }
    inline IO &operator<<(const std::string &s) { for (char c : s) pc(c); return *this; }
    inline IO &operator<<(const char *s) { while (*s) pc(*s++); return *this; }
    inline IO &operator<<(char c) { pc(c); return *this; }
    inline IO &operator<<(bool b) { return *this << (b ? 1 : 0); }
    inline IO &operator<<(float x) { return writeFloat(x); }
    inline IO &operator<<(double x) { return writeFloat(x); }
    inline IO &operator<<(long double x) { return writeFloat(x); }
    template <class A, class B>
    inline IO &operator>>(std::pair<A, B> &p) { *this >> p.first >> p.second; return *this; }
    template <class A, class B>
    inline IO &operator<<(const std::pair<A, B> &p) { *this << p.first << ' ' << p.second; return *this; }
};
inline IO io;
#define cin io
#define cout io