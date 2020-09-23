#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n, m;
ll a[100002], b[100002];
int main() {
    cin >> n;
    ll x = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        x ^= a[i];
        b[i] = x;
    }
    a[++n] = a[0] = x;
    b[n] = b[0] = 0;
    //for (int i=1; i<=n; i++)
    cin >> m;
    for (int i=0; i<m; i++) {
        ll l, r;
        cin >> l >> r;
        ll sz = (r - l + 1) % n;
        ll ans = 0, cur = l%n;
        if (sz > 0) {
            ans = b[(cur + sz - 1) % n] ^ b[cur] ^ a[cur];
        }
        cout << ans << endl;
    }
    return 0;
}