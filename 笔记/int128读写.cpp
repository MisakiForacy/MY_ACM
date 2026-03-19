using Z = __int128_t;

Z input() {
    string s;
    cin >> s;
    Z res = 0;
    for (int i = 0; i <= siz(s);i ++) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

void print(Z x) {
   if (x > 9) {
       print(x / 10);
   }
   putchar(x % 10 + '0');
}