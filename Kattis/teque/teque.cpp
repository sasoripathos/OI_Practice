#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
//#include<string>
using namespace std;
int n, a[1000005], b[1000005], t1, w1, t2, w2;
int leng(int t, int w) {
    if (t > w) w += n;
    return w-t;
}

int main() {
    scanf("%d", &n); //cin >> n;
    //string s;
    char s[15];
    int x;
    for (int i=0; i<n; i++) {
        scanf("%s%d", s, &x); //cin >> s >> x;
        if(s[0] == 'g') {
            int l1 = leng(t1, w1);
            if (x < l1) printf("%d\n", a[(t1 + x) % n]); //cout << a[(t1 + x) % n] << endl;
            else printf("%d\n", b[(t2 + x - l1) % n]); //cout << b[(t2 + x - l1) % n] << endl;
        } else if (s[5] == 'b' /*s == "push_back"*/) {
            b[w2] = x;
            w2 = (w2 + 1) % n; 
            if(leng(t2, w2) > leng(t1, w1)) {
                a[w1] = b[t2];
                t2 = (t2 + 1) % n;
                w1 = (w1 + 1) % n;
            }
        } else if (s[5] == 'f'/*s == "push_front"*/) {
            t1 = (t1 + n - 1) % n;
            a[t1] = x;
            if (leng(t1, w1) > leng(t2, w2) + 1) {
                t2 = (t2 + n - 1) % n;
                b[t2] = a[(w1 + n - 1) % n];
                w1 = (w1 + n - 1) % n;
            }

        } else if (s[5] == 'm'/*s == "push_middle"*/) {
            a[w1] = x;
            w1 = (w1 + 1) % n;
            if (leng(t1, w1) > leng(t2, w2) + 1) {
                t2 = (t2 + n - 1) % n;
                b[t2] = a[(w1 + n - 1) % n];
                w1 = (w1 + n - 1) % n;
            }
        }
    }
    return 0;
}