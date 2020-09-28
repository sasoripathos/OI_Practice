#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, a[20], sm;
bool f[12002];
int main() {
    while (true) {
        cin >> n;
        if (!n) break;
        sm = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            sm += a[i];
        }
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i=0; i<n; i++)
        for (int j=sm; j>=a[i]; j--) {
            f[j] |= f[j - a[i]];
        }
        for (int i=(sm + 1) >> 1; i<=sm; i++) {
            if (!f[i]) continue;
            cout << i << " " << sm - i << endl;
            break;
        }
    }
}