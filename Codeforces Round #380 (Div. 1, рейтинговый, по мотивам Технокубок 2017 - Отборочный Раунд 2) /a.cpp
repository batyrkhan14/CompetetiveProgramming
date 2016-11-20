#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF (long long)1000000000*(long long)1000000
using namespace std;
long long n, k, s, t, c[200100], v[200100], g[200100];
long long calc(long long v, long long x){
	if (v >= 2*x) return x;
	if (v < x) return t+(long long)1;
	long long a = v-x;
	return a+(x-a)*2;
}
long long get(long long v){
	long long tt = 0;
	for (int i = 0; i <= k; i++){
		if (i == 0){
			tt += calc(v, g[i]);
		}
		else {
			tt += calc(v, g[i]-g[i-1]);
		}
	}
	return tt;
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; i++){
		cin >> c[i] >> v[i];
	}
	for (int i = 0; i < k; i++){
		cin >> g[i];
	}
	g[k] = s;
	sort(g, g+k+1);
	long long l = 0;
	long long r = 2000000000;
	while (r > l){
		long long m = (r+l)/2;
		long long tt = get(m);
		if (tt <= t){
			r = m;
		}
		else l = m+1;
	}
	long long vv;
	if (get(r) <= t){
		vv = r;
	}
	else{
		cout << -1 << endl;
		return 0;
	}
	long long ans = INF;
	for (int i = 0; i < n; i++){
		if (v[i] >= vv){
			ans = min(ans, c[i]);
		}
	}
	if (ans == INF){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
	return 0;
}