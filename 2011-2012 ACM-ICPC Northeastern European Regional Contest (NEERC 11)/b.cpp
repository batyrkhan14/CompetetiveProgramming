#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
string get(int x, int n){
	string s = "";
	for (int i = 0; i < n; i++){
		s = (char)('0' + x%2) + s;
		x /= 2;
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio();
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int m;
	cin >> m;
	int n = 0;
	int p = 1;
	while (p < m) n++, p *= 2;
	int x = p - m;
	for (int i = 0; i < x; i++){
		cout << get(i, n-1) << endl;
	}
	for (int i = p-m+x; i < p; i++){
		cout << get(i, n) << endl;
	}
	return 0;
}