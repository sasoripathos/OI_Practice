#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define inf 1000
using namespace std;
int n, v[55], t[55], a[55], f[55];
int perm[4] = {0, 1, 2, 3};
char s[5];
int getOffset(int tp) {
    int ans = 0;
    for (int i=0; i<4; i++) {
        if (perm[i] == tp) ans = i;
    }
    return ans;
}

void init(int j) {
    for (int i=0; i<n; i++) {
        int offset = getOffset(t[i]);
        int val = 13 * offset;
        if (j & (1 << t[i])) val +=  12 - v[i];
        else val += v[i];
        a[i] = val;
    }
}


int dp() {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    int ans = 1;
    for (int i=1; i<n; i++) {
        f[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    /*for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << "--- " << ans << endl;*/
    return ans;
}

void doit() {
    int ans = 100;
    do {
        //cout << perm[0] << perm[1] << perm[2] << perm[3] << endl;
        for (int j=0; j<16; j++) {
            init(j);
            ans = min(ans, n - dp());
        }
    } while (next_permutation(perm, perm + 4));
    cout << ans << endl;
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        switch(s[0]) {
            case 'T': {
                v[i] = 8;
                break;
            }
            case 'J': {
                v[i] = 9;
                break;
            }
            case 'Q': {
                v[i] = 10;
                break;
            }
            case 'K': {
                v[i] = 11;
                break;
            }
            case 'A': {
                v[i] = 12;
                break;
            }
            default : {
                v[i] = (int) (s[0] - '2');
                break;
            }
        }
        switch(s[1]) {
            case 's': {
                t[i] = 0;
                break;
            }
            case 'h': {
                t[i] = 1;
                break;
            }
            case 'd': {
                t[i] = 2;
                break;
            }
            default : {
                t[i] = 3;
                break;
            }
        }
    }
    doit();
}