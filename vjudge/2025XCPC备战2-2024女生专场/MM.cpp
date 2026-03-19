#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 200000;
vector<int> tree[MAX_N + 1];
int subtree_size[MAX_N + 1];

bool canCover(int n, int maxLength) {
    // 用队列来模拟 BFS，从叶节点开始验证
    queue<int> q;
    vector<int> depth(n + 1, 0); // 每个节点的深度
    vector<int> visited(n + 1, 0);
    int max_depth = 0;

    // 找到所有叶节点并初始化深度
    for (int i = 1; i <= n; ++i) {
        if (tree[i].size() == 0) { // 叶节点
            q.push(i);
            depth[i] = 1;
        }
    }

    // 从叶节点往上贪心覆盖
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int parent = subtree_size[node]; // 获取父节点
        if (parent == 0) continue;       // 根节点无需处理

        depth[parent] = max(depth[parent], depth[node] + 1);
        if (--visited[parent] == 0) { // 如果所有子节点都已访问
            q.push(parent);
        }

        // 如果深度超过了允许的最大长度，返回 false
        if (depth[parent] > maxLength) {
            return false;
        }
    }
    return true;
}

int solve(int n) {
    int left = 1, right = n, result = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCover(n, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        // 清空树
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
            subtree_size[i] = 0;
        }

        // 构建树
        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            tree[parent].push_back(i);
            subtree_size[i] = parent;
        }

        // 输出结果
        cout << solve(n) << endl;
    }
    return 0;
}