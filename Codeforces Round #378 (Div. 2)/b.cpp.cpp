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
	set<char> vow;
	vow.insert('A');
	vow.insert('E');
	vow.insert('I');
	vow.insert('O');
	vow.insert('U');
	vow.insert('Y');
	string s;
	cin >> s;
	int ans = 1;
	int curr = 0;
	for (int i = 0; i < s.size(); i++){
		if (vow.find(s[i]) != vow.end()){
			curr = 0;
		}
		else{
			curr++;
			ans = max(ans, curr+1);
		}
	}
	cout << ans << endl;
	return 0;
}