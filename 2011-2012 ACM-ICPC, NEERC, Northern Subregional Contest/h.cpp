#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

int cnt[50010][10];
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("high.in", "r", stdin);
	freopen("high.out", "w", stdout);
	int n;
	cin >> n;
	string word[50010];
	for (int i = 0; i < n; i++){
		cin >> word[i];
	}
	for (int mask = 0; mask < 32; mask++){
		map<string, int> m;
		string temp[50010];
		int nm = 0;
		int x = mask;
		while (x > 0){
			if (x%2 == 1) nm++;
			x /= 2;
		}
		for (int i = 0; i < n; i++){
			temp[i] = "";
			for (int j = 0; j < 5; j++){
				if ((1<<(4-j))&mask){
					temp[i] += word[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++){
			m[temp[i]]++;
		}
		for (int i = 0; i < n; i++){
			cnt[i][nm] += m[temp[i]]-1;
		}
	}
	for (int i = 0; i < n; i++){
		cnt[i][4] -= 5*cnt[i][5];
		cnt[i][3] -= 4*cnt[i][4]+10*cnt[i][5];
		cnt[i][2] -= 3*cnt[i][3]+6*cnt[i][4]+10*cnt[i][5];
		cnt[i][1] -= 2*cnt[i][2]+3*cnt[i][3]+4*cnt[i][4]+5*cnt[i][5];
		cnt[i][0] -= cnt[i][1]+cnt[i][2]+cnt[i][3]+cnt[i][4]+cnt[i][5];
		//cout << word[i] << " " << cnt[i][0] << endl;
	}
	for (int i = 5; i >= 0; i--){
		long long ans = 0;
		for (int j = 0; j < n; j++){
			ans += (long long)cnt[j][i];
		}
		cout << ans/2 << " ";
	}
	cout << endl;
	return 0;
}