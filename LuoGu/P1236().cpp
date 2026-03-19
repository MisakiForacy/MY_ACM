#include <bits/stdc++.h>
using namespace std;
vector<int>a(4);
vector<int>op(3);
char ch[4] = {'+','-','*','/'};
bool check(){
    int n = a[0];
    for (int i=1;i<4;i++){
        if (op[i-1]==1){
            n = n + a[i];
        } else if (op[i-1]==2){
            n = n - a[i];
        } else if (op[i-1]==3){
            n = n * a[i];
        } else{
            if (n%a[i]) return 0;
            n = n / a[i];
        }
    }
    if (n==24) return 1;
    else return 0;
}
int main(){
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(),a.end());
    do{
        for (int i=1;i<=4;i++){
            for (int j=1;j<=4;j++){
                for (int k=1;k<=4;k++){
                    op[0] = i, op[1] = j, op[2] = k;
                    if (check()){
                        int n = a[0], nn = a[0];
                        for (int i=1;i<4;i++){
                            if (op[i-1]==1){
                                n = n + a[i];
                            } else if (op[i-1]==2){
                                n = n - a[i];
                            } else if (op[i-1]==3){
                                n = n * a[i];
                            } else{
                                if (n%a[i]) return 0;
                            }
                            cout << max(nn,a[i]) << ch[op[i-1]-1] << min(nn,a[i]) << '=' << n << '\n';
                            nn = n;
                        }
                        return 0;
                    }
                }
            }
        }
    } while (next_permutation(a.begin(),a.end()));
    cout << "No answer!\n";
}