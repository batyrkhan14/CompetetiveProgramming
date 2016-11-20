#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF 1000000000

using namespace std;
int n, s, col[200100], z[200100], sm[200100];
int main(){
	ios_base::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n >> s;
	int first = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (i == s-1 && x != 0){
			first = 1;
			x = 0;
		}
		col[x]++;
	}
	for (int i = 0; i < n; i++){
		if (i == 0){
			z[i] = 0;
		}
		else{
			z[i] = z[i-1] + ((col[i] == 0) ? 1 : 0);
		}
	}
	for (int i = n; i >= 0; i--){
		if (i == n) sm[i] = 0;
		else{
			sm[i] = sm[i+1] + col[i];
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++){
		int tans = col[0]-1+sm[i+1];
		tans = max(tans, z[i]);
		ans = min(ans, tans);
	}
	cout << ans+first << endl;
	return 0;
}