#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF 100000000
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in","r",stdin);
	int n;
	long long w[300100], t[300100], d[300100];
	cin >> n;
	vector<pair<long long, int> > v;
	for (int i = 0; i < n; i++){
		cin >> t[i] >> w[i];
		d[i] = w[i]-t[i];
		if (i > 0) v.push_back(make_pair(t[i], i));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int curr = 0;
	int ans = INF;
	set<pair<long long, int> > s;
	while (true){
		while (v[curr].first > t[0] && curr < v.size()){
			int ins = v[curr].second;
			s.insert(make_pair(d[ins], ins));
			curr++;
		}
		ans = min(ans, (int)s.size()+1);
		if (s.empty()) break;
		int er = s.begin()->second;
		if (d[er]+1 <= t[0]){
			t[0] = t[0]-d[er]-1;
			s.erase(s.begin());
		}
		else{
			break;
		}		
		while (v[curr].first > t[0] && curr < v.size()){
			int ins = v[curr].second;
			if (ins != 0){
				s.insert(make_pair(d[ins], ins));
			}
			curr++;
		}
		//cout << s.size() << endl;
		ans = min(ans, (int)s.size()+1);
	}
	cout << ans << endl;
}