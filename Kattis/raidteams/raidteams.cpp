#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int n;
struct player {
    string name;
    int i, a, b, c;
} p1[100002], p2[100002], p3[100002];

bool done[100002];

bool cmp1(const player &i, const player &j) {
    if (i.a > j.a) return true;
    else if (i.a == j.a && i.name < j.name) return true;
    else return false;
}

bool cmp2(const player &i, const player &j) {
    if (i.b > j.b) return true;
    else if (i.b == j.b && i.name < j.name) return true;
    else return false;
}

bool cmp3(const player &i, const player &j) {
    if (i.c > j.c) return true;
    else if (i.c == j.c && i.name < j.name) return true;
    else return false;
}

void print(string n1, string n2, string n3) {
    vector<string> s;
    s.push_back(n1);
    s.push_back(n2);
    s.push_back(n3);
    sort(s.begin(), s.end());
    cout << s[0] << " " << s[1] << " " << s[2] << endl;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p1[i].name >> p1[i].a >> p1[i].b >> p1[i].c;
        p1[i].i = i;
        p2[i].name = p1[i].name;
        p2[i].a = p1[i].a;
        p2[i].b = p1[i].b;
        p2[i].c = p1[i].c;
        p2[i].i = i;
        p3[i].name = p1[i].name;
        p3[i].a = p1[i].a;
        p3[i].b = p1[i].b;
        p3[i].c = p1[i].c;
        p3[i].i = i;
    }
    sort(p1, p1+n, cmp1);
    sort(p2, p2+n, cmp2);
    sort(p3, p3+n, cmp3);
    int c1=0, c2=0, c3=0;
    while (c1 < n && c2 < n && c3 < n) {
        while(c1 < n && done[p1[c1].i]) {c1++;}
        if (c1 == n) break;
        done[p1[c1].i] = true;
        while(c2 < n && done[p2[c2].i]) {c2++;}
        if (c2 == n) break;
        done[p2[c2].i] = true;
        while(c3 < n && done[p3[c3].i]) {c3++;}
        if (c3 == n) break;
        done[p3[c3].i] = true;
        print(p1[c1].name, p2[c2].name, p3[c3].name);
    }
    return 0;
}