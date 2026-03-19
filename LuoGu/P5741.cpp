#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
struct info{
    string name;
    i64 a,b,c,d;
};
int main(){
    i64 n,i,j;
    cin >> n;
    vector<info>a(n);
    for(i=0;i<n;i++){
        cin >> a[i].name >> a[i].a >> a[i].b >> a[i].c;
        a[i].d = a[i].a + a[i].b + a[i].c;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(abs(a[i].a-a[j].a)<=5&&\
               abs(a[i].b-a[j].b)<=5&&\
               abs(a[i].c-a[j].c)<=5&&\
               abs(a[i].d-a[j].d)<=10){
                cout << a[i].name << " " << a[j].name << endl;
               }
        }
    }
    return 0;
}