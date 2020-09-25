#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int T, n;
ll a[1000002];
int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            a[i] += a[i-1];
        }
        map<ll, int> val;
        val[0] = 1;
        int ans = 0;
        for (int i=1; i<=n; i++) {
            ll v = a[i] - 47;
            if (val.find(v) != val.end()) ans += val[v];
            if (val.find(a[i]) != val.end()) val[a[i]]++;
            else val[a[i]] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}