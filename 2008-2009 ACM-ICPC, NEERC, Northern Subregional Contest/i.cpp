#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	freopen("important.in", "r", stdin);
	freopen("important.out", "w", stdout);
	int n;
	cin >> n;
	string temp;
	getline(cin, temp);
	vector<string> names;
	for (int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		int j = 0;
		string name = "";
		while (s[j] >= 'A' && s[j] <= 'Z'){
			name += s[j];
			j++;
		}
		names.push_back(name);
	}
	cout << "Yes" << endl;
	cout << names[0] << " | ~" << names[0];
	for (int i = 1; i < names.size(); i++){
		cout << " | " << names[i]; 
	} 
	cout << endl;
	return 0;
}