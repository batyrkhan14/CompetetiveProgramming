#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;
bool ispal(string s){
	int n = (int)s.size();
	for (int i = 0; 2*i <= n; i++){
		if (s[i] != s[n-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio();
	//freopen("a.in", "r", stdin);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	set<string> v;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			string ss = s.substr(i, j-i+1);
			if (!ispal(ss))
				v.insert(ss);
			//cout << ss << endl;
		}
	}
	//v.insert("");
	set<string>::iterator it;
	vector<string> vv;
	for (it = v.begin(); it != v.end(); it++){
		vv.push_back(*it);
	}
	k--;
	if (k >= vv.size()){
		cout << -1 << endl;
	}
	else{
		cout << vv[k] << endl;
	}
	return 0;
}