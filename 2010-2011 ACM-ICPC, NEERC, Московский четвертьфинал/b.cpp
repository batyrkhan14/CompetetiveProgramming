#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int n, k, a[100010];
	vector<pair<int, int> > v;
	bool used[100010];
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		used[i] = false;
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++){
		used[v[i].second] = true;
	}
	for (int i = 0; i < n; i++){
		if (!used[i]) cout << a[i];
	}
	cout << endl;


	return 0;
}