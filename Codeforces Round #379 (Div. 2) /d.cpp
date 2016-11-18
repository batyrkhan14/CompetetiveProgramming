#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
long long fabs(long long a){
	return (a < 0) ? -a : a;
}
bool vu, vd, hu, hd, mdu, mdd, sdu, sdd;
int main(){
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	int n;
	long long x[500100], y[500100];
	char ch[500100];
	vector<pair<long long, int> > v;
	
	cin >> n;
	long long xx, yy;
	cin >> xx >> yy;
	for (int i = 0; i < n; i++){
		cin >> ch[i] >> x[i] >> y[i];
		v.push_back(make_pair(fabs(x[i]-xx)+fabs(y[i]-yy), i));
	}	
	sort(v.begin(), v.end());
	bool ok = false;
	for (int t = 0; t < n; t++){
		int i = v[t].second;
		if (x[i] == xx){
			if (y[i] < yy){
				if (!vd && (ch[i] == 'R' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					vd = true;
				}
			}
			else if (y[i] > yy){
				if (!vu && (ch[i] == 'R' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					vu = true;
				}
			}
		}
		else if (y[i] == yy){
			if (x[i] < xx){
				if (!hd && (ch[i] == 'R' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					hd = true;
				}
			}
			else if (x[i] > xx){
				if (!hu && (ch[i] == 'R' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					hu = true;
				}
			}
		}
		else if (x[i]+y[i] == xx+yy){
			if (x[i] < xx){
				if (!mdd && (ch[i] == 'B' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					mdd = true;
				}
			}
			else if (x[i] > xx){
				if (!mdu && (ch[i] == 'B' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					mdu = true;
				}
			}
		}
		else if (x[i]-y[i]==xx-yy){
			if (x[i] < xx){
				if (!sdd && (ch[i] == 'B' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					sdd = true;
				}
			}
			else if (x[i] > xx){
				if (!sdu && (ch[i] == 'B' || ch[i] == 'Q')){
					ok = true;
					break;
				}
				else{
					sdu = true;
				}
			}
		}
	}
	if (ok) {
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}