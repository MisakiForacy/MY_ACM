#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
int main() {
    string s;
    while (getline(cin, s) && s != "0") {
        stack<double> nums;
        stringstream s1(s); 
        while (s1 >> s) { 
            if (isdigit(s[0])) {
                stringstream s2;
                double num;
                s2 << s;
                s2 >> num;
                nums.push(num);
            }
            else {
                if (s == "+" || s == "-") {
                    if (s == "-") {
                        double num;
                        s1 >> num;
                        nums.push(num * -1);
                    }
                } else {
                    double num;
                    s1 >> num;
                    double num1 = nums.top();
                    nums.pop();
                    if (s == "*") {
                        nums.push(num1 * num);
                    }
                    else {
                        nums.push(num1 / num);
                    }
                }
            }
        }
        double num = nums.top();
        nums.pop();
        while (nums.size()) {
            double num1 = nums.top();
            nums.pop();
            num = num + num1;
        }
        printf("%.2lf\n", num);
    }

    return 0;
}