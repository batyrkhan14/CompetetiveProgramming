#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
long long getn(string s){
	long long ret = 0;
	for (int i = 0; i < s.size(); i++){
		ret = ret*10ll + (long long)(s[i]-'0');
	}
	return ret;
}

long long parse(string ip){
	int i = 0;
	long long ret = 0;
	string curr = "";
	while (true){
		if (i >= ip.size() || ip[i] == '.'){
			ret = ret*256ll+getn(curr);
			curr = "";
			if (i >= ip.size()) break;			
		}
		else if (ip[i] >= '0' && ip[i] <= '9'){
			curr += ip[i];
		}
		i++;
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("access.in", "r", stdin);
	//freopen("access.out", "w", stdout);
	int n;
	long long l[100010], r[100010];
	char type[100010];
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++){
		getline(cin, s);
		if (s[0] == 'a'){
			s = s.substr(11);
			type[i] = 'A';
		}
		else{
			s = s.substr(10);
			type[i] = 'D';
		}
		int pos = -1;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == '/'){
				pos = j;
				break;
			}
		}
		if (pos == -1){
			l[i] = parse(s);
			r[i] = l[i];
		}
		else{
			l[i] = parse(s.substr(0, pos));
			r[i] = l[i]+(1ll<<getn(s.substr(pos+1)))-1ll;
		}
		//cout << l[i] << " " << r[i] << " " << type[i] << endl;
	}
	int m;
	cin >> m;
	multiset<pair<long long, int> > stp;
	char ans[100010];
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		stp.insert(make_pair(parse(s), i));
		ans[i] = 'A';
	}

	multiset<pair<long long, int> >::iterator it;
	for (int i = 0; i < n; i++){
		//cout << stp.size() << endl;
		vector<multiset<pair<long long, int> >::iterator> its;
		for (it = stp.lower_bound(make_pair(l[i], 0)); it != stp.upper_bound(make_pair(r[i], m-1)); it++){
			pair<long long, int> temp = *it;
			//cout << temp.first << " " << temp.second << endl;
			ans[temp.second] = type[i];
			its.push_back(it);
		}
		for (int j = 0; j < its.size(); j++){
			stp.erase(its[j]);
		}
	}
	for (int i = 0; i < m; i++){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}