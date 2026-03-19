#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL processPairs(vector<int> pairs, int extra) {
    if(pairs.empty() && extra==0) return 0;
    LL sumPairs = 0;
    for (int x : pairs) sumPairs += x;
    LL total = extra + 2LL * sumPairs;
    int edgeCount = extra > 0 ? 2 * (int)pairs.size() + 1 : 2 * (int)pairs.size();
    if(edgeCount < 3) return 0;
    int M = pairs.empty() ? extra : pairs[0];
    if(extra > 0) M = max(M, extra);
    while(!pairs.empty() && total <= 2LL * M) {
        total -= 2LL * pairs[0];
        pairs.erase(pairs.begin());
        edgeCount = extra > 0 ? 2 * (int)pairs.size() + 1 : 2 * (int)pairs.size();
        if(edgeCount < 3) return 0;
        if(pairs.empty()) {
            M = extra; // 仅剩extra
        } else {
            M = pairs[0];
            if(extra > 0) M = max(M, extra);
        }
    }
    if(total > 2LL * M && edgeCount >= 3) return total;
    return 0;
}
  
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        unordered_map<int,int> freq;
        for (int x : a) freq[x]++;
        LL ans = 0;
        vector<int> pairs;
        for(auto &pr: freq){
            int L = pr.first, f = pr.second;
            int cnt = f / 2;
            for (int i=0; i<cnt; i++){
                pairs.push_back(L);
            }
        }
        sort(pairs.begin(), pairs.end(), greater<int>());
        LL cand = processPairs(pairs, 0);
        ans = max(ans, cand);
        for(auto &pr: freq){
            int L = pr.first, f = pr.second;
            if(f < 1) continue;
            vector<int> pairs2;
            for(auto &p: freq){
                int len = p.first, cnt = p.second;
                if(len == L){
                    int use = (cnt - 1) / 2;
                    for (int i = 0; i < use; i++)
                        pairs2.push_back(len);
                } else {
                    int use = cnt / 2;
                    for (int i = 0; i < use; i++)
                        pairs2.push_back(len);
                }
            }
            sort(pairs2.begin(), pairs2.end(), greater<int>());
            LL cand2 = processPairs(pairs2, L);
            ans = max(ans, cand2);
        }
        cout << ans << "\n";
    }
    return 0;
}