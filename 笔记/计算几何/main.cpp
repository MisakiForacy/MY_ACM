#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Point
{
    LL x, y;
    bool operator < (const Point&b) const { return x > b.x;}
    Point (LL x_ = 0, LL y_ = 0) { this->x = x_, this->y = y_;}
    Point operator + (const Point &b) const { return Point (x + b.x, y + b.y);}
    Point operator - (const Point &b) const { return Point (x - b.x, y - b.y);}
    LL operator * (const Point &b) const { return x * b.x + y * b.y;}   // 点积
    LL operator ^ (const Point &b) const { return x * b.y - b.x * y;}   // 叉积
};

typedef Point Vector;

int check (Point a, Point b, Point c) {
    Vector A = a - b;
    Vector B = c - a;
    LL cross = A ^ B;
    // 叉积大于0表示∠bac小于180°
    // 叉积等于0表示∠bac等于于180°
    // 叉积小于0表示∠bac大于180°
    return cross >= 0;  
}