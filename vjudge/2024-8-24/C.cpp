#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    map<char,int> mp;
    for (int i=0;i<int(s.length());i++){
        mp[s[i]] ++;
    }
    vector<int>ans;
    for (auto [k,v]:mp){
        ans.push_back(k-'0');
    }
    reverse(ans.begin(),ans.end());
    // int[] arr = new int[]{8,3,2,1,0};
    // int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
    cout << "int[] arr = new int[]{";
    cout << ans[0];
    for (int i=1;i<int(ans.size());i++){
        cout << ',' << ans[i];
    }
    cout << "};\n";
    cout << "int[] index = new int[]{";
    vector<int> res(11);
    int idx = 0;
    for (int i=0;i<11;i++){
        for (int j=0;j<int(ans.size());j++){
            if (ans[j]==s[i]-'0'){
                idx = j;
                break;
            }
        }
        res[i] = idx;
    }
    cout << res[0];
    for (int i=1;i<int(res.size());i++){
        cout << ',' << res[i];
    }
    cout << "};";
}