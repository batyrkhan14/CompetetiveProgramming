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
	int n, p[15];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}
	for (int i = 1; i <= 100; i++){
		bool ok = true;
		for (int j = 0; j < n; j++){
			bool can = false;
			for (int k = 0; k <= i; k++){
				if ((2*p[j]-1)*i <= k*200 && (2*p[j]+1)*i > k*200){
					can = true;
					break;
				}
			}
			if (!can) {
				ok = false;
				break;
			}
		}
		if (ok){
			cout << i << endl;
			break;
		}
	}
	return 0;
}