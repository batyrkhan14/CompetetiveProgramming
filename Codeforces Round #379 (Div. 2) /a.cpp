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
	ios_base::sync_with_stdio();
	freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, d = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'A'){
			a++;
		}
		else{
			d++;
		}
	}
	if (a > d){
		cout << "Anton" << endl;
	}
	else if (a < d){
		cout << "Danik" << endl;
	}
	else{
		cout << "Friendship" << endl;
	}
	return 0;
}