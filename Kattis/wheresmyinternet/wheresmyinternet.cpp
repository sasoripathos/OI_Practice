#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m, fa[200002];
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) fa[i] = i;
    for (int i=0; i<m; i++) {
        int x, y, r1, r2;
        cin >> x >> y;
        r1 = find(x);
        r2 = find(y);
        if (r1 != r2) {
            if (r1 < r2) fa[r2] = r1;
            else fa[r1] = r2;
        }
    }
    bool connected = true;
    for (int i=1; i<=n; i++) {
        int r = find(i);
        if (r != 1) {
            cout << i << endl;
            connected = false;
        }
    }
    if (connected) cout << "Connected" << endl;
    return 0;
}
