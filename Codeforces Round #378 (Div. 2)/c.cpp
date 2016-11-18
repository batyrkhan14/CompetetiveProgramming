#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool check(vector<int> v){
	if (v.size() == 1) return true;
	set<int> s;
	for (int i = 0; i < v.size(); i++){
		s.insert(v[i]);
	}
	return (s.size() != 1);
}
void printans(vector<int> v, int x){
	if (v.size() == 1) return;
	int mx = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i] > mx){
			mx = v[i];
		}
	}
	for (int i = 0; i < v.size(); i++){
		if (v[i] == mx){
			if (i-1 >= 0 && v[i-1] < mx){
				cout << i+1+x << " L" << endl;
				vector<int> temp;
				for (int j = 0; j < v.size(); j++){
					if (j != i-1 && j != i){
						temp.push_back(v[j]);
					}
					else if (j == i-1){
						temp.push_back(v[i-1]+v[i]);
					}
				}
				printans(temp, x);
				return;
			}
			if (i+1 < v.size() && v[i+1] < mx){
				cout << i+1+x << " R" << endl;
				vector<int> temp;
				for (int j = 0; j < v.size(); j++){
					if (j != i+1 && j != i){
						temp.push_back(v[j]);
					}
					else if (j == i){
						temp.push_back(v[i+1]+v[i]);
					}
				}
				printans(temp, x);
				return;
			}

		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int n, k, a[510], b[510];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> b[i];
	}
	vector<int> ids[510];
	bool poss = true;
	int j = 0, curr = 0;
	for (int i = 0; i < n; i++){
		curr += a[i];
		ids[j].push_back(a[i]);
		if (j >= k){
			poss = false;
			break;
		}
		else if (b[j] == curr){
			j++;
			curr = 0;
		}
		else if (b[j] < curr){
			poss = false;
			break;
		}
	}
	if (j < k){
		poss = false;
	}
	if (poss){
		for (int i = 0; i < k; i++){
			if (!check(ids[i])){
				poss = false;
				break;
			}
		}		
	}
	if (!poss){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for (int i = 0; i < k; i++){
			printans(ids[i], i);
		}
	}
	return 0;
}