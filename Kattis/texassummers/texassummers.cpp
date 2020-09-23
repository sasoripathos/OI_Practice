#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 1000000000000
using namespace std;
int n,m,p;
struct point{
    double x,y;
} a[2505];
ll e[2505][2505], d[2505];
int frm[2505];

ll dis(const struct point &i, const struct point &j) {
    return (i.x-j.x) * (i.x-j.x) + (i.y-j.y) * (i.y-j.y);
}

void spfa() {
    int q[2505], t=0, w=1, inq[2505];
    for(int i=1; i<=n; i++) {
        inq[i] = 0;
        d[i] = inf;
        frm[i] = 0;
    }
    q[0] = n-1; inq[n-1] = 1; d[n-1] = 0; //frm[n-1] = 0;
    while(t!=w) {
        int x = q[t];
        t=(t+1) % 2505; inq[x] = 0;
        for(int i=1; i<=n; i++) {
            if(d[i] > d[x] + e[x][i]) {
                d[i] = d[x] + e[x][i];
                frm[i] = x;
                if(!inq[i]) {
                    q[w] = i; inq[i] = 1;
                    w=(w+1) % 2505;
                }
            }
        }
    }
    //for(int i=1; i<=n; i++) cout<<d[i]<<endl;
    int ans[2505], zz=-1, x=frm[n];
    while(x != 0) {
        ans[++zz] = x-1;
        x = frm[x];
    }
    zz--;
    if(zz <= 0) puts("-");
    else {
        while(zz >= 0) cout<<ans[zz--]<<endl;
    }
}

int main() {
    cin>>n;
    n = n + 2;
    for(int i=1; i<=n; i++) cin>>a[i].x>>a[i].y;

    for(int i=1; i<=n; i++)
    for(int j=i+1; j<=n; j++) {
        e[i][j] = e[j][i] = dis(a[i], a[j]);
    }

    spfa();
    return 0;
}