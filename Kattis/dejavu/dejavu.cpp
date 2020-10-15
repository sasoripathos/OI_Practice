#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int n, x[100002], y[100002];
ll ans, cx[100002], cy[100002];
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        cx[x[i]]++;
        cy[y[i]]++;
    }
    for (int i=0; i<n; i++) {
        ans += (cx[x[i]] - 1) * (cy[y[i]] - 1);
    }
    cout << ans << endl;
    return 0;
}