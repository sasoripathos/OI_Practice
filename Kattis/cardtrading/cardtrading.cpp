#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int n, t, k, cnt[100002], inq[100002];
ll vn[100002], vu[100002];
struct elem{
    ll v;
    int i;
    elem(ll x, int y) : v(x), i(y) {};
    bool operator < (const struct elem &x) const {
        return v < x.v;
    }
};
priority_queue<elem> maxh;
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
        if (cnt[i] == 0) {vu[i] = -2 * x; vn[i] = 0;}
        else if (cnt[i] == 1) {vu[i] = -x; vn[i] = y;}
        else {vu[i] = 0; vn[i] = 2 * y;}
        if (i <= k) {
            maxh.push(elem(vn[i]-vu[i], i));
            inq[i] = 1;
        } else {
            struct elem top = maxh.top();
            //cout << "Top: " << top.v << " " << top.i << endl;
            if (top.v - vn[i] + vu[i] > 0) {
                maxh.pop();
                maxh.push(elem(vn[i]-vu[i], i));
                inq[top.i] = 0; inq[i] = 1;
            }
        }
    }
    ll ans = 0;
    for (int i=1; i<=t; i++) {
        ans += (inq[i] == 1) ? vu[i] : vn[i];
    }
    cout << ans << endl;
    return 0;
}