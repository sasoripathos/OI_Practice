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
bool f[50002];
void check() {
    memset(f, 0, sizeof(f));
    f[0] = true;
    for (int i=0; i<strlen(word); i++)
    for (int j=0; j<114; j++) {
        int l = strlen(a[j]);
        if (i + 1 - l >= 0 && strncmp(word + i + 1 - l, a[j], l) == 0 && f[i - l + 1]) {
            f[i + 1] = true;
            break;
        }
    }
    if (f[strlen(word)]) puts("YES");
    else puts("NO");
    
}
int main() {
    cin >> T;
    while (T--) {
        cin >> word;
        bool tag = true;
        for (int i=0; i<strlen(word); i++)  {
            if (word[i] == 'j' || word[i] == 'q') {
                puts("NO");
                tag = false;
                break;
            }
        }
        if (!tag) continue;
        check();
    }
    return 0;
}