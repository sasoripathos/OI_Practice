#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAXN 300002
#define ll long long
using namespace std;
int n, m, a[MAXN], c[MAXN], f[MAXN], maxl, pos;
int q[MAXN], q2[MAXN], cnt;
int find(int i) {
    int l=0, r=cnt, mid, ans=0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (a[q[mid]] < a[i] && c[q[mid]] != c[i]) {
            ans = mid;
            l = mid + 1;
        } else if (a[q[mid]] < a[i] && c[q[mid]] == c[i]) {
            ans = mid - 1; // must true
            if (q2[mid] != -1 && a[q2[mid]] < a[i])
                ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans + 1;
}
void dp() {
    q[0] = 0;
    q2[0] = -1;
    for (int i=1; i<=n; i++) {
        int l = find(i);
        f[i] = l;
        if (l > cnt) {
            cnt ++;
            q[l] = i;
            q2[l] = -1;
        } else {
            if (a[q[l]] >= a[i]) {
                if (c[q[l]] != c[i]) {
                    q2[l] = q[l];
                }
                q[l] = i;
            }  else {
                if (c[q[l]] == c[i]) continue;
                if (q2[l] == -1 || a[q2[l]] > a[i]) q2[l] = i;
            }
        }
        if (maxl < l) {
            maxl = l;
            pos = i;
        }
    }
}
void output() {
    cout << maxl << endl;
    vector<int> ans;
    ans.push_back(pos);
    int cur = pos;
    for (int i=pos - 1; i>0; i--) {
        if (f[i] == f[cur] - 1 && a[i] < a[cur] && c[i] != c[cur]) {
            ans.push_back(i);
            cur = i;
        }
    }
    for (int i=ans.size() - 1; i>=0; i--)
        cout << ans[i] << " ";
    cout << endl;

}
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> c[i] >> a[i];
    dp();
    output();
}