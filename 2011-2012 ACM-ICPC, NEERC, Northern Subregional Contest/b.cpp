#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("black.in", "r", stdin);
	//freopen("black.out", "w", stdout);
	int m, n, s, k;
	cin >> m >> n >> s >> k;
	string row;
	cin >> row;
	int pieces = 0, cells = 0, curr = 0; 
	for (int i = 0; ; i++){
		if ((i >= n || row[i] == '.') && curr > 0){
			pieces++;
			curr = 0;
		}
		else if (i < n && row[i] == '*'){
			curr++;
			cells++;
		}
		if (i >= n) break;
	}
	if (cells > 0){
		if (pieces != 1 || cells != s || s > m){
			cout << "Impossible" << endl;
		}
		else if (s == m || s == 1 || k == 1 || k == m){
			cout << "Unique" << endl;
		}
		else{
			cout << "Ambiguous" << endl;
		}		
	}
	else{
		if (s > k-1 && s > m-k){
			cout << "Impossible" << endl;
		}
		else if (s < n || (s < k-1 || s < m-k) || (s == k-1 && s == m-k)){
			cout << "Ambiguous" << endl;
		}
		else{
			cout << "Unique" << endl;
		}
	}
	return 0;
}