#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m, xs, ys, xe, ye;
int xx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int yy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int qx[10001], qy[10001], ans[101][101];
bool check(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m || ans[x][y] >= 0) return false;
    else return true;
}
void bfs() {
    int t=0, w=1;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        ans[i][j] = -1;
    qx[t] = xs; qy[t] = ys; ans[xs][ys] = 0;
    while(t<w) {
        int cx = qx[t], cy = qy[t];
        t++;
        for (int i=0; i<8; i++) {
            int xt = cx + xx[i], yt = cy + yy[i];
            if (check(xt, yt)) {
                qx[w] = xt; qy[w] = yt; w++;
                ans[xt][yt] = ans[cx][cy] + 1;
                if(xt == xe && yt == ye) return;
            }
        }
    }
}
int main() {
    while(scanf("%d%d%d%d%d%d", &n, &m, &xs, &ys, &xe, &ye) != EOF) {
        bfs();
        if (ans[xe][ye] >= 0) printf("%d\n", ans[xe][ye]);
        else puts("impossible");
    }
    return 0;
}