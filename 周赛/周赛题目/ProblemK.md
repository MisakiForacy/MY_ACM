# Problem K. Nastya 和游戏

Polycarp 得到一个长度为 $n$ 的数组 $a$，Polycarp 想玩一个游戏：选择一个子段，使得该子段所有元素的乘积等于其和乘以 $k$。

即对于子段 $a_l, a_{l+1}, \ldots, a_r$，满足 $a_l \times a_{l+1} \times \cdots \times a_r = (a_l + a_{l+1} + \cdots + a_r) \times k$。

请你帮 Polycarp 计算有多少个子段满足上述条件。

## 输入格式

第一行两个整数 $n, k$（$1 \leq n \leq 2 \times 10^5$，$1 \leq k \leq 10^5$）。
第二行 $n$ 个整数 $a_1, a_2, \ldots, a_n$（$1 \leq a_i \leq 10^8$）。

## 输出格式

输出满足条件的子段数量。

## 样例输入

```
1 1
1
4 2
6 3 8 1
```

## 样例输出

```
1
2
```
