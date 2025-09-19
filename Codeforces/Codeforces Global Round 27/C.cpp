#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        set<int> st;
        for (int i=1;i<=n;i++) st.insert(i);
        deque<int> ans;
        if (n & 1){
            ans.push_front(n), ans.push_front(n-1);
            ans.push_front(1), ans.push_front(3);
            st.erase(n), st.erase(n-1), st.erase(1), st.erase(3);
            for (auto x:st){
                ans.push_front(x);
            }
            cout << n << '\n';
            for (auto x:ans){
                cout << x << ' ';
            }
            cout << '\n';
        } else{
            LL k = 1;
            while ((1LL << k) < n) k ++;
            LL t = (1LL << k) - n; 
            if (t == 0) t = n;
            ans.push_front(t),st.erase(t);
            ans.push_front(n-1),st.erase(n-1);
            ans.push_front(n-2),st.erase(n-2);
            ans.push_front(1),st.erase(1);
            ans.push_front(3),st.erase(3);
            for (auto x:st){
                ans.push_front(x);
            }
            cout << t + n - 1 << '\n';
            for (auto x:ans){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}