#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include <numeric>

#define sc_int(x) scanf("%d", &x)

#define x first
#define y second
#define pb push_back

using namespace std;

const int N = 3e5 + 10, M = 50, MOD =  998244353;
const int inf = 1e9;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef pair<char, int> PCI;
typedef pair<string, string> PSS;

LL n, m;
int f[N];

void solve() 
{
    memset(f, 0, sizeof f);
    cin >> n;
    vector<LL> a(n + 1), s(n + 1);
    LL sum = 0;
    for(int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
    map<LL, vector<int>> mp;
    for(int i = 1; i <= n; i ++) mp[s[n] - s[i - 1]].pb(i);
    
    // for(auto [x, y] : mp)
    // {
    //     cout << x << ":" << endl;
    //     for(auto t : y) cout << t << " ";
    //     cout << endl;
    // }

    for(int i = 1; i <= n; i ++)
    {
        // cout << s[n] - s[i] << endl;
        f[i] = f[i - 1];
        if(!a[i]) f[i] += 1;
        else 
        {
            if(mp.count(s[n] - s[i])) 
            {
                auto t = lower_bound(mp[s[n] - s[i]].begin(), mp[s[n] - s[i]].end(), i);
                if(t != mp[s[n] - s[i]].begin()) 
                {
                    t --;
                    f[i] = max(f[i], f[*t - 1] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
}


int main()
{
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    // ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    int T = 1;
    cin >> T;
    while(T -- )
    {
        solve();
    }
}