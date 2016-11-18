#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
bool used[20010];
int n, col[20010], d[20010];
vector<int> g[20010];

void dfs(int v){
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if (!used[to]){
			if (col[v] == col[to]){
				d[to] = d[v];
			}
			else{
				d[to] = d[v]+1;
			}
			dfs(to);			
		}
	}
}
int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> col[i];
	}
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	d[0] = 0;
	dfs(0);
	int maxi = 0;
	for (int i = 0; i < n; i++){
		if (d[i] > d[maxi]){
			maxi = i;
		}
		used[i] = false;
	}
	
	d[maxi] = 0;
	dfs(maxi);
	int mm = 0;
	for (int i = 0; i < n; i++){
		mm = max(mm, d[i]);
	}
	cout << (mm+1)/2 << endl;
	return 0;
}