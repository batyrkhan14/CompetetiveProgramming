#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;

long long po[40];
long long cnt(long long l, long long r, long long d){
	long long ans = 0;
	r -= r%d;
	if (l%d != 0) ans--;
	l -= l%d;
	return ans + (r-l)/d+1;
}
long long solve(long long p, long long n){
	vector<long long> pr;
	long long tp = p;
	for (long long i = 2; i*i <= tp; i++){
		if (tp%i == 0){
			pr.push_back(i);
			while (tp%i == 0){
				tp /= i;
			}
		}
	}
	if (tp > 1) pr.push_back(tp);
	/*for (int i = 0; i < pr.size(); i++){
		cout << pr[i] << " ";
	}
	cout << endl;*/
	long long l = p;
	long long r = n/p;
	long long ans = 0;
	for (long long mask = 0; mask < po[pr.size()]; mask++){
		long long x = mask;
		//cout << mask << endl;
		int i = 0;
		long long d = 1;
		long long cn = 0;		
		while (x > 0){
			if (x%2 == 1){
				cn++;
				d *= pr[(int)pr.size()-i-1];
			}
			x /= 2;
			i++;
		}
		long long mul = (cn%2 == 0) ? 1 : -1;
		//cout << l << " " << r << " " << d << " " << mul << endl;
		ans += mul*cnt(l, r, d);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	po[0] = 1;
	for (int i = 1; i < 35; i++){
		po[i] = 2*po[i-1];
	}
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 2; i*i <= n; i++){
		long long temp = solve((long long)i, (long long)n);
		ans += temp;
 		//cout << i << " " << temp << endl;
	}
	cout << ans << endl;
	return 0;
}