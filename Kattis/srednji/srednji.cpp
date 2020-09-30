#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define MAXN 100005
#define ll long long
using namespace std;
int n, m, a[MAXN], mid;
int f[MAXN];
ll r[MAXN*2], l[MAXN*2];
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] == m) mid = i;
	}
	for(int i=mid+1; i<=n; i++) { // greater - smaller
		f[i] = a[i] > m ? (f[i-1] + 1) : (f[i-1] - 1);
		r[f[i]+n]++;
	}
		
	for(int i=mid-1; i>0; i--) {// smaller - greater
		f[i] = a[i] > m ? (f[i+1] - 1) : (f[i+1] + 1);
		l[f[i]+n] ++;
	}
    
	l[n]++; r[n]++;

	ll ans =0;
	for(int i=0;i<=n*2;i++) {
		ans += l[i]*r[i];
	}

	cout << ans << endl;
	return 0;
	
}