#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int h, n, m;
ll ansx, ansy;
void cal() {
    for (int i=h; i>1; i--) {
        ansy += (i-1) * 2;
    }
    ansx = 1;
    while (n > ansx && m < ansy) {
        n -= 2; m++;
    }
    ansx = (n >= 1) ? 0 : 1;
    ansy = (m >= ansy) ? 0 : ansy - m;
    cout << ansx << " " << ansy << endl;
}
int main() {
    cin >> h >> n >> m;
    cal();
}