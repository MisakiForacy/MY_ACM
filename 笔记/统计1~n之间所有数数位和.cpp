#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    LL n;
    cin >> n;
    auto cal = [&](LL num) -> LL {
        LL base = 1, len, val = 0;
        len = to_string(num).size();
        for (int i = 1;i <= len;i ++) {
            int cur = num / base % 10;
            for (int j = 0;j <= 9;j ++) {
                if (j < cur) {
                    val += j * (num / base / 10 + 1) * base;
                } else if (j == cur) {
                    val += j * (num / base / 10) * base;
                    val += j * (num % base + 1);
                } else {
                    val += j * (num / base / 10) * base;
                }
            }
            base *= 10;
        }
        return val;
    };
    cout << cal(n) << '\n';
}