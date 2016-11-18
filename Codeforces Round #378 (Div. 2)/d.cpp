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
	freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	set<pair<pair<int, int>, pair<int, int> > > v;
	for (int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.insert(make_pair(make_pair(a,b), make_pair(c, i)));
		v.insert(make_pair(make_pair(b,a), make_pair(c, i)));
		v.insert(make_pair(make_pair(b,c), make_pair(a, i)));
		v.insert(make_pair(make_pair(c,b), make_pair(a, i)));
		v.insert(make_pair(make_pair(a,c), make_pair(b, i)));
		v.insert(make_pair(make_pair(c,a), make_pair(b, i)));
	}
	set<pair<pair<int, int>, pair<int, int> > >::iterator it;
	multiset<pair<int, int> >::iterator mit;
	//pair<int, int> 
	long long ans = 0;
	int ii, jj, cnt; 
	for (it = v.begin(); it != v.end();){
		pair<int, int> p1= it->first;
		pair<int, int> p2 = it->second;
		multiset<pair<int, int> > ms;
		while (it != v.end() && p1 == it->first){
			ms.insert(make_pair(-it->second.first, it->second.second));
			//cout << it->first.first << " " << it->first.second << " " << it->second.first << " " << it->second.second << endl;
			it++;
		}

		if (ms.size() > 1){
			mit = ms.begin();
			pair<int, int> ff = *mit;
			mit++;
			pair<int, int> ss = *mit;
			long long c = min((long long)(-ff.first) + (long long)(-ss.first), min((long long)p1.first, (long long)p1.second));
			if (ans < c){
				ans = c;
				ii = ff.second;
				jj = ss.second;
				cnt = 2;
			}
		}
		else{
			//cout << "one" << endl;
			long long c = min((long long)p1.first, min((long long)p1.second, (long long)p2.first));
			if (ans < c){
				cnt = 1;
				ans = c;
				ii = p2.second;
			}
		}
		//cout << cnt << " " << ans << endl;
		//cout << ii << " " << jj << endl;
		//cout << endl;
	}
	cout << cnt << endl << ii+1;
	if (cnt == 2) cout << " " << jj+1;
	cout << endl;
	return 0;
}