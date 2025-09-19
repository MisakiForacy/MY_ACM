#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using LL = long long;

int main(){
    vector<LL> a = {1, 100000, 1000165, 2641253, 1545643, 154515, 100000, 8, 12};
    /**
     * 哪类数据需要离散化？
     * 数与数之间跨度特别大，但数的数量又不会很多
     * 流程：
     * 1.排序
     * 2.去重
     * 3.二分找到对应的索引，用索引值来映射原来的数
     * 上面例子：0映射1，1映射8，2映射12...
     */
    sort(a.begin(), a.end());   // 排序
    a.erase(unique(a.begin(), a.end()), a.end()); // 去重
    vector<int> p(a.size());    // 映射数组
    for (int i = 0;i < a.size();i ++){
        p[i] = lower_bound(a.begin(), a.end(), a[i]) - a.begin();  // lower_bound找到第一个大于等于a[i]的数的索引
    }
    for (int i = 0;i < a.size();i ++){
        cout << p[i] << "->" << a[i] << '\n';
    }
}