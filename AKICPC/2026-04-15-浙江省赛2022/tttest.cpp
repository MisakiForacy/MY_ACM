#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int tmp[16], n = 16, cnt = 0;
int a[] = {10, 4, 2, 1, 7, 3, 5, 12, 9, 8, 11, 10, 7, 4, 3, 3};

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k ++] = a[i ++];
        } else {
            tmp[k ++] = a[j ++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k ++] = a[i ++];
    while (j <= r)   tmp[k ++] = a[j ++];
    for (int i = l;i <= r;i ++) a[i] = tmp[i];
}

void msort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    msort(l, mid);
    msort(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    msort(0, 15);
    for (int i = 0;i < 16;i ++) cout << a[i] << ' ';
    cout << '\n';
    cout << cnt << '\n';
}