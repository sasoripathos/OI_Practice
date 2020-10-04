#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<utility>
#define inf 2147483647
using namespace std;
int n, m, a[1000][1000], maxh, minh = inf;
int xx[4] = {-1, 0, 1, 0}, yy[4] = {0, 1, 0, -1};
bool inq[1000][1000];
bool check(int limit) {
    queue<pair<int, int>> q;
    memset(inq, 0, sizeof(inq));
    for (int i=0; i<n; i++) {
        if (a[i][0] <= limit) {
            q.push(make_pair(i, 0));
            inq[i][0] = true;
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int xt = x + xx[i], yt = y + yy[i];
            if (xt < 0 || yt < 0 || xt >= n || yt >= m || inq[xt][yt] || a[xt][yt] > limit) continue;
            if (yt == m - 1) return true;
            q.push(make_pair(xt, yt));
            inq[xt][yt] = true;
        }
    }
    return false;
}
void bisection() {
    int l=minh, r = maxh, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
        cin >> a[i][j];
        maxh = max(maxh, a[i][j]);
        minh = min(minh, a[i][j]);
    }
    bisection();
    return 0;
}