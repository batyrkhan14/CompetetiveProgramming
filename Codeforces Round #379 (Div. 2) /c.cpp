#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	long long n, x, s, a[200100], c[200100];
	int m, k;
	vector<pair<long long, long long> > va, vc;
	cin >> n >> m >> k;
	cin >> x >> s;
	for (int i = 0; i < m; i++){
		cin >> a[i];
	}
	for (int i = 0; i < m; i++){
		long long b;
		cin >> b;
		va.push_back(make_pair(b, a[i]));
	}
	for (int i = 0; i < k; i++){
		cin >> c[i];
	}
	for (int i = 0; i < k; i++){
		long long d; 
		cin >> d;
		vc.push_back(make_pair(d, c[i]));
	}
	sort(va.begin(), va.end());
	reverse(va.begin(), va.end());
	sort(vc.begin(), vc.end());
	long long cost = n*x;
	for (int i = 0; i < k; i++){
		if (vc[i].first <= s){
			cost = min(cost, (n-min(n, vc[i].second))*x);
		}
	}
	int j = -1;
	long long maxc = 0; 
	for (int i = 0; i < m; i++){
		if (va[i].first <= s){
			while (j+1 < k && vc[j+1].first <= s-va[i].first){
				j++;
				maxc = max(maxc, vc[j].second);
			}
			long long xx = va[i].second;
			long long nn = n;
			if (j >= 0) nn -= maxc;
			if (nn < 0) nn = 0;
			cost = min(cost, nn*xx);			
		}
	}
	cout << cost << endl;
	return 0;
}