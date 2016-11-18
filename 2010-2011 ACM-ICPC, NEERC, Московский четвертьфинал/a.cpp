#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int n;
	double x[1010], r, pi = 3.14159265359;
	cin >> n >> r;
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	sort(x, x+n);
	double ans = 0;
	for (int i = 0; i < n; i++){
		if (i == 0){
			ans += pi*r*r;
		}
		else{
			double l = (x[i]-x[i-1])/2.00;
			if (l < r){
				ans += pi*r*r - 2.00*(acos(l/r)*r*r - l*sqrt(r*r-l*l));	
			}
			else{
				ans += pi*r*r;
			}
		}
	}
	cout << fixed << setprecision(10);
	cout << ans << endl;


	return 0;
}