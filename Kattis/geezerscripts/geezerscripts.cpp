#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<utility>
#include<queue>
#define ll long long
using namespace std;
ll A, H;
int n, m, hd[100002], zz;

struct edge {
    int t, nx;
    ll a, h;
} e[100002];

priority_queue<pair<ll, int>> q; // health, area
bool done[100002];
ll maxh[100002];

void insert(int x, int y, ll a, ll h) {
    e[++zz].t = y; e[zz].a = a; e[zz].h = h; e[zz].nx = hd[x]; hd[x] = zz;
}

ll calrest(ll mh, ll ea, ll eh) {
    ll attack = eh / A + ((eh % A) ? 1 : 0);
    ll rest = mh - ea * (attack - 1);
    return rest;
}

void dijkstra() {
    q.push(make_pair(H, 1));
    while (!q.empty()) {
        ll curh = q.top().first;
        int x = q.top().second;
        q.pop();
        if (done[x]) continue;
        for (int i=hd[x]; i; i=e[i].nx) {
            ll rest = calrest(curh, e[i].a, e[i].h);
            if (rest <= 0) continue;
            q.push(make_pair(rest, e[i].t));
        }
        done[x] = true;
        maxh[x] = curh;
        if (x == n) {
            cout << curh << endl;
            break;
        }
    }
    if (!done[n]) puts("Oh no");
    return;
}

int main() {
    cin >> A >> H >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        ll a, h;
        cin >> x >> y >> a >> h;
        insert(x, y, a, h);
    }
    dijkstra();
    return 0;
}