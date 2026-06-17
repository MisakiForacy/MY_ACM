#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int x, cnt = 2;
        vector<int> ans;
        cin >> x;
        while (x & (x + 1) != 0 && cnt ++) {
            if (cnt & 1) {
                int ok = 0, n;
                for (int i = 30;i >= 0;i --) {
                    if (x >> i & 1) {
                        ok = 1;
                    }
                    if (ok && !(x >> i & 1)) {
                        n = i;
                        break;
                    }
                }
                ans.push_back(n);
            } else {
                x += 1;
            }
        }
    }   
}