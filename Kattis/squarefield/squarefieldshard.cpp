#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 1000000000000
using namespace std;
int T, n, m;
int x[16], y[16];
int cov(int x1, int y1, int x2, int y2, int ori, int r) {
    int xl, xr, yb, yt;
    if (ori == 0) {
        xl = x1; xr = x1 + r; yb = y2 - r, yt = y2;
    }
    if (ori == 1) {
        xl = x2 - r; xr = x2; yb = y2 - r, yt = y2;
    }
    if (ori == 2) {
        xl = x1; xr = x1 + r; yb = y1, yt = y1 + r;
    }
    if (ori == 3) {
        xl = x2 - r; xr = x2; yb = y1, yt = y1 + r;
    }
    int ans = 0;
    printf("%d (%d %d) (%d %d) ori %d covers: ", r, x1, y1, x2, y2, ori);
    for (int i=0; i<n; i++) {
        if (x[i] < xl || x[i] > xr || y[i] < yb || y[i] > yt) continue;
        ans += (1 << i);
        printf("%d ", i);
    }
    puts("");
    return ans;
}
bool check(int r, int inq, int k) {
    int maxx = -65000, minx = 65000, miny = 65000, maxy = -65000;
    for (int i=0; i<n; i++) {
        if((1 << i) & inq) continue;
        maxx = max(maxx, x[i]);
        minx = min(minx, x[i]);
        maxy = max(maxy, y[i]);
        miny = min(miny, y[i]);
    }
    if (maxx - minx <= r && maxy - miny <= r) return true;
    else if (k == 1) return false;
    for (int i=0; i<4; i++) {
        int newinq = inq | cov(minx, miny, maxx, maxy, i, r);
        if (check(r, newinq, k-1)) return true;
    }
    return false;
}
void doit(int casen) {
    int l=1, r=65000, mid, ans;
    while (l<=r) {
        mid = (l + r) >> 1;
        if(check(mid, 0, m)) {
            ans = mid;
            r = mid - 1;
            //printf("%d ok\n", ans);
        } else {
            l = mid + 1;
            //printf("%d not ok\n", mid);
        }
    }
    printf("Case #%d: %d\n", casen, ans);
}
int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> x[i] >> y[i];
        doit(t);
    }
    return 0;
}