#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
int n, l[1002], r[1002], m, cnt[2002];
set<int> a;
int pos[2002], zz;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        a.insert(x);
        for (int j=1; j<=n; j++) {
            if (x >= l[j] && x <= r[j]) cnt[j] ++;
            if (x < l[j]) break;
        }
    }
    for (int i=1; i<=n; i++) {
        if (cnt[i] > 2) {
            puts("impossible");
            return 0;
        } else if (cnt[i] == 2) {
            continue;
        } else {
            if (cnt[i] == 0) {
                int p = l[i] + 1;
                while (a.find(p) != a.end()) p++;
                pos[zz++] = p;
                cnt[i] = 1;
                a.insert(p);
            }
            int p = r[i];
            if (cnt[i+1] >= 2) p--;
            while (a.find(p) != a.end()) p--;
            pos[zz++] = p;
            cnt[i] ++;
            if (p == l[i+1]) cnt[i+1]++;
            a.insert(p);
        }
    }
    cout << zz << endl;
    for (int i=0; i<zz; i++) cout << pos[i] << " ";
    puts("");
    return 0;
}