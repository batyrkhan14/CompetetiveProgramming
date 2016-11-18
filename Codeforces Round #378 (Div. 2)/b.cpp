#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int absolute(int a){
	if (a >= 0) return a;
	return -a;
}
int main(){
	ios_base::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	int n, l[100100], r[100100], L = 0, R = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		L += l[i];
		R += r[i];
	}
	int ans = absolute(L-R);
	int idx = 0;
	for (int i = 0; i < n; i++){
		if (ans < absolute(L-R-2*l[i]+2*r[i])){
			ans = absolute(L-R-2*l[i]+2*r[i]);
			idx = i+1;
		}
	}
	cout << idx << endl;
	return 0;
}