#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, T;


int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        int a, m;
        long long ans = 0;
        priority_queue<int> maxh;
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i=1; i<=n; i++) {
            cin>>a;
            if(minh.size() > 0 && minh.top() < a) {minh.push(a);}
            else {maxh.push(a);}
            int maxs = maxh.size(), mins = minh.size();
            if(maxs - mins < 0) {
                maxh.push(minh.top());
                minh.pop();
            } else if (maxs - mins > 1) {
                minh.push(maxh.top());
                maxh.pop();
            }
            m = i%2 ? maxh.top() : (maxh.top() + minh.top()) / 2;
            ans +=m;

        }
        cout << ans << endl;
    }
}