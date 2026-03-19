#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
using LL = long long;

int check(vector<int> &a) {
    return (*max_element(a.begin(), a.end()) != 0);
}

int main() {
    int n = 5;
    vector<int> a = {0, 4, 3, 5, 6, 7};
    std::srand((unsigned)std::time(nullptr));
#ifdef _WIN32
    // 对于 GBK 环境不设置 UTF-8
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);
#endif
    int round = 0;
    printf("规则：两人轮流取石子，每次从任意一堆取任意个石子（不能为0），先取完的获胜\n");
    while (check(a)) {
        cout << "索引：";
        for (int i = 1;i <= n;i ++) cout << i << ' ';
        cout << "\n石子：";
        for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
        cout << '\n';
        if ((++ round) & 1) {
            int x = 0, y = -1;
            cout << "玩家A回合：\n";
            while (a[x] == 0) {
                printf("哪一堆：（1 ~ %d）: ", n);
                scanf("%d", &x);
            }
            while (y > a[x] || y <= 0) {
                printf("取几个：（1 ~ %d）: ", a[x]);
                scanf("%d", &y);
            }
            a[x] -= y;
        } else {
            cout << "玩家B回合（电脑）：\n";
            // 随机选择一个非空堆
            vector<int> idx;
            for (int i = 1; i <= n; ++i) if (a[i] > 0) idx.push_back(i);
            int xi = idx[std::rand() % idx.size()];
            int y = std::rand() % a[xi] + 1;
            printf("电脑选择哪一堆：%d\n", xi);
            printf("电脑取几个：%d\n", y);
            a[xi] -= y;
        }
    }
    if (round & 1) {
        printf("A获胜");
    } else {
        printf("B获胜");
    }
    getchar();
    getchar();
    getchar();
}
