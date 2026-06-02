#include <bits/stdc++.h>

using namespace std;

const long long Up = 1e9;

vector<long long> dp[11];
set<long long> result;
long long n;

int get_length(long long num)
{
    int length = 0;
    while (num > 0)
    {
        length += 1;
        num /= 10;
    }
    return length;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    dp[0].emplace_back(0);
    for (int index = 0;index < 10;index ++)
    {
        for (int current = 0;(1ll << current) <= Up;current ++)
        {
            int length = get_length(1ll << current);
            if (index + length > 10) break;
            for (long long exist : dp[index]) 
            {
                long long value = exist;
                for (int times = 0;times < length;times ++)
                {
                    value *= 10;
                }
                value += 1ll << current;
                dp[index + length].emplace_back(value);
                result.insert(value);
            }
        }
    }
    cin >> n;
    for (long long value : result) 
    {
        n --;
        if (n == 0) 
        {
            cout << value << '\n';
            return 0;
        }
    }
}