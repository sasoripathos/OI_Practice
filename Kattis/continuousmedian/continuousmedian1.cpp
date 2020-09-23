#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n, T, sz, root;
struct tree {
    int v, h, l, r, s;
} tr[400005];

int bv(int w) {
    return tr[tr[w].l].h - tr[tr[w].r].h;
}

void lturn(int &w) {
    int r= tr[w].r;
    tr[w].r = tr[r].l;
    tr[w].h = max(tr[tr[w].l].h, tr[tr[w].r].h) + 1;
    tr[w].s = tr[tr[w].l].s + tr[tr[w].r].s + 1;
    tr[r].l = w;
    tr[r].h = max(tr[tr[r].l].h, tr[tr[r].r].h) + 1;
    tr[r].s = tr[tr[r].l].s + tr[tr[r].r].s + 1;
    w=r;
}

void rturn(int &w) {
    int l= tr[w].l;
    tr[w].l = tr[l].r;
    tr[w].h = max(tr[tr[w].l].h, tr[tr[w].r].h) + 1;
    tr[w].s = tr[tr[w].l].s + tr[tr[w].r].s + 1;
    tr[l].r = w;
    tr[l].h = max(tr[tr[l].l].h, tr[tr[l].r].h) + 1;
    tr[l].s = tr[tr[l].l].s + tr[tr[l].r].s + 1;
    w=l;
}

void balance(int &w) {
    int diff = bv(w);
    tr[w].s = tr[tr[w].l].s + tr[tr[w].r].s + 1;
    if(abs(diff) <= 1) return;
    else if(diff < -1) {
        if(bv(tr[w].r) > 0) rturn(tr[w].r);
        lturn(w);
    } else {
        if(bv(tr[w].l) < 0) lturn(tr[w].l);
        rturn(w);
    } 
}

void insert(int &w, int v) {
    if(!w) {
        w = ++sz;
        tr[sz].v = v;
        tr[sz].h = tr[sz].s = 1;
    } else {
        if(tr[w].v < v) {
            insert(tr[w].r, v);
            balance(w);
        } else {
            insert(tr[w].l, v);
            balance(w);
        }
    }
}

int find(int w, int p) {
    if(tr[tr[w].l].s == p-1) return tr[w].v;
    else if(tr[tr[w].l].s >= p) return find(tr[w].l, p);
    else return find(tr[w].r, p-tr[tr[w].l].s-1);
}

int main() {
    cin >> T;
    while(T--) {
        memset(tr, 0, sizeof(tr));
        sz = root = 0;
        cin >> n;
        int a, m;
        long long ans = 0;
        for(int i=1; i<=n; i++) {
            cin>>a;
            insert(root, a);
            if(i%2) {
                m = find(root, (i+1)/2);
                //cout <<  m << " ";
            } else {
                m = (find(root, i / 2) + find(root, i / 2 + 1)) / 2;
                //cout<< m << " ";
            }
            ans += m;
        }
        //cout << endl;
        cout << ans << endl;
    }
}