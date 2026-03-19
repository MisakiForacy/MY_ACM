# Codeforces Round 960 (Div. 2)
## A. Submission Bait
* 题意：轮流取数，取的数必须大于等于先前取的数，直至无法取数，问先取数的一方能否有必胜的策略
* 从最大的数开始分析，如果最大的数的数量为偶数，先取了最大的数的一方一定会输，所以获胜的策略是去寻找个数为奇数的数
* 存一个桶，统计每个数出现的次数，若存在奇数则YES，反之NO
**ex.** 不要以为题目很水就盲目提交，wa是因为只判断了最大数的个数奇偶性，而忽略了更小的数也有机会时先手获胜的机会
**ex.** 代码很简单就不贴了

## B. Array Craft
* 题意：给出序列长度n，前缀和最大的索引位置x，后缀和最大的索引位置y，构造一个只含-1，1的数列满足n，x，y，且x>y
* 前缀和与后缀和概念
* 只要满足从1到x递增，从y到n递减即可，最简单的方法就是使前缀和的最大位置为x-y,后缀和同样是x-y，也就是说，只要让**不在**[y,x]范围内的前后缀和都为0
**ex.** 感谢***聪明大方，人美心善***的**Bigarade**同学提出的反例，计算缀数和时务必考虑小于0的情况！！！！！
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,y;
        cin >> n >> x >> y;
        vector<int>ar(n+1,1);
        for (int i=y-1;i>=1;i-=2){
            ar[i] = -1;
        }
        for (int i=x+1;i<=n;i+=2){
            ar[i] = -1;
        }
        for (int i=1;i<=n;i++){
            cout << ar[i] << " \n"[i==n];
        }
    }
}
~~~

## C. Mad MAD Sum
* 题意：$MAD(array)$为$array$中出现过两个及以上的最大的数，给出一个长度为$n$的数组$a$，先使$sum=sum+\Sigma(array)$构造数组$b$，再使$b_i = MAD(a_1\dots a_i)$，直至$a$所有数都为0
* 先用最最最最最暴力的方法打一遍，虽然Time limit exceeded on test 3，但能保证没悟错题意，例如
  2 2 3经历三次循环会变成
  0 <font color = #FF0000>2</font> <font color = #00FF00>2</font>
  0 0 <font color = #FF0000>2</font>
  0 0 0
  很容易发现：
   1. n最大可以取$2*10^5$，如果暴力解题复杂度为$O(n^2)$
   2. 只需经过一次循环，数组$a$一定会变成递增
   3. 2这个数被重复计算了多次，可以从中发现规律抛去不必要的循环
* 根据上述的第二个发现，我们可以只对$a$进行一次循环变成$b$={0,2,2}，然后再遍历$b$，如果$b_i$在$b$中不止出现了一次，则将$b_i$更新为$b_i*(n-i+1)$，否则不更新，最后把$sum$加上$\Sigma(b)$即可
* 但是！
* 但是！
* 但是！
* **这样写却会WA！**
* 为什么呢，我们可以这样造一组数据
  1 1 2 3 2 3
  对其进行模拟，结果如下
  0 <font color = #FF0000>1</font> <font color = #00FF00>1</font> <font color = #0000FF>1</font> <font color = #FF0000>2</font> <font color = #00FF00>3</font>
  0 0 <font color = #FF0000>1</font> <font color = #00FF00>1</font> <font color = #0000FF>1</font> <font color = #FF00FF>1</font>
  0 0 0 <font color = #FF0000>1</font> <font color = #00FF00>1</font> <font color = #0000FF>1</font>
  0 0 0 0 <font color = #FF0000>1</font> <font color = #00FF00>1</font>
  0 0 0 0 0 <font color = #FF0000>1</font>
* 多出了一个1。。。那该怎么办呢，原来我们只对$a$循环一次得出$b$，但是无法保证$b$中一定会成对出现数字，所以有可能会像上述样例一样多出一个墙角。那如果再对第一次循环得出的$b$再循环一次，**这样就可以保证第二次循环之后所剩下的数一定是在第一次循环之后仍然成对出现的数**，接下来在用上述公式更新$b_i$即可，最后求和
* **记得开long long**
~~~cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int nn[N],nnn[N];
int main(){
    int T,t=0;
    cin >> T;
    while (T--){
        t ++;
        ll n,mx = 0,sum = 0;
        cin >> n;
        vector<ll>ar(n),b(n+1,0),c(n);
        memset(nn,0,sizeof(nn));
        memset(nnn,0,sizeof(nnn));
        for (int i=0;i<2;i++){
            mx = 0;
            memset(nn,0,sizeof(nn));
            for (int j=0;j<n;j++){
                if (i==0) cin >> ar[j];
                sum += ar[j];
                nn[ar[j]] ++;
                if (nn[ar[j]]>=2){
                    mx = max(mx,ar[j]);
                }
                b[j] = mx;
                if (i==1) nnn[b[j]]++;
                ar[j] = b[j];
            }
        }
        for (int i=0;i<n;i++){
            if (nnn[b[i]]>1){
                b[i] *= (n-i);
            }
            sum += b[i];
        }
        cout << sum << '\n';
    }
}
~~~