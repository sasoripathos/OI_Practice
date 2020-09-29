#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
#define inf 1e16
using namespace std;
int n, m, k1, k2, hd[452], zz, S, T;
struct edge {
    int t, c, nx;
    ll v;
} e[2202];

struct elem {
    int x, r, b;
    ll dis;

    elem(int x, int r, int b, ll dis) : x(x), r(r), b(b), dis(dis) {}

    bool operator < (const elem &i) const {
        return dis > i.dis; // inverse for priority queue
    }
};

priority_queue<elem> q;

void insert(int x, int y, ll v, int c) {
    e[++zz].t = y; e[zz].c = c; e[zz].v = v; e[zz].nx = hd[x]; hd[x] = zz;
    e[++zz].t = x; e[zz].c = c; e[zz].v = v; e[zz].nx = hd[y]; hd[y] = zz;
}

void dijkstra() {
    bool done[n+2][k1+2][k2+2];
    ll d[n+2][k1+2][k2+2];
    memset(done, 0, sizeof(done));
    for (int i=1; i<=n; i++)
    for (int j=0; j<=k1; j++)
    for (int k=0; k<=k2; k++)
        d[i][j][k] = inf;
    q.push(elem(S, 0, 0, 0));
    d[S][0][0] = 0;
    while (!q.empty()) {
        elem cur = q.top();
        q.pop();
        int x = cur.x, r = cur.r, b = cur.b;
        if (done[x][r][b]) continue;
        for (int i=hd[x]; i; i=e[i].nx) {
            int nr = r + (e[i].c == 1 ? 1 : 0), nb  = b + (e[i].c == 2 ? 1 : 0);
            if (nr > k1 || nb > k2) continue;
            if (d[e[i].t][nr][nb] > d[x][r][b] + e[i].v) {
                d[e[i].t][nr][nb] = d[x][r][b] + e[i].v;
                q.push(elem(e[i].t, nr, nb, d[e[i].t][nr][nb]));
            }
        }
        done[x][r][b] = true;
    }

    if (d[T][k1][k2] == inf) puts("-1");
    else cout << d[T][k1][k2] << endl;
}
int main() {
    cin >> n >> m >> k1 >> k2;
    for (int i=0; i<m; i++) {
        int x, y, c;
        ll v;
        cin >> x >> y >> v >> c;
        insert(x, y, v, c);
    }
    cin >> S >> T;
    dijkstra();
}