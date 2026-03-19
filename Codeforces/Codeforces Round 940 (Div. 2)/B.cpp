#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,i;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int>ans;
        if(n==1){
            cout << k << endl;
            continue;
        }
        else{
            int ii = 0;
            while(pow(2,ii)<=k)ii++;
            if(pow(2,ii)-1==k){
                ans.push_back(pow(2,ii)-1);
                k = 0;
            }
            else{
                ans.push_back(pow(2,ii-1)-1);
                k -= pow(2,ii-1)-1;
            }
            for(i=1;i<n-1;i++)ans.push_back((--k>=0?1:0));
            ans.push_back(k<0?0:k);
            for(i=0;i<ans.size();i++)cout << ans[i] << " ";
        }
        cout << endl;
    }
}