#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m = 1, a[4100], t;
double v[4100], f[15][4100];
double getOp(int start, int end, int k, int i) {
    if (v[i] == 0) return 0;
    double ans = 0;
    for (int j=start; j<=end; j++) {
        ans += f[k][j] * v[i] / (v[i] + v[j]);
    }
    return ans;
}
void dp() {
    for (int i=0; i<m; i++) f[0][i] = v[i] / (v[i] + v[i ^ 1]);
    for (int k=1; k<t; k++)
    for (int i=0; i<m; i++) {
        int mask = 1 << k;
        int start = ((i >> k) << k) ^ mask;
        int end = start | (mask - 1);
        double other = getOp(start, end, k-1, i);
        f[k][i] = f[k-1][i] * other;
    }
    printf("%.9lf\n", f[t-1][0]);
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a+1, a+n);
    while (m < n) {
        m = m << 1;
        t++;
    }
    for (int i=0; i<m-n; i++) {
        v[2 * i] = a[i];
        v[2 * i + 1] = 0;
    }
    for (int i=m-n; i<n; i++) v[m - n + i] = a[i];
    dp();
}