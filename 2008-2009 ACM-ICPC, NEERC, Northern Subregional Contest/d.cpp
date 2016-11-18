#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int n, r, c;
char ch[110][110];
void go(int x, int y){
	if (n > 0 && ch[x][y] == '.'){
		n--;
		ch[x][y] = '#';
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("class.in", "r", stdin);
	freopen("class.out", "w", stdout);
	cin >> n >> r >> c;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			ch[i][j] = '.';
		}
	}
	
	for (int i = 0; i < min(r, c); i++){
		if (r < c){
			go(0, i);
			go(i, 0);
		}
		else{
			go(i, 0);
			go(0, i);
		}

	}
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			go(i, j);
		}
	}

	int rf = 0, cf = 0;
	for (int i = 0; i < r; i++){
		int temp = 0;
		for (int j = 0; j < c; j++){
			if (ch[i][j] == '#') temp++;
		}
		rf = max(rf, temp);
	}
	for (int j = 0; j < c; j++){
		int temp = 0;
		for (int i = 0; i < r; i++){
			if (ch[i][j] == '#') temp++;
		}
		cf = max(cf, temp);
	}
	cout << min(rf, cf) << endl;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout << ch[i][j];
		}
		cout << endl;
	}
	return 0;
}