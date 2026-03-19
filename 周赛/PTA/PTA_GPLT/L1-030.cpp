#include <bits/stdc++.h>
using namespace std;
struct info{
    bool gender;
    string name;
    bool flag = 0;
};
int main(){
    int n;
    int i,j;
    cin >> n;
    vector<info>a(n);
    for(i=0;i<n;i++)cin >> a[i].gender >> a[i].name;
    for(i=0;i<n;i++){
        for(j=n-1;j>-1;j--){
            if((a[i].gender^a[j].gender)&(!(a[i].flag|a[j].flag))){
                a[i].flag = 1;a[j].flag = 1;
                cout << a[i].name << " " << a[j].name << endl;
            }
        }
    }
}