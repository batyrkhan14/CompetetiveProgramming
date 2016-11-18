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
	//freopen("a.in", "r", stdin);
	int n, k, a[510];
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for (int j = 1; j < n; j++){
		if (a[j] + a[j-1] < k){
			ans += k - a[j] - a[j-1];
			a[j] = k - a[j-1];
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}