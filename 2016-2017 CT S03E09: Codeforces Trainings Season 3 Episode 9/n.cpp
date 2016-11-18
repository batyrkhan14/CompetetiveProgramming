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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int n;
		long long s[510], m;
		bool used[510];
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			s[i] = (1ll<<x);
			used[i] = false;
		}
		sort(s, s+n);
		reverse(s, s+n);
		int ans = 0;
		while (true){
			ans++;
			long long left = m, poss = 0;
			bool finished = true;
			for (int i = 0; i < n; i++){
				if (!used[i]){
					finished = false;
					if (i > 0) poss = poss*(s[i-1]/s[i])*(s[i-1]/s[i]);
					long long dv = left/s[i];
					poss += dv*dv+2*dv*((m-left)/s[i]);
					left %= s[i];
					if (poss > 0){
						used[i] = true;
						poss--;
					}					
				}
			}
			if (finished) break;
		}
		cout << ans-1 << endl;
	}

	return 0;
}