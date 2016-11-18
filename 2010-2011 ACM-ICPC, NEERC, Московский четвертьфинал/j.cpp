#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	double x, y;
	cin >> x >> y;
	long long n = (long long)(x/y);
	cout << n << endl;
	return 0;
}