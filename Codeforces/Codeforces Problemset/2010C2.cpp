#include <bits/stdc++.h>
using namespace std;
const int P = 1e9+7;
const int N = 4e5+5;
typedef unsigned long long ull;
typedef long long ll;
__int128_t p1[N],h1[N],p2[N],h2[N];
int len;

unsigned int generateSeedFromTimestamp() {
  auto now = std::chrono::system_clock::now(); // 获取当前时间点
  auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()); // 转换为毫秒级的时间戳
 
  return static_cast<unsigned int>(timestamp.count()); // 将时间戳转换为整数种子值
}

void init(string s){
    unsigned int seed1 = generateSeedFromTimestamp();
    mt19937 engine(seed);
    int P1 = engine();
    p[0] = 1, h[0] = 0;
    for (int i=1;i<=len;i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + s[i];
    }
}
__int128_t get(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}
int main(){
    string s;
    cin >> s;
    len = s.length();
    s = ' ' + s;
    init(s);
    int hi = len-1, lo = 2;
    while (hi >= lo){
        if (get(1,hi) == get(lo,len)){
            cout << "YES\n";
            cout << s.substr(1,hi) << '\n';
            return 0;
        }
        hi --, lo ++;
    }
    cout << "NO\n";
    return 0;
}