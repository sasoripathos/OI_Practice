#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int a[3], l;
ll ans;
char s[1000002];
int main() {
    cin >> s;
    l = strlen(s);
    for (int i=0; i<l; i++) {
        int k = s[i] - '0';
        for (int j=k+1; j<=2; j++)
            ans += a[j];
        a[k]++;
    }
    cout << ans << endl;
}