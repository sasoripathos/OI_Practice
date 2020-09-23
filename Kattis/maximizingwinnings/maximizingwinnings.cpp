#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
int n, a[52][52], m;
ll f[5002][52], g[5002][52];
int main() {
    while(1) {
        scanf("%d", &n);
        if (!n) break;
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
        scanf("%d", &m);
        for (int i=0; i<=m; i++)
        for (int j=1; j<=n; j++)
            g[i][j] = inf, f[i][j] = -inf;
        f[0][1] = g[0][1] = 0;
        for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        for (int k=1; k<=n; k++) {
            //if (j == k) continue;
            f[i][j] = max(f[i][j], f[i-1][k] + a[k][j]);
            g[i][j] = min(g[i][j], g[i-1][k] + a[k][j]);
        }
        ll a1 = 0, a2 = inf;
        for (int i=1; i<=n; i++) {
            a1 = max(a1, f[m][i]);
            a2 = min(a2, g[m][i]);
        }
        //printf("%d %d\n", a1, a2);
        cout << a1 << " " << a2 << endl;
    }
    return 0; 
}