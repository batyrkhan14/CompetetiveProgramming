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
	freopen("ate.in", "r", stdin);
	freopen("ate.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (i+j == n){
				ans ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}