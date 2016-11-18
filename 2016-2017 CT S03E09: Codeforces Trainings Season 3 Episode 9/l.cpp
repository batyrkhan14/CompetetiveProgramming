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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		int n, a[30][30];
		string dir;
		cin >> n >> dir;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (dir == "left"){
					cin >> a[i][j];
				}
				else if (dir == "right"){
					cin >> a[i][n-j-1];
				}
				else if (dir == "up"){
					cin >> a[j][i];
				}
				else if (dir == "down"){
					cin >> a[j][n-i-1];
				}
			}
		}
		for (int i = 0; i < n; i++){
			vector<int> v;
			bool can = false;
			for (int j = 0; j < n; j++){
				if (a[i][j] != 0){
					if (!can){
						v.push_back(a[i][j]);
						can = true;
					}
					else{
						if (a[i][j] == v[v.size()-1]){
							v[v.size()-1] += a[i][j];
							can = false;
						}
						else{
							v.push_back(a[i][j]);
						}
					}
				}
			}
			for (int j = 0; j < n; j++){
				if (j < v.size()){
					a[i][j] = v[j];
				}
				else{
					a[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (dir == "left"){
					cout << a[i][j] << " ";
				}
				else if (dir == "right"){
					cout << a[i][n-j-1] << " ";
				}
				else if (dir == "up"){
					cout << a[j][i] << " ";
				}
				else if (dir == "down"){
					cout << a[j][n-i-1] << " ";
				}				
			}
			cout << endl;
		}

	}
	return 0;
}