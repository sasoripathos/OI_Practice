#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, pri[1000000], cnt;
bool mk[1000000];
void pre() {
    for (int i=2; i<=1000000; i++) {
        if(!mk[i]) pri[++cnt] = i;
        for (int j=1; j<=cnt && pri[j]*i <= 1000000; j++) {
            mk[pri[j]*i] = true;
            if (i % pri[j] == 0) break;
        }
    }
}
int main () {
    pre();
    cin >> n;
    int ans = 1, zrs = 0;
    for (int i=1; i<=cnt && n > 1 && pri[i] <= n; i++) {
        int c = 0;
        while (n % pri[i] == 0) {
            c++; n /= pri[i];
        }
        if (c > zrs) {
            zrs = c; ans = pri[i];
        }
    }
    if (n > 1 && zrs == 0) ans = n;
    cout << ans << endl;
    return 0;
}