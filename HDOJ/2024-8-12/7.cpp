#include<iostream>
#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<bitset>
#include<unordered_map>
#include<numeric>
#include<stack>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define tans cout<<"ARRAY:"
#define rep(i,a,b) for(int i = a;i<=b;i++)
const int N = 1e6 + 10;


//负数求模公式 (a % mod + mod) % mod

int gcd(int a, int b){
    return b > 0 ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int a, b, c;
bool check(int k) {
    int pa = a, pb = b, pc = c;
    vector<int> vc;
    while (pc) {
        vc.push_back(pc % k);
        pc /= k;
    }

    vector<int> va;
    while (pa) {
        va.push_back(pa % k);
        pa /= k;
    }

    vector<int> vb;
    while (pb) {
        vb.push_back(pb % k);
        pb /= k;
    }

    for (int i = 0; i < max({ va.size(),vb.size(),vc.size() }); i++) {
        pa = i < va.size() ? va[i] : 0;
        pb = i < vb.size() ? vb[i] : 0;
        pc = i < vc.size() ? vc[i] : 0;
        if ((pa + pb) % k != pc) return false;
    }
    return true;
}

void solve() {
    cin >> a >> b >> c;
    int cnt = 0;
    tans;
    rep(k, 2, 10000) {
        if (check(k)) {cout<<k<<',';cnt++;}
    }
    // tans;
    cout <<"\nSUM:" << cnt << "\n\n";
}

signed main() {
    //cout << lcm(14,5);
    int t = 1;
    // IOS;
    cin >> t;
    while (t--) solve();

    //clock_t end_time = clock();
    //cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;//输出运行时间
    return 0;
}