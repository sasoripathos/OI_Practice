#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n, f[1000005];
void pre() {
    f[0] = 1;
    ll s = 1;
    for(int i=1; i<=1000000; i++) {
        s *= i;
        while (s % 10 == 0) s /= 10;
        s %= 1000000;
        f[i] = s % 10;
    }
}
int main() {
    pre();
    while(1) {
        scanf("%d", &n);
        if (!n) break;
        cout << f[n] << endl;
    }
}
//1 2 6 4 2 2 4 2 8 8
//8 6 8 2 8