#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	set<int> u, d;
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		if (s[i] == 'U'){
			u.insert(i);
		}
		else{
			d.insert(i);
		}
	}
	for (int i = 0; i < n; i++){
		if (s[i] == 'D'){
			
		}
	}

	return 0;
}