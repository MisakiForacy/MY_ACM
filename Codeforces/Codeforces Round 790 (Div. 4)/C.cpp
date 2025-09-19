#include <iostream>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>trr;

const long long inf = 1e18;
signed main(){

    auto f = [&](int x) { // 计算阶乘
        long long res = 1;
        while (x) {
            if (__int128_t(res) * x > inf)
                return inf;
            res *= x;
            x--;
        }
        return res;
    };

    int n, k;
    cin >> n >> k;
    if (k > f(n)) {
        cout << "No Answer!" << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        trr.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        // 判断第i位放什么，去思考周期
        int zq = f(n - i);
        int op = (k - 1) / zq;
        auto it = trr.find_by_order(op);
        cout << *it << " ";
        trr.erase(it);
        k -= zq * op;
    }
}