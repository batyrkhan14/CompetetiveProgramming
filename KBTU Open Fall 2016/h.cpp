#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#define INF (long long)1000000000*(long long)1000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	int n, m;
	long long g[610][610], d[610][610];
	cin >> n >> m;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++){
			g[i][j] = INF;
			if (i == 0) g[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++){
		int u, v;
		long long c;
		cin >> u >> v >> c;
		g[u][v] = min(g[u][v], c);
	}
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++){
			d[i][j] = g[i][j];
			if (i == j) d[i][j] = 0;
		}
	}
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++){
			for (int k = 0; k <= n; k++){
				if (d[j][i] != INF && d[i][k] != INF){
					d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
				}
			}
		}
	}

	long long dp[5][6][610][610];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j <= n; j++){
			for (int k = 0; k <= n; k++){
				dp[0][i][j][k] = INF;
				dp[1][i][j][k] = INF;
			}
		}
	}
	dp[0][0][0][0] = 0;
	dp[0][1][0][0] = 0;
	dp[0][2][0][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 3; j++){
			int a = (j+1)%3;
			int b = (j+2)%3;
			for (int k = 0; k <= i-1; k++){
				for (int l = 0; l <= i-1; l++){
					if (d[i-1][i] < INF){
						dp[1][j][k][l] = dp[0][j][k][l]+d[i-1][i];	
					}
					else{
						dp[1][j][k][l] = INF;
					}
				}
			}
			for (int k = 0; k <= i-1; k++){
				for (int l = 0; l <= i-1; l++){
					if (d[l][i] != INF){
						dp[1][j][i-1][k] = min(dp[1][j][i-1][k], dp[0][a][k][l] + d[l][i]);
						dp[1][j][k][i-1] = min(dp[1][j][k][i-1], dp[0][b][l][k] + d[l][i]);											
					}
				}
			}
		}
		for (int t = 0; t < 3; t++){
			for (int j = 0; j <= n; j++){
				for (int k = 0; k <= n; k++){
					dp[0][t][j][k] = dp[1][t][j][k];
					dp[1][t][j][k] = INF;
				}
			}
		}
	}
	long long ans = INF;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j <= n; j++){
			for (int k = 0; k <= n; k++){
				//cout << i << " " << j << " " << k << " " << dp[i][j][k][0] << endl;
				ans = min(ans, dp[0][i][j][k]);
			}
		}
	}
	if (ans >= INF){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
	return 0;
}