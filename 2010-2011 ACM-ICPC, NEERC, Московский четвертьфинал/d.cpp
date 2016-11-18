#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
#define INF 2000000000
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int n, k, l, d[100100], p[100100];
	bool has[100100], used[100100];
	vector<pair<int, int> > g[100100];
	int ans = INF;
	cin >> n >> k >> l;
	for (int i = 0; i < k; i++){
		d[i] = INF;
		p[i] = -1;
		used[i] = false;
		has[i] = false;
	}
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		x--;
		p[x] = x;
		has[x] = true;
	}
	for (int i = 0; i < l; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		from--;
		to--;
		g[from].push_back(make_pair(to, cost));
		g[to].push_back(make_pair(from, cost));
	}
	for (int i = 0; i < k; i++){
		if (has[i]){
			for (int j = 0; j < g[i].size(); j++){
				int to = g[i][j].first;
				int cost = g[i][j].second;
				if (d[to] > cost){
					d[to] = cost;
					p[to] = i;
				}
			}
		}
	}
	set<pair<int, int> > q;
	for (int i = 0; i < k; i++){
		q.insert(make_pair(d[i], i));
	}
	while (!q.empty()){
		if (q.begin()->first == INF) break;
		int v = q.begin()->second;
		q.erase(q.begin());
		used[v] = true;
		for (int i = 0; i < g[v].size(); i++){
			int to = g[v][i].first;
			int cost = g[v][i].second;
			if (p[to] != p[v] && p[to] != -1 && p[v] != -1){
				ans = min(ans, d[to] + d[v] + cost);
			}
			if (!used[to]){
				if (d[to] > d[v] + cost && (!has[i] || to != p[v])){
					q.erase(make_pair(d[to], to));
					d[to] = d[v] + cost;
					p[to] = p[v];
					q.insert(make_pair(d[to], to));
				}
			}
		}
	}
	for (int i = 0; i < k; i++){
		if (has[i]){
			ans = min(ans, d[i]);
		}
	}
	cout << ans*3 << endl;
	return 0;
}