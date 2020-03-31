# Educational DP Contest 题目推荐

#### A. Frog 1

- 基本的递推题

#### B. Frog 2

- 基本的递推题

#### C. Vacation

- 基本的递推题

#### D. Knapsack 1

- 基本的背包

#### E. Knapsack 2

- 不太常见的背包

#### F. LCS

- 动态规划时记录转移的位置

- 通过动态规划数组进行逆推

#### G. Longest Path

- DP 就是根据拓扑排序做递推

#### H. Grid 1

- 基本的递推题

- 小学奥数

#### I. Coins

- 概率 DP

- 用两个维度分别记录硬币数和正面朝上的次数

#### J. Sushi

- 概率 DP

- 有一点像马尔科夫链

- 写成记忆化搜索会比较直观

#### K. Stones

- 必胜态

- 必败态

#### L. Deque

- 一个人的先手状态是另一个人的后手状态

#### M. Candies

- 前缀和（部分和）优化

- 本质上还是个背包

#### N. Slimes

- 区间 DP

- 注意计算的顺序

#### O. Matching

- 状态压缩 DP

#### P. Independent Set

- 树形 DP

- 给定的是无根树，需要指定一个根（例如 1 号节点）

#### Q. Flowers

- 树状数组（或任何区间数据结构）优化 DP

- 一般会有 `f[i] = max(f[l], f[l + 1], ..., f[r]) + a[i]` 的形式

#### R. Walk

- 转换为矩阵乘法

- 使用快速幂优化

#### S. Digit Sum

- 数位 DP

- 状态一般可以表示为 `dp[i][stats][bound]`

#### T. Permutation

- LeetCode 903

#### U. Grouping

- 状态压缩 DP

- 枚举子集的奇技淫巧

    - `for (int subset = mask; subset; subset = (subset - 1) & mask)`

#### V. Subtree

- 树形 DP

- 换根

#### W. Intervals

- `dp[i] = max{dp[j] + (所有左端点大于 j 并且右端点大于等于 i 的区间的权值之和)}`

- 记 `g[j] = max{...}` 中的 `...`，实时维护 `g[j]`

    - 有区间以 `i` 为左端点：所有的 `g[j]` 加上权值

    - 有区间以 `i` 为右端点：所有满足 `j < 左端点` 的 `g[j]` 减去权值

- 使用带懒标记的线段树

#### X. Tower

- [特殊的排序技巧](https://codeforces.com/blog/entry/63533)

- 排完序之后就是背包了