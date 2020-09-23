#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 1000000000000
using namespace std;
double d, s;
int main() {
    cin >> d >> s;
    double l=0, r=1000000;
    while(fabs(r-l)>1e-8) {
        double a1 = l + (r-l) / 3, a2 = r - (r-l) / 3;
        double x1 = a1 + s, y1 = a1 * cosh(d / (2 * a1));
        double x2 = a2 + s, y2 = a2 * cosh(d / (2 * a2));
        if(fabs(x1-y1) > fabs(x2-y2)) l = a1;
        else r=a2;
    }
    double a = (r+l) / 2;
    //cout << a << endl;
    printf("%.9lf\n", 2 * a * sinh(d / (2 * a)));
    //cout << 2 * a * sinh(d / (2 * a)) << endl;
}