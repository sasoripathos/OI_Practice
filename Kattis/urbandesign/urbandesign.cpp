#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n, m;
struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
    Point(const Point &i) : x(i.x), y(i.y) {}

    Point operator - (const Point &i) const {
        return Point(x - i.x, y - i.y);
    }

} a[20002];

ll cross(Point i, Point j) {
    return i.x * j.y - i.y * j.x;
}

void check(Point p, Point q) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (cross(p - a[i * 2], p - a[i * 2 + 1]) * cross(q - a[i * 2], q - a[i * 2 + 1]) <= 0)
            cnt ++;
    }
    if (cnt % 2) puts("different");
    else puts("same");
}
int main() {
    scanf ("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%lld%lld%lld%lld",&a[i * 2].x, &a[i * 2].y, &a[i * 2 + 1].x, &a[i * 2 + 1].y);
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        ll x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        check(Point(x1, y1), Point(x2, y2));
    }
    return 0;
}