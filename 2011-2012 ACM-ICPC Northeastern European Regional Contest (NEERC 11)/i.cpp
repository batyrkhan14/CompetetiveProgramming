#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int make_query(vector<int> perm){
	for (int i = 0; i < perm.size(); i++){
		cout << perm[i] << " ";
	}
	cout << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}

int main(){
	ios_base::sync_with_stdio();
	//freopen("gcd.in", "r", stdin);
	//freopen("gcd.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; i++){
		ans.push_back(i+1);
	}
	for (int i = 1; i <= n; i++){
		vector<int> mv;
		int mx = 0;
		for (int j = 0; j < n; j++){
			vector<int> temp;
			int k = 0;
			int l = 0;
			while (true){
				if (k >= n) break;
				if (k == j){
					temp.push_back(i);
					k++;
				}
				else{
					if (ans[l] != i){
						temp.push_back(ans[l]);
						k++;
					}
					l++;
				}
			}
			int res = make_query(temp);
			if (res == n){
				return 0;
			}
			if (res > mx){
				mx = res;
				mv = temp;
			}
		}
		ans = mv;
	}
	return 0;	
}