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

int n, m, d[100100], a[100100];

bool possible(int ds){
	int last[100100];
	for (int i = 0; i < m; i++){
		last[i] = -1;
	}
	for (int i = 0; i <= ds; i++){
		if (d[i] >= 0){
			last[d[i]] = i;
		}
	}
	for (int i = 0; i < m; i++){
		if (last[i] == -1) return false;
	}
	vector<pair<int, int> > v;
	for (int i = 0; i < m; i++){
		v.push_back(make_pair(last[i], i));
	}
	sort(v.begin(), v.end());
	int spent = 0;
	for (int i = 0; i < m; i++){
		spent += a[v[i].second];
		if (spent > v[i].first) return false;
		spent ++;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> d[i];
		d[i]--;
	}
	for (int i = 0; i < m; i++){
		cin >> a[i];
	}

	if (!possible(n-1)){
		cout << -1 << endl;
	}
	else{
		int l = 0, r = n-1;
		while (l < r){
			int m = (l+r)/2;
			if (!possible(m)){
				l = m+1;
			}
			else{
				r = m;
			}
		}
		cout << r+1 << endl;
	}
	return 0;
}