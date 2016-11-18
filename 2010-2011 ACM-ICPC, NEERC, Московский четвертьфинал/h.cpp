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
	//freopen("a.in", "r", stdin);
	//freopen("ate.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 1) cout << "YES" << endl;
	else if (n <= 4) cout << "NO" << endl;
	else{
		bool ok = false;
		for (int i = 2; i*i <= n; i++){
			if (n%i == 0){
				ok = true;
				break;
			}
		}		
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}