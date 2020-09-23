#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main() {
    cin >> n;
    int m=2, k=1;
    while (n > m) {
        n -= m;
        k++;
        m <<= 1;
    }
    n = n-1;
    for (int i=k-1; i>=0; i--) {
        if(n & (1 << i)) cout<<"7";
        else cout<<"4";
    }
    puts("");
    return 0;

}