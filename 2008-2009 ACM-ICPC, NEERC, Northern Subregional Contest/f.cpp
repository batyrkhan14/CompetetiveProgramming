#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int getl(int x){
	int ret = 1;
	while (x%2 == 0){
		ret *= 2;
		x /= 2;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);
	int n;
	long long sum[100010], a[100010];
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		sum[i] = a[i];
		if (i > 1) sum[i] += sum[i-1];

		if (i % 2 == 0){
			int l = getl(i);
			long long s = sum[i-1]-sum[i-l];
			if (s != 0){
				a[i-1] -= s;
				sum[i-1] -= s;
				sum[i] = sum[i-1]+a[i];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}