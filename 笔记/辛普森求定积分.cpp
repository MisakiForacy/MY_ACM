// 2025杭电暑假多校第4场，1012
// 辛普森公式求弧长公式定积分
/*
auto f = [&](double x) -> double {
    double y = 0;
    for (int i = m;i >= 1;i --){
        y += a[i] * cal(x, i);
    }
    return y;
};
auto df = [&](double x) -> double {
    double y = 0;
    for (int i = m;i >= 1;i --){
        y += i * a[i] * cal(x, i - 1);
    }
    return y;
};
auto fdf = [&](double x) -> double {
    double y = sqrt(1 + cal(df(x), 2));
    return y;
};
auto simpson = [&](double l, double r) -> double {
    double v = (r - l) / 6.0 * (fdf(l) + 4 * fdf((l + r) / 2) + fdf(r));
    return v;
};
auto dis = [&](auto dis, double l, double r, double v) -> double {
    double mid = (l + r) / 2;
    double L = simpson(l, mid), R = simpson(mid, r);
    if (fabs(L + R - v) > eps * 0.01){
        return dis(dis, l, mid, L) + dis(dis, mid, r, R);
    }
    return L + R + (L + R - v) / 0.01;
};
*/
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define double long double
using namespace std;
using LL = long long;
const double inf = 1e11;
const double eps = 1e-7;
void output(double x){
    static char s[25];
    sprintf(s,"%.4Le",x);
    for(int i:{0,1,2,3,4,5,6,7}) printf("%c",s[i]);
    printf("%c\n",s[strlen(s)-1]);
}
void solve(){
    int n, m;
    double X, Y;
    scanf("%d%d%llf%llf", &n, &m, &X, &Y);
    vector<double> a(m + 1), H(n + 1), W(n + 1);
    vector<int> p(n);
    for (int i = 0;i < n;i ++) p[i] = i + 1;
    for (int i = 1;i <= m;i ++) scanf("%llf", &a[i]);
    for (int i = 1;i <= n;i ++){
        scanf("%llf%llf", &H[i], &W[i]);
    }
    if (n == 1){
        printf("0.0000e+0\n");
        return;
    }
    auto cal = [&](double a, int k) -> double {
        double res = 1;
        while (k --){
            res *= a;
        }
        return res;
    };
    auto f = [&](double x) -> double {
        double y = 0;
        for (int i = m;i >= 1;i --){
            y += a[i] * cal(x, i);
        }
        return y;
    };
    auto df = [&](double x) -> double {
        double y = 0;
        for (int i = m;i >= 1;i --){
            y += i * a[i] * cal(x, i - 1);
        }
        return y;
    };
    auto fdf = [&](double x) -> double {
        double y = sqrt(1 + cal(df(x), 2));
        return y;
    };
    auto simpson = [&](double l, double r) -> double {
        double v = (r - l) / 6.0 * (fdf(l) + 4 * fdf((l + r) / 2) + fdf(r));
        return v;
    };
    auto dis = [&](auto dis, double l, double r, double v) -> double {
        double mid = (l + r) / 2;
        double L = simpson(l, mid), R = simpson(mid, r);
        if (fabs(L + R - v) > eps * 0.01){
            return dis(dis, l, mid, L) + dis(dis, mid, r, R);
        }
        return L + R + (L + R - v) / 0.01;
    };
    auto f1 = [&](double x, double k, double b) -> double {
        double y = f(x);
        y -= k * x + b;
        return y;
    };
    auto f2 = [&](double x, double X0, double Y0, double R) -> double {
        double y = 0;
        y = cal(X0 - x, 2) + cal(Y0 - f(x), 2) - cal(R, 2);
        return y; 
    };
    auto check1 = [&](double lo, double x, double k, double b) -> bool {
        double val1 = f1(lo, k, b);
        double val2 = f1(x, k, b);
        return val1 * val2 > 0;
    };
    auto check2 = [&](double lo, double x, double X0, double Y0, double R) -> bool {
        double val1 = f2(lo, X0, Y0, R);
        double val2 = f2(x, X0, Y0, R);
        return val1 * val2 > 0;
    };
    auto cal1 = [&](double Mi, double k, double b) -> double {
        double lo = Mi, hi = inf;
        while (hi - lo > eps){
            double mid = (lo + hi) / 2.0;
            if (check1(lo, mid, k, b)) lo = mid;
            else hi = mid;
        }
        return lo;
    };
    auto cal2 = [&](double Mi, double X0, double Y0, double R) -> double {
        double lo = Mi, hi = inf;
        while (hi - lo > eps){
            double mid = (lo + hi) / 2.0;
            if (check2(lo, mid, X0, Y0, R)) lo = mid;
            else hi = mid;
        }
        return lo;
    };
    double Min = 1e18;
    do{
        double sum = 0;
        double h = H[p[0]];
        double w = W[p[0]];
        double x = 0;
        double lst_x = 0, lst_y = 0, lst_h = h;
        for (int i = 1;i < n;i ++){
            h = H[p[i]];
            w = W[p[i]];
            double k = (Y - lst_h) / (X - lst_x);
            double b = lst_h - (Y - lst_h) * lst_x / (X - lst_x);
            double R = max(lst_h - f(lst_x), h);
            double x1 = cal1(lst_x, k, b);
            double x2 = cal2(lst_x, lst_x, f(lst_x), R);
            x = max(x1, x2);
            lst_x = x;
            lst_y = f(x);
            lst_h = lst_y + h;
            sum += dis(dis, 0, x, simpson(0, x)) * w;
        }
        Min = min(Min, sum);
    } while (next_permutation(all(p)));

    output(Min);
}
int main(){
    int T = 1;
    scanf("%d", &T);
    while (T --) solve();
}