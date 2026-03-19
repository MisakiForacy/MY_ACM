#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>>ans(0,vector<int>(10));
    if (n<10 || n>30){
        cout << 0 << '\n';
    } else{
        for (int n1=1;n1<=3;n1++)
        for (int n2=1;n2<=3;n2++)
        for (int n3=1;n3<=3;n3++)
        for (int n4=1;n4<=3;n4++)
        for (int n5=1;n5<=3;n5++)
        for (int n6=1;n6<=3;n6++)
        for (int n7=1;n7<=3;n7++)
        for (int n8=1;n8<=3;n8++)
        for (int n9=1;n9<=3;n9++)
        for (int n10=1;n10<=3;n10++){
            if (n1+n2+n3+n4+n5+n6+n7+n8+n9+n10==n){
                ans.push_back({n1,n2,n3,n4,n5,n6,n7,n8,n9,n10});
            }
        }
        cout << ans.size() << '\n';
        for (int i=0;i<int(ans.size());i++){
            for (int j=0;j<10;j++){
                cout << ans[i][j] << " \n"[j==9];
            }
        }
    }
}