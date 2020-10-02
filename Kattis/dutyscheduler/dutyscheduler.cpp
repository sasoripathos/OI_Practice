#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#define inf 100000000
using namespace std;
int n, m, maxc;
bool a[62][35];
string names[62];
struct edge {
    int t, nx, v;
} e[4000];
int zz, hd[100], S, T, h[100];
int assign[32][2];

void insert(int x, int y, int v) {
    zz++; e[zz].t = y; e[zz].v = v; e[zz].nx = hd[x]; hd[x] = zz;
    zz++; e[zz].t = x; e[zz].v = 0; e[zz].nx = hd[y]; hd[y] = zz;
}
void build(int bound) {
    zz = 1; S = n + m + 1; T = n + m + 2;
    memset(hd, 0, sizeof(hd));
    for (int i=1; i<=m; i++) {
        insert(S, i, bound);
        for (int j=1; j<=n; j++) {
            if (a[i][j]) insert(i, m + j, 1);
        }
    }
    for (int j=1; j<=n; j++)
        insert(m + j, T, 2);
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

bool bfs() {
    for (int i=1; i<= T; i++) h[i] = -1;
    queue<int> q;
    q.push(S); h[S] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=hd[cur]; i; i=e[i].nx) {
            if (e[i].v > 0 && h[e[i].t] == -1) {
                h[e[i].t] = h[cur] + 1;
                q.push(e[i].t);
            }
        }
    }
    return h[T] != -1;
}

int dinic() {
    int ans = 0;
    while(bfs()) ans += dfs(S, inf);
    return ans;
}

bool check(int bound) {
    build(bound);
    if (dinic() == (n << 1)) {
        for (int i=1; i<=n; i++) {
            int cnt = 0;
            for (int j=hd[m+i]; j && cnt < 2; j=e[j].nx) {
                if (e[j].t >= 1 && e[j].t <= m && e[j].v > 0) {
                    assign[i][cnt++] = e[j].t;
                }
            }
        }
        return true;
    } else
        return false;
}

void bisection() {
    int l=1, r=maxc, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    for (int i=1; i<=n; i++) {
        printf("Day %d: ", i);
        cout << names[assign[i][0]] << " " << names[assign[i][1]] << endl;
    }
        
}
int main () {
    cin >> m >> n;
    for (int i=1; i<=m; i++) {
        int c, x;
        cin >> names[i] >> c;
        maxc = max(maxc, c);
        for (int j=0; j<c; j++) {
            cin >> x;
            a[i][x] = true;
        }
    }
    bisection();
    return 0;
}
