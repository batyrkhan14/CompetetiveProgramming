#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
string get (int i, int j){
	cout << i+1 << " " << j+1 << endl;
	cout.flush();
	string s;
	cin >> s;
	return s;
}
int main(){
	int n, m;
	cin >> n >> m;
	int currx = 0, curry = 0, mxx = 0, mnx = 0, mxy = 0, mny = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (i + mxx < n && i + mnx >= 0 && j + mxy < m && j + mny >= 0){
				//cout << i << " " << j << " " << currx << " " << curry << endl;
				string s = get(i+currx, j+curry);
				if (s == "DETECTED"){
					fclose(stdout);
					return 0;
				}
				else if (s == "L"){
					//cout << "here" << endl;
					curry--;
					mny = min(mny, curry);
				}
				else if (s == "R"){
					curry++;
					mxy = max(mxy, curry);
				}
				else if (s == "U"){
					currx--;
					mnx = min(mnx, currx);
				}
				else if (s == "D"){
					currx++;
					mxx = max(mxx, currx);
				}
			}
		}
	}
	return 0;
}