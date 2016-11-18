

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
int n, xa[110], ya[110], xp[110], yp[110], ans[110];
bool used[110];
double dist(int i, int j){
	return sqrt((xa[i]-xp[j])*(xa[i]-xp[j])*1.00+(ya[i]-yp[j])*(ya[i]-yp[j])*1.00);
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	//freopen("ants.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> xa[i] >> ya[i];
	}
	for (int i = 0; i < n; i++){
		cin >> xp[i] >> yp[i];
	}
	for (int i = 0; i < n; i++){
		int md = 1000000000;
		int mj = -1;
		for (int j = 0; j < n; j++){
			if (!used[j]){
				int dt = dist(i, j);
				if (dt < md){
					md = dt;
					mj = j;
				}
			}
		}
		ans[i] = mj;
		used[mj] = true;
	}
	for (int t = 0; t < 1000; t++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (dist(i, ans[i]) + dist(j, ans[j]) > dist(i, ans[j]) + dist(j, ans[i])){
					swap(ans[i], ans[j]);
				}
			}
		}		
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] + 1 << endl;
	}
	return 0;
}