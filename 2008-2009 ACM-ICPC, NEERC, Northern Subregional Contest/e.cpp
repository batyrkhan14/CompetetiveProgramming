#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
bool check(string s1, string s2){
	int nm[500];
	for (char i = 'A'; i <= 'Z'; i++){
		nm[i] = 0;
	}
	for (int i = 0; i < s1.size(); i++){
		nm[s1[i]]++;
		nm[s2[i]]--;
	}
	for (char i = 'A'; i <= 'Z'; i++){
		if (nm[i] != 0){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("enchanted.in", "r", stdin);
	freopen("enchanted.out", "w", stdout);
	string s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;
	int n = s1.size();
	if (check(s1, t1) && check(s2, t2)){
		multiset<pair<char, char> > st;
		for (int i = 0; i < n; i++){
			st.insert(make_pair(s1[i], s2[n-i-1]));
		}
		for (int i = 0; i < n; i++){
			pair<char, char> temp = make_pair(t1[i], t2[n-i-1]);
			if (st.find(temp) != st.end()){
				st.erase(st.equal_range(temp).first);
			}
		}
		if (st.size() == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}