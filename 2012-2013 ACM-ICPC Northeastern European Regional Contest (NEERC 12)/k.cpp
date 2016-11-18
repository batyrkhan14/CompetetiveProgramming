#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
bool check(long long x, long long k, long long n){
	long long res = 0;
	vector<long long> v;
	while (x > 0){
		v.push_back(x%k);
		x /= k;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		res = res*k;
		if (res > n) return false;
		res = res*k;
		if (res > n) return false;
		res = res + v[i];
		if (res > n) return false;
	}
	return (res <= n);
}
int main(){
	ios_base::sync_with_stdio();
	freopen("great.in", "r", stdin);
	freopen("great.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	long long l = 0;
	long long r = n;
	while (l < r){
		long long m = (l+r+1)/2;
		if (check(m, k, n)){
			l = m;
		}
		else{
			r = m-1;
		}
	}
	cout << l+1 << endl;
	return 0;
}