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
	freopen("addictive.in", "r", stdin);
	freopen("addictive.out", "w", stdout);
	int h, w, c, x, m[12][12];
	cin >> h >> w >> c;
	int j = 0, i = 0, step = 1;
	for (int l = 0; l < c; l++){
		cin >> x;
		for (int k = 0; k < x; k++){
			m[i][j] = l+1;
			j += step;
			if (j >= w || j < 0){
				i++;
				j -= step;
				step = -step;
			}			
		}
	}
	for (int k = 0; k < h; k++){
		for (int l = 0; l < w; l++){
			cout << m[k][l];
		}
		cout << endl;
	}


	return 0;
}