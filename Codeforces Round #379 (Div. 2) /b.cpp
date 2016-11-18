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
	freopen("a.in", "r", stdin);
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	long long ans = 0;
	int x = min(k2, min(k5, k6));
	ans += 256*(long long)x;
	k2 -= x;
	if (k2 > 0){
		int y = min(k2, k3);
		ans += 32*(long long)y;
	}
	cout << ans << endl;
	return 0;
}