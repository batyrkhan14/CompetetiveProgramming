#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;
long long getans(int l, int i, int r){
	long long x = r-i;
	long long y = i-l;
	return (x*(x+1)/2)*(y+1)+(y*(y+1)/2)*(x+1)+(x+1)*(y+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int n, k, a[100100], l[100100], r[100100];
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	stack<pair<int, int> > s;
	for (int i = 0; i < n; i++){
		while (!s.empty() && s.top().first >= a[i]){
			s.pop();
		}
		if (s.empty()){
			l[i] = 0;
		}
		else{
			l[i] = s.top().second+1;
		}
		s.push(make_pair(a[i], i));
	}
	while (!s.empty()){
		s.pop();
	}
	for (int i = n-1; i >= 0; i--){
		while (!s.empty() && s.top().first >= a[i]){
			s.pop();
		}
		if (s.empty()){
			r[i] = n-1;
		}
		else{
			r[i] = s.top().second-1;
		}
		s.push(make_pair(a[i], i));
	}
	/*for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << l[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << r[i] << " ";
	}
	cout << endl;*/
	vector<pair<long long, long long> > v;
	for (int i = 0; i < n; i++){
		v.push_back(make_pair(getans(l[i], i, r[i]), (long long)a[i]));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < k; i++){
		v[i].second++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		ans += v[i].first*v[i].second;
	}
	cout << ans << endl;
	return 0;
}