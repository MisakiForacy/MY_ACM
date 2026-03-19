# AtCoder Beginner Contest 360
## A - A Healthy Breakfast
- 读取字符串，遍历，若$S_i$取得 R 和 M 任意之一结束遍历，先取得 R，输出Yes反之No
## B - Vertical Reading
- 由于数据范围不严谨，可使用暴力枚举得出w，c解决此问题
- $\because w<|s|\therefore w$不得超过$|s|-1$
- 自定义check函数，用于判定该w和c是否满足条件，同样遍历即可
- 注意：在check的过程中索引值有可能会超出向量的范围，此时需要将超出范围的字符替换成空格再进行比较
## C - Move It
- 贪心
- 要让成本最小，就不能移动每个箱子中质量最大的物品，根据该思路，只需求出每个超过一件物品的箱子中除质量最大的物品质量之和即可，最后将每个箱子的和累加得出最终答案