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
	freopen("ascii.in", "r", stdin);
	freopen("ascii.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	double area = 0;
	for (int i = 0; i < h; i++){
		string s;
		cin >> s;
		bool in = false;
		for (int i = 0; i < w; i++){
			if (s[i] == '\\' || s[i] == '/'){
				area += 0.5;
				in = !in;
			}
			else{
				if (in) area += 1.0;
			}
		}
	}
	cout << area << endl;
	return 0;
}