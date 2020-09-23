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
int x[16], y[16], f[32800][16];
int edge(int t) {
    int minx=65000, maxx=-1, miny=65000, maxy=-1;
    for (int i=0; i<n; i++) {
        if ((1 << i) & t) {
            minx = minx < x[i] ? minx : x[i];
            maxx = maxx > x[i] ? maxx : x[i];
            miny = miny < y[i] ? miny : y[i];
            maxy = maxy > y[i] ? maxy : y[i];
        }
    }
    return max(maxx - minx, maxy - miny);
}
void dp(int casen) {
    for (int i=1; i<(1<<n); i++)
    for (int j=1; j<=m; j++)
        f[i][j] = 65000;
    for (int i=1; i<(1<<n); i++) {
        f[i][1] = edge(i);
    }
    for (int i=1; i<(1<<n); i++)
    for (int j=1; j<(1<<n); j++) {
        if ((j & i) != j || j == i) continue;
        for (int k=2; k<=m; k++) {
            f[i][k] = min(f[i][k], max(f[j][k-1], f[j ^ i][1]));
        }
    }
    printf("Case #%d: %d\n", casen, f[(1 << n) - 1][m]);
}
int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> x[i] >> y[i];
        dp(t);
    }
}