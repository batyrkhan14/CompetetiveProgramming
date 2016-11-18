

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	vector<pair<int, int> mov;
	for (int i = 0; i < 6; i++){
		string mv;
		cin >> mv;
		mov.push_back(make_pair(mv[0]-'A', mv[1]-'A'));
	}
	
	return 0;
}