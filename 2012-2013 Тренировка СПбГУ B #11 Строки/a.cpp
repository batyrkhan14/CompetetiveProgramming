#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
int p[100010], cnt[150], c[100010];
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	string s;
	getline(cin, s);
	int n = s.size();
	for (int i = 0; i < n; i++){
		cnt[s[i]]++;
	}
	for (int i = 1; i < 128; i++){
		cnt[i] += cnt[i-1];
	}
	for (int i = 0; i < n; i++){
		cnt[s[i]]--;
		p[cnt[s[i]]] = i;
	}
	c[p[0]] = 0;
	int classes = 0;
	for (int i = 1; i < n; i++){
		if (s[p[i]] != s[p[i-1]]){
			classes++;
		}
		c[p[i]] = classes;
	}
	for (int i = 0; i < n; i++){
		cout << p[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << c[i] << " ";
	}
	cout << endl;

	return 0;
}