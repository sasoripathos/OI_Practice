#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n, a, b, c, f[100002][3], ans;
char s[100002];
void cal(int i, int l, char v) {
    int nx = (i + 1) % n;
    int last = (i + l) % n;
    f[i][v - 'A'] = f[nx][v - 'A'];
    f[i][v - 'A'] -= (s[last] == v) ? 1 : 0;
    f[i][v - 'A'] += (s[i] == v) ? 1 : 0;
}
void pre() {
    for(int i=0;i<n;i++) {
        a += (s[i] == 'A') ? 1 : 0;
        b += (s[i] == 'B') ? 1 : 0;
        c += (s[i] == 'C') ? 1 : 0;
    }
    for (int i=0; i<a; i++)
        f[0][0] += (s[i] == 'A') ? 1 : 0;
    for (int i=0; i<b; i++)
        f[0][1] += (s[i] == 'B') ? 1 : 0;
    for (int i=0; i<c; i++)
        f[0][2] += (s[i] == 'C') ? 1 : 0;
    for (int i=n-1; i>0; i--) {
        if (a) cal(i, a, 'A');
        if (b) cal(i, b, 'B');
        if (c) cal(i, c, 'C');
    }
}
void doit() {
    int ans = n;
    for (int i=0; i<n; i++) {
        int ia = i, ib = (i + a) % n, ic = (i + a + b) % n;
        ans = min(ans, a - f[ia][0] + b - f[ib][1] + c - f[ic][2]);
        ia = i, ic = (i + a) % n, ib = (i + a + c) % n;
        ans = min(ans, a - f[ia][0] + c - f[ic][2] + b - f[ib][1]);
    }
    cout << ans << endl;
}
int main() {
    cin >> n >> s;
    pre();
    doit();
}