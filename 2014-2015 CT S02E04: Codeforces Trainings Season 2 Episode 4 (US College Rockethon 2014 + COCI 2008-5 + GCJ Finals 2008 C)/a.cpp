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
	ios_base::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	long long mm = 0, mw = 0, sc = 0;
	for (int i = 0; i < n; i++){
		long long m, w, c;
		cin >> m >> w >> c;
		mm += min(m, c);
		mw += min(w, c);
		sc += min(c, m+w);
	}
	cout << min(mm, min(mw, sc/2)) << endl;
	return 0;
}