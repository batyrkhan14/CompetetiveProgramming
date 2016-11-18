#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF (long long)2000000000 * (long long)2000000000
using namespace std;



int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	int n, m, a[200100], b[200100];
	cin >> n >> m;
	vector<pair<int, int> > p;
	bool used[200100];
	for (int i = 0; i < n; i++){
		int s;
		cin >> s;
		p.push_back(make_pair(s, i));
		b[i] = -1;
	}
	vector<pair<int, pair<int, int> > > v;
	for (int j = 0; j < m; j++){
		a[j] = 0;
		used[j] = false;
		int s;
		cin >> s;
		int lvl = 0;
		while (true){
			v.push_back(make_pair(-s, make_pair(lvl, j)));
			lvl++;
			if (s == 1) break;
			s = (s+1)/2;
		}
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	/*for (int i = 0; i < p.size(); i++){
		cout << "p " << p[i].first << " " << p[i].second << endl; 
	}*/
	sort(v.begin(), v.end());
	/*for (int i = 0; i < v.size(); i++){
		cout << "v " << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
	}*/
	int c = 0, u = 0; 
	for (int i = 0, j = 0; i < p.size() && j < v.size();){
		if (used[v[j].second.second]){
			j++;
		}
		else if (p[i].first > -v[j].first){
			i++;
		}
		else if (p[i].first < -v[j].first){
			j++;
		}
		else if (p[i].first == -v[j].first){
			c++;
			a[v[j].second.second] = v[j].second.first;
			u += a[v[j].second.second];
			b[p[i].second] = v[j].second.second;
			used[v[j].second.second] = true;
			i++;
			j++;
		}
	}
	cout << c << " " << u << endl;
	for (int i = 0; i < m; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << b[i]+1 << " ";
	}
	cout << endl;
	return 0;
}