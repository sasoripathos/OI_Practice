#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 1000000000000
using namespace std;
int n, m, a[100005], b[100005], f[100005], ans = 0;
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[i] = a[i] * 100 + i * m;
    }

    int maxpre = 1;
    for (int i=2; i<=n; i++) {
        int cur = b[maxpre] - (i + 1) * m - a[i] * 100;
        ans = max(ans, cur);
        maxpre = b[i] > b[maxpre] ? i : maxpre;
    }

    cout << ans << endl;
    return 0;
}