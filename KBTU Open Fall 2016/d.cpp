#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio();
	//freopen("a.in", "r", stdin);
	int n, k, x[50], y[50];
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	int s = 0;
	for (int i = 0; i < n; i++){
		int next = (i+1)%n;
		s += (x[i]*y[next] - y[i]*x[next]);
	}
	cout << fixed << setprecision(10);
	cout << (double)((s > 0) ? s : -s)/2.00/(double)(k+1) << endl;
	return 0;
}