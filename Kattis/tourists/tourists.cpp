#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n, zz, hd[200005]; 
struct edge {
    int t, nx;
} e[400005];
int h[200005], fa[200005][20];
ll ans;

void insert(int x, int y) {
    zz++; e[zz].t = y; e[zz].nx = hd[x]; hd[x] = zz;
    zz++; e[zz].t = x; e[zz].nx = hd[y]; hd[y] = zz;
}

void init_lca(int x) {
    for(int i=1; i<=18; i++) {
        if ((1 << i) > h[x]) break;
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
        
    for(int i=hd[x]; i; i=e[i].nx) {
        int y = e[i].t;
        if (y == fa[x][0]) continue;
        fa[y][0] = x; h[y] = h[x] + 1;
        init_lca(y);
    }
}

int find_lca(int x, int y) {
    if (h[x] > h[y]) swap(x, y);
    // adjust to same height
    for (int i=18; i>=0 && h[y] != h[x]; i--) {
        if (h[fa[y][i]]>=h[x]) y = fa[y][i];
    }
    // stop if x y are already the same
    if (x==y) return x;
    // find lca
    for (int i=18; i>=0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main() {
    cin >> n;
    int x, y;
    for (int i=0; i<n-1; i++) {
        cin >> x >> y;
        insert(x, y);
    }
    h[0] = -1;
    init_lca(1);
    for (int i=1; i<=n/2; i++) 
    for (int j=2; i*j <=n; j++) {
        int lca = find_lca(i, i*j);
        ans += h[i] + 1 + h[i*j] + 1 - h[lca] - h[lca] - 1;
    }
    cout << ans << endl;
    return 0;
}