# Problem G. Phoenix 的分配

Phoenix 有一个只包含小写拉丁字母的字符串 $s$。他想将字符串中的所有字母分成 $k$ 个\textbf{非空}字符串 $a_1, a_2, \dots, a_k$，使得字符串 $s$ 中的每个字母恰好分配到一个字符串 $a_i$ 中。字符串 $a_i$ \textbf{不需要}是 $s$ 的子串。Phoenix 可以随意分配 $s$ 中的字母，并且可以在每个字符串 $a_i$ 内部任意重排字母。

例如，如果 $s = $ \t{baba} 且 $k=2$，Phoenix 可以通过多种方式分配字符串中的字母，例如：
\begin{itemize}
\item \t{ba} 和 \t{ba}
\item \t{a} 和 \t{abb}
\item \t{ab} 和 \t{ab}
\item \t{aa} 和 \t{bb}
\end{itemize}

但以下分配方式是无效的：
\begin{itemize}
\item \t{baa} 和 \t{ba}
\item \t{b} 和 \t{ba}
\item \t{baba} 和空字符串（$a_i$ 必须是非空的）
\end{itemize}

Phoenix 想将字符串 $s$ 中的字母分配到 $k$ 个字符串 $a_1, a_2, \dots, a_k$ 中，以\textbf{最小化}它们中字典序最大的字符串，即最小化 $max(a_1, a_2, \dots, a_k)$。请你帮助他找到最优的分配方式，并输出 $max(a_1, a_2, \dots, a_k)$ 的最小可能值。

字符串 $x$ 的字典序小于字符串 $y$，当且仅当：
- $x$ 是 $y$ 的前缀且 $x \ne y$；
- 或者存在一个下标 $i$（$1 \leq i \leq min(|x|, |y|)$），使得 $x_i < y_i$，并且对于每个 $j$（$1 \leq j < i$），都有 $x_j = y_j$。
其中 $|x|$ 表示字符串 $x$ 的长度。

\InputFile
输入包含多个测试用例。第一行包含一个整数 $t$（$1 \leq t \leq 1000$）~--- 测试用例的数量。每个测试用例包含两行。

每个测试用例的第一行包含两个整数 $n$ 和 $k$（$1 \leq k \leq n \leq 10^5$）~--- 字符串 $s$ 的长度和 Phoenix 想要分配的非空字符串的数量。

每个测试用例的第二行包含一个长度为 $n$ 的字符串 $s$，仅由小写拉丁字母组成。

保证所有测试用例中 $n$ 的总和不超过 $10^5$。

\OutputFile
输出 $t$ 个答案~--- 每个测试用例输出一行。第 $i$ 个答案应为第 $i$ 个测试用例中 $max(a_1, a_2, \dots, a_k)$ 的最小可能值。

\Examples
```
6
4 2
baba
5 2
baacb
5 3
baacb
5 3
aaaaa
6 4
aaxxzz
7 1
phoenix
```

```
ab
abbc
b
aa
x
nehinopx
```

\Note
在第一个测试用例中，一种最优的分配方式是将 \t{baba} 分配为 \t{ab} 和 \t{ab}。

在第二个测试用例中，一种最优的分配方式是将 \t{baacb} 分配为 \t{abbc} 和 \t{a}。

在第三个测试用例中，一种最优的分配方式是将 \t{baacb} 分配为 \t{ac}、\t{ab} 和 \t{b}。

在第四个测试用例中，一种最优的分配方式是将 \t{aaaaa} 分配为 \t{aa}、\t{aa} 和 \t{a}。

在第五个测试用例中，一种最优的分配方式是将 \t{aaxxzz} 分配为 \t{az}、\t{az}、\t{x} 和 \t{x}。

在第六个测试用例中，一种最优的分配方式是将 \t{phoenix} 分配为 \t{ehinopx}。
