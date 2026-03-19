# Codeforces Round 943 (Div. 3)
## A. Maximize?
You are given an integer $x$. Your task is to find any integer $y$ $(1\le y\lt x)$ such that $\gcd(x,y)+y$ is maximum possible.  
**Note that if there is more than one $y$ which satisfies the statement, you are allowed to find any.**  
$\gcd(a,b)$ is the Greatest Common Divisor of $a$ and $b$. For example, $\gcd(6,4)=2$.  
### Input
The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.  
Each of the following $t$ lines contains a single integer $x$ ($2 \le x \le 1000$).  
### Output
For each test case, output any $y$ ($1 \le y \lt x$), which satisfies the statement.  
### Example
**Input**  
>7<br>10<br>7<br>21<br>100<br>2<br>1000<br>6<br>

**Output**

>5<br>6<br>18<br>98<br>1<br>750<br>3<br>

### 思路
1. 题意：找到一个小于x的值y，使$gcd(x,y)+y$ 取得最大值
2. $$\because \space gcd(x,x) = x，gcd(x,x-1) = 1$$
   $$\therefore \space gcd(x,x-1)+x-1 = x $$
   $$\therefore \space y=x-1,gcd(x,y)+y取得max$$
### Code
~~~cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x;
        cout << x-1 << endl;
    }
    return 0;
}
~~~
## B. Prefiquence
You are given two binary strings $a$ and $b$. A binary string is a string consisting of the characters '0' and '1'.

Your task is to determine the maximum possible number $k$ such that a prefix of string $a$ of length $k$ is a subsequence of string $b$.

A sequence $a$ is a subsequence of a sequence $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) elements.  
### Input 
The first line consists of a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.  
The first line of each test case contains two integers $n$ and $m$ ($1\le n,m \le 2 \cdot 10^5$) — the length of string $a$ and the length of string $b$, respectively.  
The second line of each test case contains a binary string $a$ of length $n$.  
The third line of each test case contains a binary string $b$ of length $m$.  
It is guaranteed that the sum of values $n$ over all test cases does not exceed $2 \cdot 10^5$. Similarly, the sum of values $m$ over all test cases does not exceed $2 \cdot 10^5$.  
### Output  
For each test case, output a single number — the maximum $k$, such that the first $k$ characters of $a$ form a subsequence of $b$.
### Example
**Input**
>6<br>5 4<br>10011<br>1110<br>3 3<br>100<br>110<br>1 3<br>1<br>111<br>4 4<br>1011<br>1111<br>3 5<br>100<br>11010<br>3 1<br>100<br>0<br>

**Output**
>2<br>2<br>1<br>1<br>3<br>0<br>
### 思路
1. 题意：给定两个包含01的字符串，找到最长公共子序列
2. 问题类型：贪心，双指针
3. 以字符串a作为大循环，从$b_k$开始遍历，直到$a_i$出现
### Code
~~~cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
string s1,s2;
bool flg;
i64 t,a,b,i,j,k,cnt;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    flg = true;
    cin >> a >> b;
    cin >> s1 >> s2;
    k = 0, cnt = 0;
    for(i=0;i<a;i++){
        while(k<b){
            if(s1[i] == s2[k]){
                cnt++;
                k++;
                break;
            }
            k++;
        }
    }
    cout << cnt << endl;
}
~~~
## C. Assembly via Remainders
### 思路