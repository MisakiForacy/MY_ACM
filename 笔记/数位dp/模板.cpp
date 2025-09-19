int cal(int num){
    vector<int> p;
    while (num){
        p.push_back(num % 10);
        num /= 10;
    }
    p.push_back(0);
    reverse(p.begin(), p.end());
    int len = p.size() - 1;
    int dp[len + 1][2][10];
    memset(dp, 0, sizeof dp);
    for (int i = 1;i <= len;i ++){
        for (int x = 1;x <= (i == 1 ? p[i] : 9);x ++){ // 
            dp[i][(i == 1 && x == p[i])][x] ++;
        }
        for (int limit = 0;limit <= 1;limit ++){
            for (int x = 0;x <= (limit ? p[i] : 9);x ++){
                for (int last = 0;last <= 9;last ++){
                    dp[i][(limit && x == p[i])][x] += dp[i - 1][limit][last];
                }
            }
        }
    }
    LL sum = 0;
    for (int i = 0;i <= 9;i ++){
        sum += dp[len][0][i];
        sum += dp[len][1][i];
    }
    return sum;
}