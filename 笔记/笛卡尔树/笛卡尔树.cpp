#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using LL = long long;

/**
 * 笛卡尔树
 * 将无序数组变成一个有序表
 * 构建出一棵树，
 * 树上节点按照原数组的索引(key)来看是一棵二叉搜索树 
 * (二叉搜索树概念：所有节点左子树上的值均小于它自己，所有节点右孩子上的值均大于它自己)
 * 树上节点按照原数组的值(value)来看是一个(小/大)根堆
 * 建树复杂度O(n)
 * 讲解链接:https://www.bilibili.com/video/BV16eUFY8EXH/?spm_id_from=333.337.search-card.all.click&vd_source=392199501e15f6ebc0e43eab1920b5ab
 * 模板题:https://www.luogu.com.cn/problem/P5854
 */

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> ls(n + 1, 0), rs(n + 1, 0);
    stack<pair<int, int>> stk;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int lst = 0;
    /**
     * 如果栈为空，则压入元素作为根
     * 压入栈的元素为栈顶元素的右孩子(要求栈顶元素的val小于压入栈元素的val)
     * 如果不满足栈顶元素val小于压入栈元素的val，则要进行弹出操作
     * 最后弹出的元素将作为压入栈元素的左孩子
     */
    for (int i = 1;i <= n;i ++) {
        lst = 0;
        if (stk.empty()) {
            stk.push({i, a[i]});
        } else {
            while (!stk.empty() && stk.top().y > a[i]) {
                lst = stk.top().x;
                stk.pop();
            }
            if (stk.empty()) {
                ls[i] = lst;
                stk.push({i, a[i]});
            } else {
                rs[stk.top().x] = i;
                ls[i] = lst;
                stk.push({i, a[i]});
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        cout << ls[i] << ' ';
    }
    cout << '\n';
    for (int i = 1;i <= n;i ++) {
        cout << rs[i] << ' ';
    }
    cout << '\n';
}