#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define inf 1e7
using namespace std;
int n, a[1005], b[1005], c[1005], tol;
void init() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
        c[i] = b[i] - b[i-1];
        tol += b[i];
    }
}

void doit(){
    double up = inf, down = 0;
    for(int i=2; i<=n; i++) {
        if (c[i] == 0) {
            if (a[i-1] < a[i]) {
                puts("-1");
                return;
            }
        } else if (c[i] > 0) {
            up = fmin(up, (a[i-1] - a[i]) * 1.0 / c[i]);
        }
        else {
            down = fmax(down, (a[i-1] - a[i]) * 1.0 / c[i]);
        }
    }
    if(up < down) puts("-1");
    else  printf("%.12lf\n", down * tol);
}

int main() {
  init(); doit();
  return 0;
}