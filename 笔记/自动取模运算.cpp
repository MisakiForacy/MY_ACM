const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;
 
template<const LL MOD>
struct ModInt{
    LL x;
    static inline LL norm(LL n){
        n %= MOD;
        if (n < 0) n += MOD;
        return n;
    }
    ModInt(LL n = 0){ x = norm(n);}
    ModInt<MOD> qmi(LL k) const {
        ModInt<MOD> res = 1;
        ModInt<MOD> a = *this;
        while (k){
            if (k&1) (res.x *= a.x) %= MOD;
            (a.x *= a.x) %= MOD;
            k /= 2;
        }
        return res;
    }
    ModInt<MOD> inv() const { return qmi(MOD-2);}
    friend ModInt<MOD> operator+(const ModInt<MOD>& a,const ModInt<MOD>& b){ return ModInt<MOD>(a.x + b.x);}
    friend ModInt<MOD> operator-(const ModInt<MOD>& a,const ModInt<MOD>& b){ return ModInt<MOD>(a.x - b.x);}
    friend ModInt<MOD> operator*(const ModInt<MOD>& a,const ModInt<MOD>& b){ return ModInt<MOD>((a.x * b.x) % MOD);}
    friend ModInt<MOD> operator/(const ModInt<MOD>& a,const ModInt<MOD>& b){ return a * b.inv();}
    friend ModInt<MOD> operator%(const ModInt<MOD>& a,const ModInt<MOD>& b){ return ModInt<MOD>(a.x % b.x);}
    friend bool operator<=(const ModInt<MOD>& a,const ModInt<MOD>& b){ return a.x <= b.x;}
    friend bool operator< (const ModInt<MOD>& a,const ModInt<MOD>& b){ return a.x <  b.x;}
    friend bool operator>=(const ModInt<MOD>& a,const ModInt<MOD>& b){ return a.x >= b.x;}
    friend bool operator> (const ModInt<MOD>& a,const ModInt<MOD>& b){ return a.x >  b.x;}
    friend bool operator==(const ModInt<MOD>& a,const ModInt<MOD>& b){ return a.x == b.x;}
    friend bool operator!=(const ModInt<MOD>& a,const ModInt<MOD>& b){ return a.x != b.x;}
    friend ostream& operator<< (ostream& out,const ModInt<MOD>& a){ return out << a.x;}
    friend istream& operator>> (istream& in, ModInt<MOD>& a){ LL v;in >> v;a.x = norm(v);return in; }
    ModInt<MOD>& operator+= (const ModInt<MOD>& a){ return *this = *this + a;}
    ModInt<MOD>& operator-= (const ModInt<MOD>& a){ return *this = *this - a;}
    ModInt<MOD>& operator*= (const ModInt<MOD>& a){ return *this = *this * a;}
    ModInt<MOD>& operator/= (const ModInt<MOD>& a){ return *this = *this / a;}
    ModInt<MOD>& operator++ (){ ++x; if (x == MOD) x = 0; return *this; }
    ModInt<MOD> operator++ (int){ ModInt<MOD> t = *this;++(*this);return t; }
    ModInt<MOD>& operator-- (){ if (x == 0) x = MOD;--x;return *this; }
    ModInt<MOD> operator-- (int){ ModInt<MOD> t = *this;--(*this);return t; }
};
using Z = ModInt<MOD3>;