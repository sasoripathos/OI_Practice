#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
int n, m, k, cnt;
char a[105][105];
set<int> s[50005];
int main() {
    scanf("%d%d%d", &k, &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%s", a[i]);
        for (int j=0; j<m; j++) {
            if (a[i][j] == '*') s[0].insert(i * m + j);
            else s[1].insert(i * m + j);
        }
    }
    if (s[1].size() > 0) cnt = 2;
    else cnt = 1;
    for (int t=1; t<k; t++) {
        for (int i=0; i<n; i++) {
            scanf("%s", a[i]);
        }
        int oldcnt = cnt;
        for (int c=0; c<oldcnt; c++) {
            set<int>::iterator it=s[c].begin();
            set<int> newset = set<int> ();
            int orig_size = s[c].size();
            while (it!=s[c].end()) {
                int v = *it;
                int i = v / m, j = v % m;
                if (a[i][j] == '.') {
                    newset.insert(v);
                    s[c].erase(it++);
                } else {
                    ++it;
                }
            }
            if (newset.size() != orig_size && newset.size() != 0) {
                s[cnt] = newset;
                cnt++;
            } else if (newset.size() == orig_size) {
                s[c] = newset;
            }
        }
    }
    int ans = 0;
    for (int i=0; i<cnt; i++) {
        ans += s[i].size() > 0 ? 1 : 0;
    }
    printf("%d\n", ans);
    return 0;
}