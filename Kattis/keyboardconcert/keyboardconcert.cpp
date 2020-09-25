#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m, can[1000][1001], a[1000], suf[1000][1001];

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int x, l;
        cin >> l;
        for (int j=0; j<l; j++) {
            cin >> x;
            can[i][x] = 1;
        }
    }
    for (int i=0; i<m; i++) cin >> a[i];
    for (int i=0; i<n; i++)
    for (int j=m-1; j>=0; j--) {
        if (can[i][a[j]]) suf[i][j] = suf[i][j+1] + 1;
        else suf[i][j] = 0;
    }

    /*for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cout << suf[i][j] << " ";
        puts("");
    }*/

    int cur = 0, ans = 0;
    while (cur < m) {
        int ins = 0;
        for (int i=1; i<n; i++) ins = suf[i][cur] > suf[ins][cur] ? i : ins;
        cur += suf[ins][cur];
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}