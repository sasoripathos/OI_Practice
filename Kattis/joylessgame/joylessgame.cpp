#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
char s[100002];
int main() {
    cin >> n;
    while(n--) {
        cin >> s;
        int l = strlen(s);
        if (l == 2) puts("Bash");
        else {
            if (s[0] == s[l-1]) {
                if (l % 2) puts("Bash");
                else puts("Chikapu");
            } else {
                if (l % 2) puts("Chikapu");
                else puts("Bash");
            }
        }
    }
}