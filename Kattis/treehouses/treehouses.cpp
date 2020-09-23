#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,p;
struct point{
    double x,y;
} a[1005];
struct edge {
    int x,y;
    double v;
} e[1000005];
int zz, fa[1005];
double dis(const struct point &i, const struct point &j) {
    return sqrt((i.x-j.x) * (i.x-j.x) + (i.y-j.y) * (i.y-j.y));
}
bool cmp(const struct edge &i, const struct edge &j) {
    return i.v < j.v;
}
int find(int x) {
    if(fa[x]!=x) fa[x] = find(fa[x]);
    return fa[x];
}
int main() {
    cin>>n>>m>>p;
    for(int i=1; i<=n; i++) cin>>a[i].x>>a[i].y;
    for(int i=1; i<=n; i++)
    for(int j=i+1; j<=n; j++) {
        e[++zz].x = i; e[zz].y = j; e[zz].v = dis(a[i], a[j]);
    }

    for(int i=1; i<=n; i++) fa[i] = (i <= m) ? 1 : i;
    sort(e+1, e+zz+1, cmp);
    int cnt = n-m+1;
    double ans = 0;
    for(int i=1; i<=p; i++) {
        int x,y,r1, r2;
        cin>>x>>y;
        r1 = find(x); r2=find(y);
        if(r1 != r2) {fa[r1] = r2; cnt--;}
    }
    //for(int i=1;i<=zz;i++) cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].v<<endl;
    for(int i=1; i<=zz && cnt > 1; i++) {
        int r1, r2;
        r1 = find(e[i].x); r2=find(e[i].y);
        if(r1 != r2) {fa[r1] = r2; cnt--; ans+=e[i].v;}
    }
    
    //cout<<ans<<endl;
    printf("%.6lf\n", ans);
    return 0;
}