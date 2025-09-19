#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD = 1e9 + 7;

char get_c(vector<vector<char>> &a,int i,int j){
    map<char,int> mp;
    mp[a[i - 1][j]] ++;
    mp[a[i - 1][j + 1]] ++;
    mp[a[i][j - 1]] ++;
    mp[a[i + 1][j - 1]] ++;
    for (char c = 'a';c <= 'z';c ++){
        if (!mp.count(c)){
            return c;
        }
    }
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        int n,m,k;
        cin >> n >> m >> k;
        int ok = 1;
        if (n & 1){
            if (k < (m / 2)) ok = 0;
            if ((k - (m / 2)) % 2 != 0){
                if (k < 3 * (m / 2)) ok = 0;
                if ((k - 3 * (m / 2)) % 2 != 0) ok = 0;
            }
        } else if (m & 1){
            k = n * m / 2 - k;
            if (k < (n / 2)) ok = 0;
            if ((k - (n / 2)) % 2 != 0){
                if (k < 3 * (n / 2)) ok = 0;
                if ((k - 3 * (n / 2)) % 2 != 0) ok = 0;
            }
        } else{
            if (k % 2 != 0){
                if (k < 2 * (m / 2)) ok = 0;
                if ((k - 2 * (m / 2)) % 2 != 0) ok = 0;
            }
            k = n * m / 2 - k;
            if (k % 2 != 0){
                if (k < 2 * (n / 2)) ok = 0;
                if ((k - 2 * (n / 2)) % 2 != 0) ok = 0;
            }
            k = n * m / 2 - k;
        }
        if (!ok){
            cout << "NO\n";
        } else{
            int f = 0;
            cout << "YES\n";
            vector<vector<char>> a;
            a.clear();
            if (m & 1){
                a.resize(m + 2, vector<char>(n + 2, ' '));
                f = 1;
                swap(n, m);
            }
            else a.resize(n + 2, vector<char>(m + 2, ' '));
            int t;
            if (k >= (2 + (n & 1)) * (m / 2) && (k - (2 + (n & 1)) * (m / 2)) % 2 == 0){
                for (int i = 2 + (n & 1);i <= n + 4;i += 4){
                    if (k - i * (m / 2) < 0){
                        t = i - 4;
                        break;
                    }
                }
                for (int i = 1;i <= t;i ++){
                    for (int j = 1;j <= m;j += 2){
                        a[i][j] = a[i][j + 1] = get_c(a,i,j);
                    }
                }
            } else if (k >= (n & 1) * (m / 2) && (k - (n & 1) * (m / 2)) % 2 == 0){
                for (int i = (n & 1);i <= n + 4;i += 4){
                    if (k - i * (m / 2) < 0){
                        t = i - 4;
                        break;
                    }
                }
                for (int i = 1;i <= t;i ++){
                    for (int j = 1;j <= m;j += 2){
                        a[i][j] = a[i][j + 1] = get_c(a,i,j);
                    }
                }
            }
            k -= t * (m / 2);
            for (int i = t + 1;i <= n;i += 2){
                if (!k) break;
                for (int j = 1;j <= m;j += 2){
                    a[i][j] = a[i][j + 1] = get_c(a,i,j);
                    a[i + 1][j] = a[i + 1][j + 1] = get_c(a,i + 1,j);
                    k -= 2;
                    if (!k) break;
                }
            }
            for (int i = 1;i <= n;i ++){
                for (int j = 1;j <= m;j ++){
                    if (a[i][j] == ' '){
                        a[i][j] = a[i + 1][j] = get_c(a,i,j);
                    }
                }
            }
            if (f){
                for (int i = 1;i <= m;i ++){
                    for (int j = 1;j <= n;j ++){
                        cout << a[j][i];
                    }
                    cout << '\n';
                }
            }else{
                for (int i = 1;i <= n;i ++){
                    for (int j = 1;j <= m;j ++){
                        cout << a[i][j];
                    }
                    cout << '\n';
                }
            }
        }
    }
}