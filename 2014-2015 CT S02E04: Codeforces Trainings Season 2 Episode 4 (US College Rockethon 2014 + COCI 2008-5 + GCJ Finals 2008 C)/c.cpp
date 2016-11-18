#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF 2000000000
using namespace std;
int x[] = {0, 1, 0, -1};
int y[] = {-1, 0, 1, 0};
int n, N, a[80][80];

pair<int, int> isPoss(int M){
	int d[80][80], df[80][80];
	bool used[80][80];
	pair<int, int> p[80][80];
	set<pair<pair<int, int>, pair<int, int> > > s;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			used[i][j] = false;
			d[i][j] = INF;
			df[i][j] = INF;
			if (i == 0 || i == N-1 || j == 0 || j == N-1){
				d[i][j] = 0;
				df[i][j] = 0;
				p[i][j] = make_pair(i, j);
				s.insert(make_pair(make_pair(0, 0), make_pair(i, j)));
			}
		}
	}

	for (int i = 0; i < N*N; i++){
		if (s.empty()) break;
		int fi = s.begin()->second.first;
		int fj = s.begin()->second.second;
		s.erase(s.begin());
		for (int j = 0; j < 4; j++){
			int ti = fi+x[j];
			int tj = fj+y[j];
			if (ti >= 0 && ti < N && tj >= 0 && tj < N && a[ti][tj]-a[fi][fj] >= df[fi][fj]){
				if (d[fi][fj] < M && df[ti][tj] > a[ti][tj]-a[fi][fj]){
					s.erase(make_pair(make_pair(d[ti][tj], df[ti][tj]), make_pair(ti, tj)));
					d[ti][tj] = d[fi][fj]+1;
					df[ti][tj] = a[ti][tj]-a[fi][fj];
					p[ti][tj] = p[fi][fj];
					s.insert(make_pair(make_pair(d[ti][tj], df[ti][tj]), make_pair(ti, tj)));
				}
			}
		}
	}
	if (d[n][n] == INF) return make_pair(-1, -1);
	queue<pair<int, int> > q;
	q.push(make_pair(n, n));
	while (!q.empty()){
		int fi = q.front().first;
		int fj = q.front().second;
		q.pop();
		used[fi][fj] = true;
		for (int i = 0; i < 4; i++){
			int ti = fi+x[i];
			int tj = fj+y[i];
			if (ti >= 0 && ti < N && tj >= 0 && tj < N && (fi != 0 && fi != N-1 && fj != 0 && fj != N-1)){
				if (!used[ti][tj] && df[ti][tj] <= a[fi][fj]-a[ti][tj]){
					q.push(make_pair(ti, tj));
				}
			}
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == 0 || j == 0 || i == N-1 || j == N-1){
				if (used[i][j]) return make_pair(i, j);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	N = 2*n+1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}
	int l = 1;
	int r = N*N;
	while (l < r){
		int m = (l+r)/2;
		pair<int, int> temp = isPoss(m);
		if (temp.first == -1){
			l = m+1;
		}
		else{
			r = m;
		}
	}
	if (l == N*N){
		cout << "IMPOSSIBLE";
	}
	else{
		cout << l << endl;
		pair<int, int> ans = isPoss(l);
		cout << ans.first+1 << " " << ans.second+1 << endl;
	}
/*	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (d[i][j] == INF) cout << -1 << " " ;
			else cout << df[i][j] << " ";
		}
		cout << endl;
	}
	if (d[n][n] == INF){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << d[n][n] << endl << p[n][n].first << " " << p[n][n].second << endl;
	}*/
	return 0;
}