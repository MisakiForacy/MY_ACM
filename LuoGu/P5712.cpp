#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    if(x>1)cout<<"Today, I ate " << x << " apples.";
    else if(x==1)cout << "Today, I ate 1 apple.";
    else cout << "Today, I ate 0 apple.";
    return 0;
}