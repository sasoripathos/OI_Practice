#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define inf 100000000
using namespace std;
int p, q, f[101][101], my[101][2], sis[2][101];
int myval(int s, int t, int row) {
    if (my[row][s % 2] == 0) return 0;
    else if ((t - s + 1) % 2 == 0) return 0;
    else return my[row][s % 2];
}

int sisval(int s, int t, int col) {
    int v0 = sis[0][q-1] - sis[0][col], v1 = sis[1][q-1] - sis[1][col];
    int v = (s % 2) ? v1 : v0;
    if (v == 0) return 0;
    else if ((t - s + 1) % 2 == 0) return 0;
    else return v;
}

int dfs(int x, int y) {
    if (x == -1 || y == q) return 0;
    if (f[x][y] != -inf) return f[x][y];
    for (int i=y; i<q; i++) {
        int v1 = myval(y, i, x), opval = inf;
        for (int j=x; j>=0; j--) {
            int v2 = sisval(j, x, i);
            opval = min(opval, v1 - v2 + dfs(j - 1, i + 1));
        }
        f[x][y] = max(f[x][y], opval);
    }
    return f[x][y];
}
void pre() {
    for (int i=0; i<p; i=i+2)
        my[i][0] = 1, my[i][1] = -1;
    for (int i=0; i<q; i=i+2)
        sis[0][i] = 1, sis[1][i] = -1;
    for (int i=0; i<p; i++)
    for (int j=0; j<q; j++)
        f[i][j] = -inf;
}
int main() {
    cin >> p >> q;
    pre();
    cout << dfs(p - 1, 0) << endl;
}