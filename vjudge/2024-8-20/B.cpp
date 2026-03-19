#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(),x.end()
using namespace std;
int a[20005];
vector<int> p;
void init(){
    a[1] = 1;
    for (int i=2;i<=20000;i++){
        if (!a[i]){
            p.push_back(i);
            for (int j=i*i;j<=20000;j+=i){
                a[j] = 1;
            }
        }
    }
}
struct haha{
    int num,pri,id;
    // bool operator < (const haha &that){
    //     if (that.pri != pri) return that.pri < pri;
    // }
};
bool cmp(haha a,haha b){
    if (a.pri != b.pri) return a.pri > b.pri;
}
int main(){
    init();
    int n;
    while (cin >> n){
        vector<haha> arr;
        int num,pri=1;
        for (int i=0;i<n;i++){
            cin >> num;
            int idx = lower_bound(all(p),num)-p.begin();
            for (int i=idx;i>=0;i--){
                if (num%p[i]==0){
                    pri = p[i];
                    break;
                }
            }
            arr.push_back({num,pri,i});
        }
        sort(all(arr),cmp);
        if (arr[0].pri!=1){
            cout << arr[0].num << '\n';
        } else{
            cout << 1 << '\n';
        }
    }
}