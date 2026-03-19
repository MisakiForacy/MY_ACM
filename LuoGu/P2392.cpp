#include <bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<int> s1(n1);
    vector<int> s2(n2);
    vector<int> s3(n3);
    vector<int> s4(n4);
    int sum1,sum2,sum3,sum4;
    sum1 = sum2 = sum3 = sum4 = 0;
    for (int i=0;i<n1;i++) cin >> s1[i], sum1 += s1[i];
    for (int i=0;i<n2;i++) cin >> s2[i], sum2 += s2[i];
    for (int i=0;i<n3;i++) cin >> s3[i], sum3 += s3[i];
    for (int i=0;i<n4;i++) cin >> s4[i], sum4 += s4[i];
    int l1,l2,l3,l4;
    l1 = sum1/2, l2 = sum2/2, l3 = sum3/2, l4 = sum4/2;
    int dp1[l1+1],dp2[l2+1],dp3[l3+1],dp4[l4+1];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    memset(dp3,0,sizeof(dp3));
    memset(dp4,0,sizeof(dp4));
    for (int i=0;i<n1;i++){
        for (int j=l1;j>=s1[i];j--){
            dp1[j] = max(dp1[j],dp1[j-s1[i]]+s1[i]);
        }
    }
    for (int i=0;i<n2;i++){
        for (int j=l2;j>=s2[i];j--){
            dp2[j] = max(dp2[j],dp2[j-s2[i]]+s2[i]);
        }
    }
    for (int i=0;i<n3;i++){
        for (int j=l3;j>=s3[i];j--){
            dp3[j] = max(dp3[j],dp3[j-s3[i]]+s3[i]);
        }
    }
    for (int i=0;i<n4;i++){
        for (int j=l4;j>=s4[i];j--){
            dp4[j] = max(dp4[j],dp4[j-s4[i]]+s4[i]);
        }
    }
    int ans = 0;
    ans += max(sum1-dp1[l1],dp1[l1]);
    ans += max(sum2-dp2[l2],dp2[l2]);
    ans += max(sum3-dp3[l3],dp3[l3]);
    ans += max(sum4-dp4[l4],dp4[l4]);
    cout << ans << '\n';
}