#include <iostream>
#include <vector>
int main(){
    int x,y,count=0;
    std::vector<int>a;
    std::cin >> x >> y;
    for(int i=x+(x%4==0?0:(4-x%4));i<=y;i+=4)if(i%400==0||i%100!=0)a.push_back(i),count++;
    std::cout << count << std::endl;
    for(std::vector<int>::iterator it=a.begin();it!=a.end();it++)std::cout << *it << " ";
}