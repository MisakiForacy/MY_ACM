#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    while (cin >> k){
        int cnt = 0;
        vector<string>ans;
        for (int y=k+1;y<=k*2;y++){
            if (!((k*y)%(y-k))){
                string line = "1/"+to_string(k)+" = 1/"+to_string((k*y)/(y-k))+" + 1/"+to_string(y);
                ans.push_back(line);
                cnt ++;
            }
        }
        printf("%d\n",cnt);
        for (int i=0;i<cnt;i++){
            cout << ans[i] << "\n";
        }
    }
}