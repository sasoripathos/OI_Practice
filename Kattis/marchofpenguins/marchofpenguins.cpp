#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#define inf 100000000
using namespace std;
int n, hd[205], zz, S, T, tol, h[205];
double L;
struct Edge {
    int t, nx, v;
    Edge(int t, int nx, int v) : t(t), nx(nx), v(v) {}
};
struct Point{
    int x, y, p, l;
    Point(int x, int y, int p, int l) : x(x), y(y), p(p), l(l) {}
};
vector<Point> a;
vector<Edge> e;

void init() {
    scanf("%d%lf", &n, &L);
    for (int i=0; i<n; i++) {
        int x, y, p, l;
        scanf("%d%d%d%d", &x, &y, &p, &l);
        a.push_back(Point(x, y, p, l));
        tol += p;
    }
}

bool canJump (Point &i, Point &j) {
    double d = sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
    return d <= L;
}

void insert(int x, int y, int v) {
    int zz = e.size();
    e.push_back(Edge(y, hd[x], v)); hd[x] = zz;
    zz++;
    e.push_back(Edge(x, hd[y], 0)); hd[y] = zz;
}

void build() {
    memset(hd, 0, sizeof(hd));
    e.clear();
    e.push_back(Edge(0, 0, 0)); e.push_back(Edge(0, 0, 0)); // dummy edge for dinic
    S = 2 * n;
    for (int i=0; i<n; i++) {
        insert(S, i, a[i].p);
        insert(i, n+i, a[i].l);
        for (int j=i+1; j<n; j++) {
            if (canJump(a[i], a[j])) {
                insert(n+i, j, a[i].l);
                insert(n+j, i, a[j].l);
            }
        }
    }
}

bool bfs() {
    for (int i=0; i<=S; i++) h[i] = -1;
    queue<int> q;
    h[S] = 0; 
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=hd[cur]; i; i=e[i].nx) {
            if (h[e[i].t] == -1 && e[i].v > 0) {
                h[e[i].t] = h[cur] + 1;
                q.push(e[i].t);
            }
        }
    }
    return h[T] != -1;
}

int dfs(int x, int f) {
    if (x == T) return f;
    int need, used = 0;
    for (int i=hd[x]; i; i=e[i].nx) {
        if (h[e[i].t] == h[x] + 1) {
            need = dfs(e[i].t, min(f - used, e[i].v));
            e[i].v -= need;
            e[i ^ 1].v += need;
            used += need;
            if (used == f) return f;
        }
    }
    if (!used) h[x] = -1;
    return used;
}

int dinic() {
    int ans = 0;
    while (bfs()) ans += dfs(S, inf);
    return ans;
}

void doit() {
    bool found = false;
    for (int i=0; i<n; i++) {
        build();
        T = i;
        if (dinic() == tol) {
            printf("%d ", i);
            found = true;
        }
    }
    if (found) puts("");
    else puts("-1");
}
int main() {
    init();
    doit();
}