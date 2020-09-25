#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T, n, m, L, a[10000];
bool check(int v, int cur, int head, int i) {
    if (head == 0) {
        if (cur < n) return false;
        else return true;
    } else if (cur >= n) {
        return true;
    } else if (i == m) {
        return true;
    }
    if (a[i] - cur > v) {
        return check(v, a[i] - 1, head - 1, i);
    } else {
        while (a[i] <= cur + v && i<m) i++;
        return check(v, cur + v, head - 1, i);
    }
}
void doit() {
    int ans=n, l=1, r=n, mid;
    while(l<=r) {
        mid = (l+r) >> 1;
        if(check(mid, 0, L, 0)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &L);
        for (int i=0; i<m; i++) scanf("%d", &a[i]);
        doit();
    }
}