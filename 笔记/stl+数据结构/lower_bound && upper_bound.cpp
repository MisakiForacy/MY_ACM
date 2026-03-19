#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int main(){
    // vector<int> a = {1,1,2,2,2,5,5,6,7,8};
    // int n;
    // while (cin >> n){
    //     if (lower_bound(all(a),n)==a.end()){
    //         cout << "Not find\n";
    //     } else{
    //         cout << lower_bound(all(a),n)-a.begin() << '\n';
    //     }
    //     if (upper_bound(all(a),n)==a.end()){
    //         cout << "Not find\n";
    //     } else{
    //         cout << upper_bound(all(a),n)-a.begin() << '\n';
    //     }
    //     // lower_bound 返回第一个大于等于n的数字的索引
    //     // upper_bound 返回第一个大于n的数字的索引
    // }
    vector<int> a = {1,3,5};
    int n;
    while (cin >> n){
        cout << a.size() - (lower_bound(all(a),n)-begin(a)) << '\n';
    }
}