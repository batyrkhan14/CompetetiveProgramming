#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <bitset>
#include <map>

using namespace std;
int ind(char a){
	if (a >= 'a' && a <= 'z') return a-'a';
	return a-'A' + 'z'-'a'+1;
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("hyperdrome.in", "r", stdin);
	freopen("hyperdrome.out", "w", stdout);
	int n;
	string s;
	cin >> n >> s;

	vector<bool> v(52);
	map<long long, int> cnt;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		v[ind(s[i])] = v[ind(s[i])]^1;
		int count = 0;
		long long num = 0;
		for (int j = 0; j < v.size(); j++){
			count += v[j];
			num = num*2+v[j];
		}
		if (count <= 1){
			ans += 1ll;
		}
		if (cnt.find(num) != cnt.end()){
			ans += (long long)cnt[num];
		}
		long long temp = 1;
		for (int j = 0; j < 52; j++){
			num ^= temp;
			if (cnt.find(num) != cnt.end()){
				ans += (long long)cnt[num];		
			}
			num ^= temp;
			temp *= 2;
		}
		cnt[num]++;
	}
	cout << ans << endl;
	return 0;
}