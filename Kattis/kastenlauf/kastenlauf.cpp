#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int T, n;
struct Point {
    int x, y;
} a[105];
bool can[105];
int dis(Point &i, Point &j) {
    return abs(i.x - j.x) + abs(i.y - j.y);
}
void bfs() {
    memset(can, 0, sizeof(can));
    queue<int> q;
    q.push(0);
    can[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i=0; i<n+2; i++) {
            if (can[i]) continue;
            if (dis(a[i], a[x]) <= 1000) {
                can[i] = true;
                q.push(i);
            }
        }
    }
    if (can[n+1]) puts("happy");
    else puts("sad");
}
int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n+2; i++) cin >> a[i].x >> a[i].y;
        bfs();
    }
}