#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
char gender[200100];
int parent[200100], seq[200100];

set<int> alive;
int main(){
	ios_base::sync_with_stdio();
	freopen("eve.in", "r", stdin);
	freopen("eve.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> gender[i];
		parent[i] = i;
		alive.insert(i);
		seq[i] = -1;
	}
	int m, ids = n;
	cin >> m;
	for (int i = 0; i < m; i++){
		int f, s;
		char g;
		cin >> f;
		if (f < 0){
			alive.erase(-f);
		}
		else{
			cin >> s >> g;
			int nw = ++ids;
			parent[nw] = parent[s];
			gender[nw] = g;
			alive.insert(nw);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++){
		int id, sq;
		cin >> id >> sq;
		seq[parent[id]] = sq;
	}
	set<int>::iterator it;
	set<int> parents;
	set<int> seqs;
	bool unk = false;
	for (it = alive.begin(); it != alive.end(); it++){
		int id = *it;
		parents.insert(parent[id]);
		if (seq[parent[id]] == -1) unk = true;
		else{
			seqs.insert(seq[parent[id]]);
		}
	}
	if (parents.size() <= 1 || (unk == false && seqs.size() <= 1)){
		cout << "YES" << endl;
	}
	else if (unk == true && seqs.size() <= 1){
		cout << "POSSIBLY" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}