#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

int n;
int a[N], cnt[N], res[N];

int main() {
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int index = 0;
    for (int i = 0;i < N;i ++) {
        while (cnt[i] --) {
            res[index] = i;
            index ++;
        }
    }
    for (int i = 0;i < index;i ++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}