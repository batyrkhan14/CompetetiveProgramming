#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;


bool isPal(string s){
	int n = s.size();
	for (int i = 0; i < n/2; i++){
		if (s[i] != s[n-i-1]){
			return false;
		}
	}
	return true;
}
int getM(string s){
	int n = s.size();
	for (int l = n; l >= 1; l--){
		for (int j = 0; j+l-1 < n; j++){
			string ns = s.substr(j, l);
			if (isPal(ns)){
				return l;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	int q;
	cin >> q;
	for (int t = 0; t < q; t++){
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 0;
		for (int i = 0; i < n+1; i++){
			for (int ch = 'a'; ch <= 'z'; ch++){
				string ns;
				string temp = ""+ch;
				if (i == 0) ns = temp + s;
				else if (i == n) ns = s + temp;
				else{
					ns = s.substr(0, i) + temp+ s.substr(i);
				} 
				if (getM(ns) >= getM(s)+k) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}