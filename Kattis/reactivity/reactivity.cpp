#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, k, inq[1002], ct[1002];

struct edge {
    int t, nx;
} e[1000002];
int head[1002], zz;

void insert(int x, int y) {
    zz++; e[zz].t = y; e[zz].nx = head[x]; head[x] = zz;
}

int dfs(int x) {
    if (inq[x]) return -1;
    if (ct[x]) return ct[x];
    ct[x] = 1;
    inq[x] = 1;
    for (int i=head[x]; i; i=e[i].nx) {
        int nx = dfs(e[i].t);
        if (nx == -1) {inq[x] = 0; return -1;}
        else ct[x] = max(ct[x], nx + 1);
    }
    inq[x] = 0;
    return ct[x];
}
int main() {
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        insert(x,y);
    }
    int tag = 0, cur;
    for (int i=0; i<n; i++) {
        if(ct[i] == 0) {
            ct[i] = dfs(i);
            if (ct[i] == n) {
                tag = 1, cur = i;
            }
            else if (ct[i] == -1) {
                puts("back to the lab");
                return 0;
            }

        }
    }
    if (!tag) puts("back to the lab");
    else {
        while (ct[cur] > 1) {
            cout << cur << " ";
            for (int i=head[cur]; i; i=e[i].nx) {
                if(ct[e[i].t] + 1 == ct[cur]) {
                    cur = e[i].t;
                    break;
                }
            }
        }
        cout << cur << endl;
    }
    return 0;
}