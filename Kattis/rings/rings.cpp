#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n, fa[100], w[100];
struct circle {
    double x, y, r;
} a[100];
void init() {
    for (int i=0; i<n; i++) {
        fa[i] = i;
        w[i] = 1;
        scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
    }
}
bool check(const struct circle &i, const struct circle &j) {
    double dis = sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
    double minr = i.r > j.r ? j.r : i.r, maxr = i.r > j.r ? i.r : j.r;
    if (dis > minr + maxr) return false;
    else if (dis + minr < maxr) return false;
    else return true;
}
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void doit() {
    int ans = 1;
    for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++) {
        if (check(a[i], a[j])) {
            int r1 = find(i), r2 = find(j);
            if (r1 != r2) {
                fa[r1] = r2; w[r2] += w[r1];
                ans = max(ans, w[r2]);
            }
        }
    }
    printf("The largest component contains %d ", ans);
    if (ans == 1) puts("ring.");
    else puts("rings.");
}
int main() {
    while (1) {
        scanf("%d", &n);
        if (n == -1) break;
        init();
        doit();
    }
    return 0;
}