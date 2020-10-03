#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
int T, n, m, zz, hd[40002], cnt[40002];
map<int, int> last;
struct edge {
    int t, nx;
} e[800005];

void insert(int x, int y) {
    zz++; e[zz].t = y; e[zz].nx = hd[x]; hd[x] = zz;
}

void init() {
    last.clear();
    zz = 0;
    memset(hd, 0, sizeof(hd));
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &m);
        int x;
        for (int j=1; j<m; j++) {
            scanf("%d", &x);
            map<int, int>::iterator it = last.find(x);
            if (it != last.end()) {
                insert(it -> second, i);
            }
        }
        scanf("%d", &x);
        last[x] = i;
    }
}

int dfs(int x) {
    if (cnt[x]) return cnt[x];
    cnt[x] = 1;
    for (int i=hd[x]; i; i=e[i].nx) {
        cnt[x] = max(cnt[x], 1 + dfs(e[i].t));
    }
    return cnt[x];
}

void doit(int trace) {
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<n; i++) {
        if (!cnt[i]) dfs(i);
        ans = max(ans, cnt[i]);
    }
    printf("%d %d\n", trace, ans);
}
int main () {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        init();
        doit(t);
    }
}