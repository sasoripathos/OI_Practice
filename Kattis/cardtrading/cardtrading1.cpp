#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int n, t, k, cnt[100002];
struct elem{
    ll vu, vn;
    bool operator < (const struct elem &x) const {
        return vn - vu < x.vn - x. vu;
    }
} a[100002];
int main() {
    cin >> n >> t >> k;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i=1; i<=t; i++) {
        ll x, y;
        cin >> x >> y; 
        if (cnt[i] == 0) {a[i].vu = -2 * x; a[i].vn = 0;}
        else if (cnt[i] == 1) {a[i].vu = -x; a[i].vn = y;}
        else {a[i].vu = 0; a[i].vn = 2 * y;}
    }
    sort(a+1, a+t+1);
    ll ans = 0;
    for (int i=1; i<=t; i++) {
        ans += (i <= k) ? a[i].vu : a[i].vn;
    }
    cout << ans << endl;
    return 0;
}