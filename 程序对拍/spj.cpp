#include <bits/stdc++.h>
using namespace std;

int n, a[500010];

int N, b[500010];

void input () {
    cin >> n;
    for (int i = 0;i < n;i ++) cin >> a[i];
}

void output () {
    cin >> N;
    for (int i = 0;i < n;i ++) cin >> b[i];
}

void Result () {
    cout << n << '\n';
    for (int i = 0;i < n;i ++) cout << a[i] << " \n"[i == n - 1];
    cout << N << '\n';
    for (int i = 0;i < n;i ++) cout << b[i] << " \n"[i == n - 1];
}

void check () {
    vector <int> use (n + 1, 0), Count (n + 1, 0);
    stack <int> stk;
    int cnt = 0;
    for (int i = 0;i < n;i ++) {
        Count[a[i]] ++, Count[b[i]] ++;
        if (use[a[i]] == 1) {
            while (stk.top () != a[i]) {
                use[stk.top()] --;
                stk.pop();
            }
            cnt ++;
        } else {
            stk.push (a[i]);
            use[a[i]] ++;
        }
        if (use[b[i]] == 1) {
            while (stk.top () != b[i]) {
                use[stk.top()] --;
                stk.pop();
            }
        } else {
            stk.push (b[i]);
            use[b[i]] ++;
        }
    }
    if (cnt != N) {
        cout << "Error In Count\n";
        cout << "Real : " << cnt << '\n';
        cout << "Actual : " << N << '\n';
        cout << '\n';
    } else {
        cout << "Count Is Correct\n";
        cout << '\n';
    }
    for (int i = 1;i <= n;i ++) {
        if (Count[i] < 2) {
            cout << "Less in : " << i << " Actual : " << Count[i] << '\n';
        } else if (Count[i] > 2) {
            cout << "More in : " << i << " Actual : " << Count[i] << '\n';
        }
    }
}

int main () {
    input ();
    output ();
    // Result ();
    check ();
}