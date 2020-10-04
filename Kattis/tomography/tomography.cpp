#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n, m, a[1000];
priority_queue<int> q1, q2;
void doit() {
    while (!q1.empty()) {
        int x = q1.top();
        q1.pop();
        if (q2.size() < x) {
            puts("No");
            return;
        }
        for (int i=0; i<x; i++) {
            a[i] = q2.top();
            q2.pop();
        }
        for (int i=0; i<x; i++) {
            if (a[i] > 1) q2.push(a[i] - 1);
        }
    }
    puts("Yes");
}
int main() {
    cin >> m >> n;
    int rs=0, cs=0;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        if (x > n) {
            puts("No");
            return 0;
        }
        rs += x;
        if (x > 0) q1.push(x);
    }
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x > m) {
            puts("No");
            return 0;
        }
        cs += x;
        if (x > 0) q2.push(x);
    }
    if (rs != cs) {
        puts("No");
        return 0;
    }
    doit();
}