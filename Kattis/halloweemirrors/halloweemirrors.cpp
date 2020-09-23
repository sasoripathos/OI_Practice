#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator + (const Point &p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (const Point &p) {
        return Point(x - p.x, y - p.y);
    }
};

double dot(const Point &p, const Point &q) {
    return p.x * q.x + p.y * q.y;
}

int n, m;
struct Mirror {
    Point x, y;
} mir[100];

bool check(Mirror mr, Point p) {
    double r = dot(p - mr.x, mr.y - mr.x) / dot (mr.y - mr.x, mr.y - mr.x);
    //cout << r << " --- ";
    if(r < 0 || r > 1) return false;
    else return true;
}

int main() {
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        double x1, y1, x2, y2;
        for (int i=0; i<n; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            mir[i].x.x = x1; mir[i].x.y = y1;
            mir[i].y.x = x2; mir[i].y.y = y2;
        }
        scanf("%d", &m);
        for (int i=0; i<m; i++) {
            scanf("%lf%lf", &x1, &y1);
            int ans = 0;
            for (int j=0; j<n; j++) {
                if (check(mir[j], Point(x1, y1))) ans++;
            }
            printf("%d\n", ans);
        }
        puts("");
    }
    return 0;
}
