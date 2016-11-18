#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF (long long)2000000000 * (long long)2000000000
using namespace std;

long long getans(long long a, long long b, long long c){
	if (a < 0 || b < 0 || c < 0) return INF;
	return 3*(max(a, max(b, c)))-a-b-c;
}

int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	long long a, b, c;
	cin >> a >> b >> c;
	long long ans = INF;	
	long long x[] = {0,-1,0,-1,0,-1,0};
	long long y[] = {0,-1,-1,0,0,0,-1};
	long long z[] = {0,0,-1,-1,-1,0,0};
	for (int i = 0; i < 7; i++){
		ans = min(ans, getans(a+x[i],b+y[i],c+z[i]));
	}
	cout << ans << endl;
	return 0;
}