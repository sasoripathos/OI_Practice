#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int m, s, a[1000002], b[1000002], ans;
int main() {
    cin >> m >> s;
    for (int i=0; i<m; i++)
    for (int j=0; j<s; j++)
        cin >> a[i * s + j];
    for (int j=0; j<s; j++) {
        for (int i=0; i<m; i++)  {
            if (!b[a[i * s + j]]) ans++;
            b[a[i * s + j]] = 1;
        }
        if (ans == j + 1) break;
    }
    cout << ans << endl;
    sort(a, a+ans);
    for (int i=0; i<ans; i++) cout << a[i] << " ";
    cout << endl;
    return 0;

}