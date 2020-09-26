#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const char *a[114] = {"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne",
                      "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca",
                      "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn",
                      "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr",
                      "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn",
                      "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re",
                      "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at",
                      "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds",
                      "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm",
                      "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac",
                      "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es",
                      "fm", "md", "no", "lr"};
int T;
char word[50002];
int done[50002];
bool check(int cur) {
    if (cur == strlen(word)) return true;
    if (done[cur] == 1) return true;
    else if (done[cur] == 0) return false;
    for (int i=113; i>=0; i--) {
        if (a[i][0] != word[cur]) continue;
        int l = strlen(a[i]);
        if (strncmp(word + cur, a[i], l) == 0) {
            if (check(cur + l)) {
                done[cur] = 1;
                return true;
            }
        }
    }
    done[cur] = 0;
    return false;
}
int main() {
    cin >> T;
    while (T--) {
        cin >> word;
        bool tag = true;
        for (int i=0; i<strlen(word); i++)  {
            done[i] = -1;
            if (word[i] == 'j' || word[i] == 'q') {
                puts("NO");
                tag = false;
                break;
            }
        }
        if (!tag) continue;
        if(check(0)) puts("YES");
        else puts("NO");
    }
    return 0;
}