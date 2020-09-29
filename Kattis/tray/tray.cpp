#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n, m;
bool done[25][3];
ll cal[25][3][64];
ll dfs() {
    int x=-1, y=-1;
    for (int i=0; i<m && x == -1; i++)
    for (int j=0; j<3 && y == -1; j++) {
        if (!done[i][j]) {
            x = i; y = j;
        }
    }
    if (x == -1) {
        return 1;
    }
    int state = 0;
    for (int i=x+1; i>=x; i--)
    for (int j=2; j>=0; j--)
        state = state * 2 + (done[i][j] ? 1 : 0);
    if (cal[x][y][state] != -1) return cal[x][y][state];
    ll ans = 0;
    if (!done[x][y]) {
        done[x][y] = true;
        ans += dfs();
        done[x][y] = false;
    }
    if (!done[x][y] && x + 1 < m && !done[x + 1][y]) {
        done[x][y] = true; done[x + 1][y] = true;
        ans += dfs();
        done[x][y] = false; done[x + 1][y] = false;
    }
    if (!done[x][y] && y < 2 && !done[x][y + 1]) {
        done[x][y] = true; done[x][y + 1] = true;
        ans += dfs();
        done[x][y] = false; done[x][y + 1] = false;
    }
    cal[x][y][state] = ans;
    return ans;
}
int main() {
    cin >> m >> n;
    for (int i=0; i<n; i++) {
        double x, y;
        cin >> x >> y;
        done[(int) x][(int) y] = true;
    }
    for (int i=0; i<m; i++)
    for (int j=0; j<3; j++)
    for (int k=0; k<64; k++)
        cal[i][j][k] = -1;
    ll ans = dfs();
    cout << ans << endl;
    return 0;
}