#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, t, a[200005];
int main() {
    cin >> n >> t;
    for (int i=0; i<n; i++) cin >> a[i];
    switch(t) {
        case 1: 
            puts("7");
            break;
        case 2: {
            if (a[0] > a[1]) puts("Bigger");
            else if (a[0] == a[1]) puts("Equal");
            else puts("Smaller");
            break;
        }
        case 3: {
            if(a[0] >= a[1] && a[0] <= a[2]) cout<<a[0]<<endl;
            else if(a[0] >= a[2] && a[0] <= a[1]) cout<<a[0]<<endl;
            else if(a[1] >= a[0] && a[1] <= a[2]) cout<<a[1]<<endl;
            else if(a[1] >= a[2] && a[1] <= a[0]) cout<<a[1]<<endl;
            else if(a[2] >= a[1] && a[2] <= a[0]) cout<<a[2]<<endl;
            else if(a[2] >= a[0] && a[2] <= a[1]) cout<<a[2]<<endl;
            break;
        }
        case 4: {
            long long ans = 0;
            for (int i=0; i<n; i++) ans += a[i];
            cout << ans << endl;
            break;
        }
        case 5: {
            long long ans = 0;
            for (int i=0; i<n; i++) {
                if (a[i] % 2 == 0) ans += a[i];
            }
            cout << ans << endl;
            break;
        }
        case 6: {
            long long ans = 0;
            for (int i=0; i<n; i++) {
                cout << (char) (a[i] % 26 + 'a');
            }
            cout << endl;
            break;
        }
        case 7: {
            int i = 0, view[200005];
            memset(view, 0 , sizeof(view));
            while (i >= 0 && i < n-1) {
                i = a[i];
                if (view[i]) {
                    puts("Cyclic");
                    break;
                }
                view[i] = 1;
                if (i < 0 || i >= n) puts("Out");
                else if (i == n - 1) puts("Done");
            }
            break;
        }
    }
}