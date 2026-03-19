# 简单数学题、数组字符串练习2
### WERTYU
* **题意**：有个人敲键盘会往右敲一位，比如把A敲成S，现在要求我们把实际的字符串转换成他想敲的字符串
* **hint**：只会存在数字和大写字母，我们只需要找到该字符出现在键盘的哪一行，然后再找到它索引的前一位字符，暴力枚举即可
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    map<string,string>mp;
    string l1 = "1234567890-=";
    string l2 = "QWERTYUIOP[]\\";
    string l3 = "ASDFGHJKL;'";
    string l4 = "ZXCVBNM,./";
    while (getline(cin,s)){
        string ans = "";
        for (int i=0;i<s.length();i++){
            if (l1.find(s[i])<=l1.length()){
                ans.push_back(l1[l1.find(s[i])-1]);
            } else if (l2.find(s[i])<=l2.length()){
                ans.push_back(l2[l2.find(s[i])-1]);
            } else if (l3.find(s[i])<=l3.length()){
                ans.push_back(l3[l3.find(s[i])-1]);
            } else if (l4.find(s[i])<=l4.length()){
                ans.push_back(l4[l4.find(s[i])-1]);
            } else{
                ans.push_back(s[i]);
            }
        }
        cout << ans << '\n';
    }
}
~~~
### Palindromes
* 题意：给定一个字符串，判定他是否为回文串或是镜像字符串
* **hint 1**: 回文串的定义，即从后往前读和从前往后读的结果是相同的字符串，例如ABCBA
* **hint 2**: 镜像字符串的定义，将从后往前数和从前往后数相同索引的字符换成其对应的镜像字符，例如E的镜像字符为3，那么E3就为一个镜像字符串
* 分别用两个函数判断字符串的性质，我用了is_pal和is_mir，你们随意
~~~cpp
#include <bits/stdc++.h>
using namespace std;
map<char,char>mp;
void init(){
	mp['A'] = 'A', mp['E'] = '3', mp['H'] = 'H', mp['I'] = 'I';
	mp['J'] = 'L', mp['L'] = 'J', mp['M'] = 'M', mp['O'] = 'O';
	mp['S'] = '2', mp['T'] = 'T', mp['U'] = 'U', mp['V'] = 'V';
	mp['W'] = 'W', mp['X'] = 'X', mp['Y'] = 'Y', mp['Z'] = '5';
	mp['1'] = '1', mp['2'] = 'S', mp['3'] = 'E', mp['5'] = 'Z';
	mp['8'] = '8', mp['0'] = '0';
}
bool is_pal(string s){
	int len = s.length();
	for (int i=0;i<len/2;i++){
		if (s[i]!=s[len-i-1]){
			// cout << s[i] << ' ' << s[len-i-1] << '\n';
			return 0;
		}
	}
	return 1;
}
bool is_mir(string s){
	int len = s.length();
	for (int i=0;i<len/2;i++){
		if (s[i]!=mp[s[len-i-1]]){
			return 0;
		}
	}
	if (len&1){
		if (s[len/2]!=mp[s[len/2]]){
			return 0;
		}
	}
	return 1;
}
int main(){
	string s;
	init();
	while (cin >> s){
		if (is_pal(s)&&is_mir(s)){
			cout << s << " -- is a mirrored palindrome.\n";
		} else if ((!is_pal(s))&&is_mir(s)){
			cout << s << " -- is a mirrored string.\n";
		} else if (is_pal(s)&&(!is_mir(s))){
			cout << s << " -- is a regular palindrome.\n";
		} else{
			cout << s << " -- is not a palindrome.\n";
		}
		cout << '\n';
	}
}
~~~
### Master-Mind Hints
* 题意：给定一个数列，作为样本，然后每输入一行就将其与样本进行比较，输出$$(与样本中完全匹配的数字数量,样本中存在但并不完全匹配的数字数量)$$
* 枚举即可，注意格式
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,r=0;
	while (cin >> n){
		if (!n) break;
		cout << "Game " << ++r << ":\n";
		vector<int>sample(n);
		vector<int>compare(n);
		for (int i=0;i<n;i++){
			cin >> sample[i];
		}
		while (cin >> compare[0]){
			map<int,int>mp;
			int cnt = 0, sam = 0;
			for (int i=1;i<n;i++){
				cin >> compare[i];
			}
			if (!compare[0]) break;
			for (int i=0;i<n;i++){
				if (sample[i] != compare[i]){
					mp[sample[i]] ++;
				} else{
					cnt ++;
				}
			}
			for (int i=0;i<n;i++){
				if (sample[i]!=compare[i]){
					if (mp[compare[i]]>0){
						mp[compare[i]]--;
						sam ++;
					}
				}
			}
			cout << "    (" << cnt << ',' << sam << ")\n";
		}
	}
}
~~~
### Digit Generator
* **题意：** 给定一个数字n，问能否找到一个数m，使m各个位数上的数相加和为n
* **hint 1:** 枚举，但是，并不必要从一开始枚举，一个三位数，其最坏情况为各个位置上都为9，和为27，所以对于一个三位数，我们只需要从n-27枚举到n即可，四位数同理，从n-36开始枚举，可以极大优化程序循环次数
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ok = 0;
        cin >> n;
        int len = to_string(n).length();
        for (int i=n-len*9;i<=n;i++){
            int s = 0;
            int ll = to_string(i).length();
            for (int j=0;j<ll;j++){
                s += to_string(i)[j]-'0';
            }
            if (i+s == n){
                cout << i << '\n';
                ok = 1;
                break;
            }
        }
        if (!ok){
            cout << 0 << endl;
        }
    }
}
~~~
### Score
* **题意：** OOXX，O表示正确，X表示错误，如果正确，该题的得分会在上一题的基础上加一，如果错误，得分归零，计算总分
* **hint 1:** 维护一个数组即可，每判定一道题只需知道其上一题的得分即可
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while (T--){
		int sum = 0;
		string s;
		cin >> s;
		vector<int>a(s.length()+1,0);
		for (int i=0;i<s.length();i++){
			if (s[i]=='O'){
				a[i+1] = a[i] + 1;
			}
			sum += a[i+1];
		}
		cout << sum << '\n';
	}
}
~~~
### Molar mass
* **题意：** 给定一个化学物质方程，计算该物质的质量
* **hint 1：** 首先用map将每个元素的质量记录下来，然后遍历字符串，将该元素的质量乘上它出现的次数，最后计算总和即可
* **hint 2:** 有些元素后面可能不会有数字出现，乘一即可
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n;
	while (n--){
		cin >> s;
		map<char,double>mp;
		map<char,double>mm;
		mm['C'] = 12.01, mm['H'] = 1.008;
		mm['O'] = 16.00, mm['N'] = 14.01;
		for (int i=0;i<s.length()-1;i++){
			if (isalpha(s[i])&&isalpha(s[i+1])){
				mp[s[i]] ++;
			} else if (isalpha(s[i])){
				string num = "";
				int j = i;
				while (isdigit(s[++j])) num.push_back(s[j]);
				mp[s[i]] += stod(num);
				i = j-1;
			}
		}
		if (isalpha(s[s.length()-1])){
			mp[s[s.length()-1]] ++;
		}
		double sum = 0;
		for (auto [k,v]:mp){
			sum += v * mm[k];
		}
		cout << fixed << setprecision(3) << sum << '\n';
	}
}
~~~
### Digit Counting
* **题意：** 计数器，统计从1到n的所有数字中，0~9出现的次数
* **hint 1：**枚举，然后将数字转换成字符串，再拼接，最后用map统计即可
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		int n;
		string str = "";
		cin >> n;
		map<char,int>mp;
		for (int i=1;i<=n;i++){
			str.append(to_string(i));
		}
		for (int i=0;i<str.length();i++){
			mp[str[i]-'0']++;
		}
		for (int i=0;i<=9;i++){
			cout << mp[i] << " \n"[i==9];
		}
	}
}
~~~
### Periodic Strings
* **题意：** 找一个字符串的最短循环周期
* **hint 1:** 由于字符串的长度不会很大，从1开始枚举周期即可，如果满足则break输出，不满足则回溯，周期加一进行下一轮枚举
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		int ok = 1;
		string s;
		cin >> s;
		s = ' ' + s;
		for (int i=1;i<=s.length();i++){
			if (!((s.length()-1)%i)){
				ok = 1;
				string str = s.substr(1,i);
				for (int j=i+1;j<s.length();j+=i){
					if (s.substr(j,i)!=str){
						ok = 0;
					}
				}
				if (ok){
					cout << i << '\n';
					break;
				}
			}
		}
		if (T) cout << '\n';
	}
}
~~~
### All in All
* **题意：** 给定字符串s和字符串t，问能否删除字符串t中的任意字符使之变成字符串s，不能改变顺序
* **hint 2:** 维护一个双指针，使第一个指针p1在字符串s上遍历，第二个指针p2在字符串t上遍历如果p2指向的字符与p1指向的字符相同，则同时加加指针p1p2，如果不同，则加加p2，直至找到相同字符，若始终无法找到，则输出NO
~~~cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	string t,s;
	while (cin >> t >> s){
		int l1 = t.length();
		int l2 = s.length();
		int p1,p2 = 0,ok = 1;
		for (p1=0;p1<l1;p1++){
			while (p2<l2 && s[p2]!=t[p1]) p2 ++;
			if (p2==l2){
				ok = 0;
				break;
			}
			p2 ++;
		}
		cout << (ok?"Yes\n":"No\n");
	}
}
~~~