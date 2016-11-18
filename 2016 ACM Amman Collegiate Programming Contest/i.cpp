#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int getans(string s, int n){
	//cout << s << " " << n << endl;
	int mn = 0, mx = 0, curr = 0, i = 0, ans = 0;
	int l, r;
	while (i < s.size()){
		if (s[i] == '<'){
			curr--;
			mn = min(mn, curr);
			if (mx - mn + 1 > n){
				l = mn+1;
				r = mx;
				curr++;
				ans++;
				break;
			}
		}
		else{
			curr++;
			mx = max(mx, curr);
			if (mx - mn + 1 > n){
				l = mn;
				r = mx-1;
				curr--;
				ans++;
				break;
			}
		}
		i++;
	}	
	i++;
	//cout << l << " " << r << " " << curr << endl;
	while (i < s.size()){
		if (s[i] == '<'){
			if (curr == l){
				ans++;
			}
			else{
				curr--;
			}
		}
		else{
			if (curr == r){
				ans++;
			}
			else{
				curr++;
			}
		}
		i++;
	}
	//cout << s << " " << n << " " << ans << endl;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int r, c;
		cin >> r >> c;
		string s;
		cin >> s;
		string ud = "", lr = "";
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '<' || s[i] == '>'){
				lr += s[i];
			}
			else{
				if (s[i] == '^') ud += '<';
				else ud += '>';
			}
		}
		//cout << ud << " " << lr << endl;
		cout << getans(ud, r) + getans(lr, c) << endl;

	}
	return 0;
}