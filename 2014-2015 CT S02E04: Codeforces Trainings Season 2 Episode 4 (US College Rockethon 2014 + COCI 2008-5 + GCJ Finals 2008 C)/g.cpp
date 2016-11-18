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
	int n, s;
	cin >> n >> s;
	int sm = n*(n-1)/2;
	sm -= s;
	if (sm%2 != 0){
		cout << -1 << endl;
		return 0;
	}
	else{
		sm /= 2;
		set<int> ans;
		for (int i = n-1; i >= 1; i--){
			if (sm >= i){
				sm -= i;
				ans.insert(i);
			}
		}
		if (sm > 0){
			cout << -1 << endl;
			return 0;
		}
		int curr = 0;
		cout << curr << " ";
		for (int i = 1; i < n; i++){
			if (ans.find(n-i) != ans.end()){
				curr--;
			}
			else{
				curr++;
			}
			cout << curr << " ";
		}
		cout << endl;
	}
	return 0;
}