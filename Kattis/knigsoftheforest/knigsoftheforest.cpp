#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n, k, s;
struct player {
    int y, p;
} a[200005];
priority_queue<int> q;
bool cmp(const struct player &i, const struct player &j) {
    return i.y < j.y;
}
int main() {
    cin >> k >> n;
    cin >> a[0].y >> a[0].p;
    s = a[0].p;
    for (int i=1; i<n+k-1; i++) cin >> a[i].y >> a[i].p;
    sort(a, a+n+k-1, cmp);
    for (int i=0; i<k; i++) q.push(a[i].p);
    int year = a[0].y, tag = 0;
    for (int i=k; i<=n+k-1; i++) {
        int v = q.top();
        q.pop();
        if(v == s) {
            tag = 1; break;
        }
        year++;
        q.push(a[i].p);
    }
    if (tag) cout << year << endl;
    else puts("unknown");
    return 0;
}