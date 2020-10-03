#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<set>
#include<string>
using namespace std;
int T, n;
char s[105];
set<string> sub[100];
void init() {
    cin >> n;
    cin.getline(s, 105); // skip the \n after n
    for (int i=0; i<n; i++) {
        cin.getline(s, 105);
        sub[i].clear();
        int l = strlen(s);

        for (int j=0; j<l; j++)
            s[j] = (s[j] >= 97 ? (char) (s[j] - 32) : s[j]);

        for (int j=0; j<l; j++)
        for (int k=1; k<=l && j+k <= l; k++) {
            string inp (s+j, k); 
            sub[i].insert(inp);
        }
    }
}

bool find(string tar, int j) {
    for (int i=0; i<n; i++) {
        if (i == j) continue;
        if (sub[i].find(tar) != sub[i].end()) return true;
    }
    return false;

}

void doit(int t) {
    printf("Case #%d:\n", t);
    if (n == 1) {
        cout << "\"\"" << endl;
        return;
    }
    for (int i=0; i<n; i++) {
        string ans = "";
        for (auto it=sub[i].begin(); it!=sub[i].end(); ++it) {
            string cur = *it;
            if (ans != "" && ans.size() < cur.size()) continue;
            if (!find(cur, i)) {
                if (ans == "" || cur.size() < ans.size()) ans = cur;
                if (cur.size() == ans.size() && cur < ans) ans = cur;
            }
        }
        if (ans == "") cout << ":(" << endl;
        else cout << "\"" << ans << "\"" << endl;
    }
}
int main () {
    cin >> T;
    for (int t=1; t<=T; t++) {
        init();
        doit(t);
    }
}