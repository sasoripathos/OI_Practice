#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n, a[25], l;
char s[105];
void init() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        l = strlen(s);
        for (int j=0; j<l; j++) {
            int p = s[j] - 'a';
            a[i] |= (1 << p);
        }
    }
}
void doit() {
    int ans = 0;
    for (int i=1; i<(1 << n); i++) {
        int x = 0;
        for (int j=0; j<n; j++) {
            if (i & (1 << j)) x |= a[j];
            if (x == ((1 << 26) - 1)) break;
        }
        if (x == ((1 << 26) - 1)) ans++;
    }
    cout << ans << endl;
}
int main() {
    init();
    doit();
}