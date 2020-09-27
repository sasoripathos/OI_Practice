#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100005],ans;
int main() {
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1, a+n+1);
    ans = n;
    for(int i=n; i>=1; i--)
        ans = min(ans, n - i + a[i]);
    printf("%d\n",ans);
    return 0;
}