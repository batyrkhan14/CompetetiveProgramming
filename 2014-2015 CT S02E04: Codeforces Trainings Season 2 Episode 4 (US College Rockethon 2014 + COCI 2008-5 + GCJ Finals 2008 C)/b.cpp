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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> v;
	for (int i = 0; i < n; i++){
		if (s[i] != s[n-i-1]){
			v.push_back(i);
		}
	}
	if (v.size() == 0){
		cout << 1 << endl << s << endl;
	}
	else if (v.size() == 2 && n%2 == 1){
		int mid = n/2;
		if (s[v[0]] == s[mid] || s[v[1]] == s[mid]){
			cout << 1 << endl;
			if (s[v[0]] == s[mid]){
				swap(s[mid], s[v[1]]);
			}
			else{
				swap(s[mid], s[v[0]]);
			}
			cout << s << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	else if (v.size() == 4){
		set<char> st;
		for (int i = 0; i < v.size(); i++){
			st.insert(s[v[i]]);
		} 
		if (st.size() != 2){
			cout << 0 << endl;
		}
		else{
			cout << 2 << endl;
			set<char>::iterator it;
			string ss = s;
			it = st.begin();
			char a = *it;
			char b = *(++it);
			if (a > b) swap(a, b);
			ss[v[0]] = a;
			ss[v[1]] = b;
			ss[v[2]] = b;
			ss[v[3]] = a;
			cout << ss << endl;
			ss[v[0]] = b;
			ss[v[1]] = a;
			ss[v[2]] = a;
			ss[v[3]] = b;
			cout << ss << endl;

		}
	}
	else{
		cout << 0 << endl;
	}
	return 0;
}