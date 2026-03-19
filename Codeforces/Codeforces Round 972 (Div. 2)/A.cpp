#include <bits/stdc++.h>
using namespace std;
char ch[] = {'a','e','i','o','u'};
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s = "";
        int a[] = {0,0,0,0,0};
        for (int i=0;i<5;i++){
            a[i] = n / 5;
        }
        for (int i=0;i<n%5;i++){
            a[i] ++;
        }
        for (int i=0;i<5;i++){
            for (int j=0;j<a[i];j++){
                s.push_back(ch[i]);
            }
        }
        cout << s << '\n';
    }
}